#pragma once
#include <SFML/Graphics/View.hpp>

class Camera : sf::View
{
private:
	sf::View view;

public:
	Camera();

	void move(float x, float y) {
		this->view.move(sf::Vector2f(x, y));
	}

	sf::View getView();
};

