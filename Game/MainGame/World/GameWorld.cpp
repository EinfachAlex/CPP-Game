#include "GameWorld.h"
#include <iostream>

void GameWorld::loadWorld(int worldID)
{
	this->worldFile.open(std::to_string(worldID) + ".json");

	if (this->worldFile.is_open()) {
		std::string fileContent((std::istreambuf_iterator<char>(this->worldFile)), std::istreambuf_iterator<char>());

		nlohmann::json jsonWorld = nlohmann::json::parse(fileContent);

		for (size_t i = 1; i <= jsonWorld.size(); i++)
		{
			try
			{
				std::string x = std::to_string(i);
				nlohmann::json jsonWorldX = jsonWorld[x];
				std::cout << "Y: " << i << '\n';
				
				for (size_t i = 1; i <= jsonWorldX.size(); i++)
				{
					std::cout << "X: " << i << jsonWorldX[std::to_string(i)] << '\n';
				}
			}
			catch (const std::exception& exception)
			{
				std::cout << exception.what();
			}			
		}
	}
}
