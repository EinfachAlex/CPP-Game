#include "Camera.h"

Camera::Camera() : sf::View::View() {
	this->view = sf::View::View(sf::Vector2f(800.0f, 600.0f), sf::Vector2f(1066.66f, 600.0f));
}

sf::View Camera::getView()
{
	return this->view;
}
