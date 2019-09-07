#pragma once
#include "MainMenuButton.h"

using namespace std;

class MainMenu;

class MainMenuStartButton : public MainMenuButton {
private:
	MainMenu* mainMenu;

public:
	MainMenuStartButton();

	MainMenuStartButton(sf::Vector2f vector, sf::Text text, sf::RenderWindow& window, sf::Vector2f& position, MainMenu* mainMenu);

	void onPressW();
	void onPressA();
	void onPressS();
	void onPressD();
	void onPressEnter();
};
