#include "GameWorld.h"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <nlohmann/json.hpp>
#include "Blocks/WorldBlockCoordinates.h"
#include "Blocks/WorldBlock.h"
#include <thread>

GameWorld::GameWorld() {

}

GameWorld::GameWorld(sf::RenderWindow* window) {
	this->window = window;
}

void GameWorld::loadWorld(int worldID)
{
	this->worldFile.open(std::to_string(worldID) + ".json");

	if (this->worldFile.is_open()) {
		//Convert contents of file to string and create json object
		std::string fileContent((std::istreambuf_iterator<char>(this->worldFile)), std::istreambuf_iterator<char>());
		nlohmann::json jsonWorld = nlohmann::json::parse(fileContent);

		//Iterate over JSON, (Y)
		for (size_t y = 0; y <= (jsonWorld.size() - 1); y++)
		{
			try
			{
				nlohmann::json jsonWorldX = jsonWorld[std::to_string(y + 1)];
				std::cout << "Y: " << y + 1 << '\n';

				//Iterate over JSON, (X)
				for (size_t x = 0; x <= (jsonWorldX.size() - 1); x++)
				{
					//std::cout << "X: " << x + 1 << jsonWorldX[std::to_string(x + 1)] << '\n';

					WorldBlock* worldBlock = new WorldBlock(WorldBlockCoordinates(x, y));

					this->blocks[y][x] = worldBlock;
				}
			}
			catch (const std::exception& exception)
			{
				std::cout << exception.what();
			}
		}
	}
	this->vertexArray.setPrimitiveType(sf::Quads);
	this->vertexArray.resize(10000);

	sf::Vertex* quad = &this->vertexArray[0];
	quad[0].position = sf::Vector2f(0, 0);
	quad[0].color = sf::Color::Yellow;

	quad[1].position = sf::Vector2f(64, 0);
	quad[1].color = sf::Color::Red;

	quad[2].position = sf::Vector2f(64, 64);
	quad[2].color = sf::Color::Green;

	quad[3].position = sf::Vector2f(0, 64);
	quad[3].color = sf::Color::Cyan;
}

void GameWorld::draw(sf::RenderWindow& window) {
	for (size_t y = 0; y < 100; y++)
	{
		for (size_t x = 0; x < 100; x++)
		{
			if (this->blocks[y][x] != NULL) {
				WorldBlock wb = *this->blocks[y][x];

				wb.block->setPosition(sf::Vector2f((wb.coordinates.x * wb.block->getSize().x), (wb.coordinates.y * wb.block->getSize().y)));

				window.draw(*blocks[y][x]->block);
			}
		}
	}

	window.draw(this->vertexArray);
}