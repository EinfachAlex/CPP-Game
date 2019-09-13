#pragma once

#include "Blocks/WorldBlock.h"
#include "Blocks/WorldBlockCoordinates.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>

class GameWorld
{
public:
	WorldBlock* blocks[99][99];
	sf::VertexArray vertexArray;

	GameWorld();
	void loadWorld(int);
	void draw(sf::RenderWindow& window);
private:
	//std::ifstream worldFile;
	sf::RenderWindow* window;
	sf::Texture texture;
};