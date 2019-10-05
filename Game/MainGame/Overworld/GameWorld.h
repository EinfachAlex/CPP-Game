#pragma once

#include <fstream>
#include <nlohmann/json.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Tiles/WorldTile.h"
#include <chrono>
#include <iostream>
#include <thread>
#include "Tiles/PlayerTile.h"
#include <memory>

class GameWorld
{
public:
	static const int tileSize = 64;

	WorldTile tiles[100][100];
	sf::VertexArray vertexArray;
	static GameWorld* getInstance();

	void loadWorld(int);
	void draw(sf::RenderWindow& window);
private:
	static GameWorld* instance;

	sf::RenderWindow* window;
	sf::Texture texture;
	int blockSize = 64;

	nlohmann::json worldData;

	void loadWorldPart(int, int);
};