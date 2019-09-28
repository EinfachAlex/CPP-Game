#include "WorldTile.h"

WorldTile::WorldTile() {

}

WorldTile::WorldTile(WorldBlockCoordinates coordinates){
	this->coordinates = coordinates;
	this->block = sf::RectangleShape(sf::Vector2f(16.0f, 16.0f));
	this->block.setFillColor(sf::Color::Red);
}

WorldTile::~WorldTile() {
	//delete this->block;
}