#include "WorldTile.h"

WorldTile::WorldTile() {

}

WorldTile::WorldTile(WorldBlockCoordinates coordinates){
	this->coordinates = coordinates;
	this->tile = std::make_shared<sf::RectangleShape>(sf::Vector2f(16.0f, 16.0f));
	this->tile->setFillColor(sf::Color::Red);
}

WorldTile::~WorldTile() {
	//delete this->block;
}