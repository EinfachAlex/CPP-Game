#pragma once

#include "WorldBlockCoordinates.h"
#include "SFML/Graphics.hpp"

class WorldBlock
{
public:
	WorldBlockCoordinates coordinates;
	sf::RectangleShape block;

	WorldBlock();
	WorldBlock(WorldBlockCoordinates coordinates);

	~WorldBlock();
	
private:
	
};

