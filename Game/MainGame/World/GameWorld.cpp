#include "GameWorld.h"
#include <iostream>
#include <chrono>
#include <thread>

void GameWorld::loadWorldPart(int tn, int threadForLoopLength) {
	std::chrono::time_point<std::chrono::system_clock> tstart = std::chrono::system_clock::now();

	int offset = tn * threadForLoopLength + tn;

	for (size_t x = offset; x <= offset + threadForLoopLength; x++)
	{
		//std::cout << "Loading " << offset + x << '\n';
		for (size_t y = 0; y < 9; y++)
		{

			int tileNumber = level[x * 9 + y];

			int tx = tileNumber % (this->texture.getSize().x / this->blockSize);
			int ty = tileNumber / (this->texture.getSize().x / this->blockSize);

			WorldBlock wb = WorldBlock(WorldBlockCoordinates(x, y));
			this->blocks[x][y] = wb;

			//std::cout << "Drawing " << x << " / " << y << " - VertexOffset: " << ((y + (x * 9)) * 4) << '\n';

			sf::Vertex* quad = &this->vertexArray[(y + (x * 9)) * 4];

			quad[0].position = sf::Vector2f(wb.coordinates.x * blockSize, wb.coordinates.y * blockSize);
			quad[1].position = sf::Vector2f(wb.coordinates.x * blockSize + blockSize, wb.coordinates.y * blockSize + 0);
			quad[2].position = sf::Vector2f(wb.coordinates.x * blockSize + blockSize, wb.coordinates.y * blockSize + blockSize);
			quad[3].position = sf::Vector2f(wb.coordinates.x * blockSize + 0, wb.coordinates.y * blockSize + blockSize);

			quad[0].texCoords = sf::Vector2f((tx * this->blockSize), (ty * this->blockSize));
			quad[1].texCoords = sf::Vector2f(((tx + 1) * this->blockSize), (ty * this->blockSize));
			quad[2].texCoords = sf::Vector2f(((tx + 1) * this->blockSize), ((ty + 1) * this->blockSize));
			quad[3].texCoords = sf::Vector2f((tx * this->blockSize), ((ty + 1) * this->blockSize));
		}
	}

	std::chrono::time_point<std::chrono::system_clock> tend = std::chrono::system_clock::now();
	auto timePassed = std::chrono::duration_cast<std::chrono::milliseconds>(tend - tstart);
	std::cout << "Thread " << tn << " finished (in " << timePassed.count() << " ms.\n";

}
void GameWorld::loadWorld(int worldID)
{
	this->texture.loadFromFile("tileset.png");

	this->vertexArray.setPrimitiveType(sf::Quads);
	this->vertexArray.resize(40000);

	int numberOfThreads = 11; //std::thread::hardware_concurrency() / 2 * 1.5;
	int threadForLoopLength = 99 / numberOfThreads;


	for (size_t x = 0; x < numberOfThreads - 1; x++)
	{
		std::thread t1 = std::thread(&GameWorld::loadWorldPart, this, static_cast<int>(x), threadForLoopLength);
		t1.detach();
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
	sf::RenderStates rs;
	rs.texture = &this->texture;
	rs.transform = sf::Transform(1, 0, 0, 0, 1, 0, 0, 0, 1);

	window.draw(this->vertexArray, rs);
}