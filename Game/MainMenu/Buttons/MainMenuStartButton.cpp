#include "MainMenuStartButton.h"
#include "../MainMenu.h"
#include "../../MainGame/MainGame.h"

MainMenuStartButton::MainMenuStartButton()
{
}

MainMenuStartButton::MainMenuStartButton(sf::Vector2f vector, sf::Text text, sf::RenderWindow& window, sf::Vector2f& position, MainMenu* mainMenu) : MainMenuButton(vector, text, window, position) {
	this->mainMenu = mainMenu;
}

void MainMenuStartButton::onPressW() {

}

void MainMenuStartButton::onPressA() {
}

void MainMenuStartButton::onPressS() {
	this->shape.setFillColor(sf::Color::White);
	this->mainMenu->getMiddleButton().shape.setFillColor(sf::Color::Red);
	this->mainMenu->setActiveButton(this->mainMenu->getMiddleButton());
}

void MainMenuStartButton::onPressD() {
}

void MainMenuStartButton::onPressEnter() {
	this->mainMenu->active = false;
}

