#include "Camera.h"

Camera::Camera() : sf::View::View() {
	this->view = sf::View::View(sf::Vector2f(800.0f, 600.0f), sf::Vector2f(1066.66f, 600.0f));
}

sf::View Camera::getView()
{
	return this->view;
}

void Camera::move(double x, double y) {
	this->view.move(sf::Vector2f(float(x), float(y)));
}

void Camera::centerOnPlayer(){
	WorldBlockCoordinates wbc = GameWorld::getInstance()->getPlayer()->coordinates;

	this->view.setCenter(sf::Vector2f(float(wbc.x * GameWorld::tileSize), float(wbc.y * GameWorld::tileSize)));
}
