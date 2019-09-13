#include "WorldBlock.h"

WorldBlock::WorldBlock() {

}

WorldBlock::WorldBlock(WorldBlockCoordinates coordinates){
	this->coordinates = coordinates;
	this->block = sf::RectangleShape(sf::Vector2f(16.0f, 16.0f));
	this->block.setFillColor(sf::Color::Red);
}

WorldBlock::~WorldBlock() {
	//delete this->block;
}