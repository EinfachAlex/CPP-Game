#pragma once

#include "WorldBlockCoordinates.h"
#include "SFML/Graphics.hpp"

class WorldBlock
{
public:
	WorldBlock();
	WorldBlock(WorldBlockCoordinates coordinates);
	WorldBlockCoordinates coordinates;
	sf::RectangleShape * block;
private:
	
};

