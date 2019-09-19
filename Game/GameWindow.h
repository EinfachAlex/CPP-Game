#pragma once
#include <SFML/Graphics/RenderWindow.hpp>

class GameWindow : public sf::RenderWindow {
private:
	static GameWindow* instance;

public:
	GameWindow();

	GameWindow(sf::VideoMode videoMode, sf::String title);

	static GameWindow* getInstance(sf::VideoMode videoMode, sf::String title);
	static GameWindow* getInstance();
};

