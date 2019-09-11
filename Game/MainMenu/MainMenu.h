#pragma once

#include "Buttons/MainMenuStartButton.h"
#include "Buttons/MainMenuMiddleButton.h"
#include "Buttons/MainMenuEndButton.h"

class MainMenu
{
private: 
	 MainMenuStartButton startButton;
	 MainMenuMiddleButton middleButton;
	 MainMenuEndButton endButton;
	 MainMenuButton* activeButton;

	sf::RenderWindow* window;
	sf::Font font;

public: 
	static bool active;
	MainMenu(sf::RenderWindow* window);
	void draw();
	void checkForKeyPress();
	void setActiveButton(MainMenuButton& IactiveButton);

	MainMenuStartButton& getStartButton();
	MainMenuMiddleButton& getMiddleButton();
	MainMenuEndButton& getEndButton();
	MainMenuButton& getActiveButton();
};

