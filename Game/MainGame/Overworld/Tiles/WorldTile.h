#pragma once

#include "TileCoordinates.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "TileCoordinates.h"

class WorldTile
{
public:
	WorldBlockCoordinates coordinates;
	sf::RectangleShape block;

	WorldTile();
	WorldTile(WorldBlockCoordinates coordinates);

	~WorldTile();
	
private:
	
};

