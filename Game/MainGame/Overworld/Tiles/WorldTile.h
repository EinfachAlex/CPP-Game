#pragma once

#include "TileCoordinates.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "TileCoordinates.h"
#include <memory>

class WorldTile
{
public:
	WorldBlockCoordinates coordinates;
	std::shared_ptr<sf::RectangleShape> tile;

	WorldTile();
	WorldTile(WorldBlockCoordinates coordinates);

	~WorldTile();
	
private:
	
};

