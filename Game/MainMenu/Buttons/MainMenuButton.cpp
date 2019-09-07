#include "MainMenuButton.h"

MainMenuButton::MainMenuButton() {

}

MainMenuButton::MainMenuButton(sf::Vector2f vector, sf::Text text, sf::RenderWindow& window, sf::Vector2f& position) : RectangleShape(vector) {
	this->text = text;
	this->shape = RectangleShape(vector);

	this->text.setOrigin(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 2);
	this->text.setPosition(position);
	this->text.setFillColor(sf::Color::Green);

	this->shape.setOrigin(this->getSize().x / 2, this->getSize().y / 2);
	this->shape.setPosition(position);
}

void MainMenuButton::unhighlight() {
	this->shape.setFillColor(sf::Color::White);
}

void MainMenuButton::highlight() {
	this->shape.setFillColor(sf::Color::Red);
}

void MainMenuButton::onPressW() {

}

void MainMenuButton::onPressA() {

}

void MainMenuButton::onPressS() {

}

void MainMenuButton::onPressD() {

}

void MainMenuButton::onPressEnter() {

}