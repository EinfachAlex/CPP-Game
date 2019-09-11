#pragma once

#include "Blocks/WorldBlock.h"
#include "Blocks/WorldBlockCoordinates.h"
#include <fstream>
#include <nlohmann/json.hpp>
#include <SFML/Graphics.hpp>

class GameWorld
{
private:
	std::ifstream worldFile;
	sf::RenderWindow* window;
public:
	GameWorld();
	GameWorld(sf::RenderWindow* window);
	WorldBlock* blocks[99][99];
	void loadWorld(int);
	void draw();
};