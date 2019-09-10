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
public:
	WorldBlock* blocks[100][100];
	void loadWorld(int);
	void draw(sf::RenderWindow& window);
};