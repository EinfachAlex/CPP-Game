#include "GameWorld.h"
#include <iostream>
#include <thread>

void GameWorld::loadWorldPart(int tn, int threadForLoopLength) {
	std::chrono::time_point<std::chrono::system_clock> tstart = std::chrono::system_clock::now();

	int offset = tn * threadForLoopLength + tn;

	for (size_t y = offset; y <= offset + threadForLoopLength; y++)
	{
		for (size_t x = 0; x < this->worldData["width"]; x++)
		{
			int tileID;

			try
			{
				tileID = this->worldData["data"][(x + (y * this->worldData["height"]))];


				int tx = tileID % (this->texture.getSize().x / this->tileSize) - 1;
				int ty = tileID / (this->texture.getSize().x / this->tileSize);

				WorldTile wt = WorldTile(WorldBlockCoordinates(x, y));
				this->tiles[x][y] = wt;


				sf::Vertex* quad = &this->vertexArray[(x + (y * this->worldData["height"])) * 4];

				quad[0].position = sf::Vector2f(wt.coordinates.x * tileSize, wt.coordinates.y * tileSize);
				quad[1].position = sf::Vector2f(wt.coordinates.x * tileSize + tileSize, wt.coordinates.y * tileSize + 0);
				quad[2].position = sf::Vector2f(wt.coordinates.x * tileSize + tileSize, wt.coordinates.y * tileSize + tileSize);
				quad[3].position = sf::Vector2f(wt.coordinates.x * tileSize + 0, wt.coordinates.y * tileSize + tileSize);

				quad[0].texCoords = sf::Vector2f((tx * this->tileSize), (ty * this->tileSize));
				quad[1].texCoords = sf::Vector2f(((tx + 1) * this->tileSize), (ty * this->tileSize));
				quad[2].texCoords = sf::Vector2f(((tx + 1) * this->tileSize), ((ty + 1) * this->tileSize));
				quad[3].texCoords = sf::Vector2f((tx * this->tileSize), ((ty + 1) * this->tileSize));
			}
			catch (const std::exception& err)
			{

			}
		}
	}

	std::chrono::time_point<std::chrono::system_clock> tend = std::chrono::system_clock::now();
	auto timePassed = std::chrono::duration_cast<std::chrono::milliseconds>(tend - tstart);
	std::cout << "Thread " << tn << " finished (in " << timePassed.count() << " ms)\n";
}

void GameWorld::loadWorld(int worldID)
{
	this->texture.loadFromFile("tileset.png");

	this->vertexArray.setPrimitiveType(sf::Quads);
	this->vertexArray.resize(40000);

	std::ifstream worldFile;
	worldFile.open(std::to_string(worldID) + ".json");

	if (worldFile.is_open()) {
		//Convert contents of file to string and create json object
		std::string fileContent((std::istreambuf_iterator<char>(worldFile)), std::istreambuf_iterator<char>());
		this->worldData = nlohmann::json::parse(fileContent)["layers"][0];

		int numberOfThreads = 1; //std::thread::hardware_concurrency() / 2 * 1.5;
		int threadForLoopLength = (this->worldData["height"] - 1) / numberOfThreads;

		for (size_t y = 0; y < numberOfThreads; y++)
		{
			std::thread t1 = std::thread(&GameWorld::loadWorldPart, this, static_cast<int>(y), threadForLoopLength);
			t1.detach();
		}
	}
}



void GameWorld::draw(sf::RenderWindow& window) {
	sf::RenderStates rs;
	rs.texture = &this->texture;
	rs.transform = sf::Transform(1, 0, 0, 0, 1, 0, 0, 0, 1);

	window.draw(this->vertexArray, rs);

	this->player.setPosition(100, 100);
	this->player.setFillColor(sf::Color::Green);
	window.draw(this->player);
}