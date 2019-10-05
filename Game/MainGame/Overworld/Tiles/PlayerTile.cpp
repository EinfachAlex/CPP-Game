#include "PlayerTile.h"
#include "../GameWorld.h"

PlayerTile::PlayerTile() {
	this->tile = std::make_shared<sf::RectangleShape>(sf::Vector2f(GameWorld::tileSize, GameWorld::tileSize));
}