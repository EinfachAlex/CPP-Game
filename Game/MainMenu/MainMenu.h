#pragma once

#include "Buttons/MainMenuStartButton.h"
#include "Buttons/MainMenuMiddleButton.h"
#include "Buttons/MainMenuEndButton.h"
#include "SFML/Window/Keyboard.hpp"

class MainMenu
{
private:
	MainMenuStartButton* startButton;
	MainMenuMiddleButton* middleButton;
	MainMenuEndButton* endButton;
	MainMenuButton* activeButton;

	static MainMenu* instance;

	sf::RenderWindow* window;
	sf::Font font;

public:
	static bool active;

	MainMenu(sf::RenderWindow* window);
	void loop();
	void draw();
	void checkForKeyPress();
	void setActiveButton(MainMenuButton& IactiveButton);

	static MainMenu* getInstance();

	MainMenuStartButton& getStartButton();
	MainMenuMiddleButton& getMiddleButton();
	MainMenuEndButton& getEndButton();
	MainMenuButton& getActiveButton();
};

