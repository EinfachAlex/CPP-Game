#pragma once

#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>

using namespace std;

struct MainMenuButton : public sf::RectangleShape
{
public:

	sf::Text text;
	sf::RectangleShape shape;

	MainMenuButton();

	MainMenuButton(sf::Vector2f vector, sf::Text text, sf::RenderWindow& window, sf::Vector2f& position);

	virtual void onPressW();
	virtual void onPressA();
	virtual void onPressS();
	virtual void onPressD();
	virtual void onPressEnter();

	virtual void highlight();
	virtual void unhighlight();
};