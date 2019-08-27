#pragma once

#include "MainMenuStartButton.h"
#include "MainMenuMiddleButton.h"
#include "MainMenuEndButton.h"

class MainMenu
{
private: 
	 MainMenuStartButton* startButton;
	 MainMenuMiddleButton* middleButton;
	 MainMenuEndButton* endButton;
	 MainMenuButton* activeButton;

	sf::RenderWindow* window;
	sf::Font font;

public: 
	static bool active;
	MainMenu(sf::RenderWindow* window);
	void draw(sf::RenderWindow& window);
	void checkForKeyPress();
	void setActiveButton(MainMenuButton& IactiveButton);

	MainMenuStartButton& getStartButton();
	MainMenuMiddleButton& getMiddleButton();
	MainMenuEndButton& getEndButton();
	MainMenuButton& getActiveButton();
};

