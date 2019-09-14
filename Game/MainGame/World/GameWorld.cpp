#include "GameWorld.h"
#include <iostream>
#include <thread>

GameWorld::GameWorld() {

}

GameWorld::GameWorld(sf::RenderWindow* window) {
	this->window = window;
}

void GameWorld::loadWorld(int worldID)
{
	this->worldFile.open(std::to_string(worldID) + ".json");

	for (size_t x = 0; x < numberOfThreads -1; x++)
	{
		std::thread t1 = std::thread(&GameWorld::loadWorldPart, this, static_cast<int>(x), threadForLoopLength);
		t1.join();
	}

	/*for (size_t i = 0; i < numberOfThreads; i++)
	{
		for (size_t x = i * threadForLoopLength + i; x < i * threadForLoopLength + i + threadForLoopLength; x++)
		{
			for (size_t y = 0; y < 99; y++)
			{
				WorldBlock wb = WorldBlock(WorldBlockCoordinates(x, y));
				this->blocks[x][y] = wb;

				//std::cout << "Drawing " << offset + x << " / " << y << " - VertexOffset: " << (((y * x) + (offset + x)) * 4) << '\n';

				sf::Vertex* quad = &this->vertexArray[((y * x) + (x)) * 4];

				quad[0].position = sf::Vector2f(wb.coordinates.x, wb.coordinates.y);
				quad[0].color = sf::Color::Yellow;

				quad[1].position = sf::Vector2f(wb.coordinates.x + 64, wb.coordinates.y + 0);
				quad[1].color = sf::Color::Red;

				quad[2].position = sf::Vector2f(wb.coordinates.x + 64, wb.coordinates.y + 64);
				quad[2].color = sf::Color::Green;

				quad[3].position = sf::Vector2f(wb.coordinates.x + 0, wb.coordinates.y + 64);
				quad[3].color = sf::Color::Cyan;
			}

		}
	}*/


	//std::chrono::time_point<std::chrono::system_clock> wlend = std::chrono::system_clock::now();
	//auto timePassed = std::chrono::duration_cast<std::chrono::milliseconds>(wlend - wlstart);

	//std::cout << "Drecks Welt zu laden hat " << std::to_string(timePassed.count()) << "ms gedauert, du Hurensohn\n";

	//ToDo: objekt f�r jedes ding dann vertex vom objekt nehmen und in vertexarray packen 
	/*for (size_t a = 0; a < 50000; a++)
	{
		this->vertexArray[a] = dummy[a];
	}

	this->vertexArray.append(sf::RectangleShape(sf::Vector2f(1.0f, 1.0f)));*/

	/*this->worldFile.open(std::to_string(worldID) + ".json");

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
	for (size_t y = 0; y < 99; y++)
	{
		for (size_t x = 0; x < 99; x++)
		{
			WorldBlock* worldBlock = new WorldBlock(WorldBlockCoordinates(x, y));

			this->blocks[y][x] = worldBlock;
		}
	}

	std::cout << "Fertig!";*/
}

void GameWorld::draw(sf::RenderWindow& window) {
	/*for (size_t y = 0; y < 99; y++)
	{
		for (size_t x = 0; x < 99; x++)
		{

			if (this->blocks[y][x] != NULL) {
				WorldBlock wb = *this->blocks[y][x];

				sf::Vertex* blockidiot = &this->vertexArray[(y * 99) + x];

				blockidiot[0].position = sf::Vector2f((wb.coordinates.x * wb.block->getSize().x), (wb.coordinates.y * wb.block->getSize().y));
				blockidiot[1].position = sf::Vector2f((wb.coordinates.x * wb.block->getSize().x) + wb.block->getSize().x, (wb.coordinates.y * wb.block->getSize().y));
				blockidiot[2].position = sf::Vector2f((wb.coordinates.x * wb.block->getSize().x) + wb.block->getSize().x, (wb.coordinates.y * wb.block->getSize().y) + wb.block->getSize().y);
				blockidiot[3].position = sf::Vector2f((wb.coordinates.x * wb.block->getSize().x), (wb.coordinates.y * wb.block->getSize().y) + wb.block->getSize().y);
				//wb.block->setPosition(sf::Vector2f((wb.coordinates.x * wb.block->getSize().x), (wb.coordinates.y * wb.block->getSize().y)));
				blockidiot[0].color = sf::Color::Red;
				blockidiot[1].color = sf::Color::Red;
				blockidiot[2].color = sf::Color::Red;
				blockidiot[3].color = sf::Color::Red;
			}
		}
	}*/

	/*sf::VertexArray quad(sf::Quads, 4);

	quad[0].position = sf::Vector2f(40, 50);
	quad[0].color = sf::Color::Yellow;

	quad[1].position = sf::Vector2f(80, 50);
	quad[1].color = sf::Color::Red;

	quad[2].position = sf::Vector2f(90, 200);
	quad[2].color = sf::Color::Green;

	quad[3].position = sf::Vector2f(10, 150);
	quad[3].color = sf::Color::Cyan;*/

	//Vertex Buffer machen oder so
	//this->window->draw(quad);

	/*for (size_t a = 0; a < 1; a++)
	{
		if (this->vertexArray[a].color.r > 200) this->vertexArray[a].color.r = 0;
		if (this->vertexArray[a].color.g > 200) this->vertexArray[a].color.g = 0;
		if (this->vertexArray[a].color.b > 200) this->vertexArray[a].color.b = 0;

		this->vertexArray[a].color.r = this->vertexArray[a].color.r + 1;
		std::cout << this->vertexArray[a].color.toInteger();
	}*/

	window.draw(this->vertexArray);
}