#pragma once
#include <SFML/Graphics/View.hpp>
#include "..//MainGame/Overworld/GameWorld.h"

class Camera : sf::View
{
private:
	sf::View view;

public:
	Camera();

	void move(double x, double y);
	void centerOnPlayer();

	sf::View getView();
};

