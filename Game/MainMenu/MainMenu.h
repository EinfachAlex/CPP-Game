#pragma once

#include "Buttons/MainMenuStartButton.h"
#include "Buttons/MainMenuMiddleButton.h"
#include "Buttons/MainMenuEndButton.h"
#include "SFML/Window/Keyboard.hpp"

class MainMenu
{
private:
	std::shared_ptr<MainMenuStartButton> startButton;
	std::shared_ptr<MainMenuMiddleButton> middleButton;
	std::shared_ptr<MainMenuEndButton> endButton;
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

