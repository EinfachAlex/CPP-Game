#include "MainMenuMiddleButton.h"
#include "../MainMenu.h"

MainMenuMiddleButton::MainMenuMiddleButton() {

}

MainMenuMiddleButton::MainMenuMiddleButton(sf::Vector2f vector, sf::Text text, sf::RenderWindow& window, sf::Vector2f& position, MainMenu* mainMenu) : MainMenuButton(vector, text, window, position) {
	this->mainMenu = mainMenu;
}

void MainMenuMiddleButton::onPressW()
{
	this->shape.setFillColor(sf::Color::White);
	this->mainMenu->getStartButton().shape.setFillColor(sf::Color::Red);
	this->mainMenu->setActiveButton(this->mainMenu->getStartButton());
}

void MainMenuMiddleButton::onPressA()
{
}

void MainMenuMiddleButton::onPressS()
{
	this->shape.setFillColor(sf::Color::White);
	this->mainMenu->getEndButton().shape.setFillColor(sf::Color::Red);
	this->mainMenu->setActiveButton(this->mainMenu->getEndButton());
}

void MainMenuMiddleButton::onPressD()
{
}

void MainMenuMiddleButton::onPressEnter() {

}