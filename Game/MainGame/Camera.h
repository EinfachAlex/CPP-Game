#pragma once
#include <SFML/Graphics/View.hpp>

class Camera : sf::View
{
private:
	sf::View view;

public:
	Camera();

	void move(double x, double y);

	sf::View getView();
};

