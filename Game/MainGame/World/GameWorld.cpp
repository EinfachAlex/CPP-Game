#include "GameWorld.h"
#include <iostream>

void GameWorld::loadWorld(int worldID)
{
	this->worldFile.open(std::to_string(worldID) + ".json");

	if (this->worldFile.is_open()) {
		//Convert contents of file to string and create json object
		std::string fileContent((std::istreambuf_iterator<char>(this->worldFile)), std::istreambuf_iterator<char>());
		nlohmann::json jsonWorld = nlohmann::json::parse(fileContent);

		//Iterate over JSON, (Y)
		for (size_t i = 0; i <= (jsonWorld.size() - 1); i++)
		{
			try
			{
				nlohmann::json jsonWorldX = jsonWorld[std::to_string(i + 1)];

				//Iterate over JSON, (X)
				for (size_t j = 0; j <= (jsonWorldX.size() - 1); j++)
				{
					std::cout << "X: " << i << jsonWorldX[std::to_string(i)] << '\n';

					WorldBlock* worldBlock = new WorldBlock(i + j + i + j);

					this->blocks[i][j] = worldBlock;
				}
			}
			catch (const std::exception& exception)
			{
				std::cout << exception.what();
			}
		}
	}
}
