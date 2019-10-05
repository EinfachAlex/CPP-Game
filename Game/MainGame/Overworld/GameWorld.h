#pragma once

#include <fstream>
#include <nlohmann/json.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Tiles/WorldTile.h"

class GameWorld
{
public:
	static const int tileSize = 64;

	WorldTile tiles[100][100];
	sf::VertexArray vertexArray;

	void loadWorld(int);
	void draw(sf::RenderWindow& window);
private:
	sf::RenderWindow* window;
	sf::Texture texture;
	int blockSize = 64;

	nlohmann::json worldData;

	void loadWorldPart(int, int);
};