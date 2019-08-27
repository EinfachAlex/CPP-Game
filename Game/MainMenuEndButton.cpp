#include "MainMenuEndButton.h"
#include "MainMenu.h"

MainMenuEndButton::MainMenuEndButton() {

}

MainMenuEndButton::MainMenuEndButton(sf::Vector2f vector, sf::Text text, sf::RenderWindow& window, sf::Vector2f& position, MainMenu* mainMenu) : MainMenuButton(vector, text, window, position) {
	this->mainMenu = mainMenu;
}

void MainMenuEndButton::onPressW()
{
	this->shape.setFillColor(sf::Color::White);
	this->mainMenu->getMiddleButton().shape.setFillColor(sf::Color::Red);
	this->mainMenu->setActiveButton(this->mainMenu->getMiddleButton());
}

void MainMenuEndButton::onPressA()
{
}

void MainMenuEndButton::onPressS()
{
}

void MainMenuEndButton::onPressD()
{
}

void MainMenuEndButton::onPressEnter() {
	std::exit(0);
}