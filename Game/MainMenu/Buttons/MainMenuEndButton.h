#pragma once
#include "MainMenuButton.h"

class MainMenu;

class MainMenuEndButton : public MainMenuButton {
private:
	MainMenu* mainMenu;

public:
	MainMenuEndButton();

	MainMenuEndButton(sf::Vector2f vector, sf::Text text, sf::RenderWindow& window, sf::Vector2f& position, MainMenu* mainMenu);

	void onPressW();
	void onPressA();
	void onPressS();
	void onPressD();
	void onPressEnter();
};

