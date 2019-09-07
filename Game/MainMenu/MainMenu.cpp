#include "MainMenu.h"

bool MainMenu::active = true;

MainMenu::MainMenu(sf::RenderWindow* window) {
	this->window = window;
	font.loadFromFile("Terminus.ttf");

	const_cast<sf::Texture&>(font.getTexture(30)).setSmooth(false);
	const_cast<sf::Texture&>(font.getTexture(30)).generateMipmap();

	sf::Vector2f position = sf::Vector2f(static_cast<float> ((*this->window).getSize().x / 2), 100.0f);
	startButton = new MainMenuStartButton(sf::Vector2f(300.0f, 100.0f), sf::Text("Spiel starten...!", font, 30), *this->window, position, this);

	position = sf::Vector2f(static_cast<float> ((*this->window).getSize().x / 2), 200.0f);
	middleButton = new MainMenuMiddleButton(sf::Vector2f(300.0f, 100.0f), sf::Text("Irgendwas hier!", font, 30), *this->window, position, this);

	position = sf::Vector2f(static_cast<float> ((*this->window).getSize().x / 2), 300.0f);
	endButton = new MainMenuEndButton(sf::Vector2f(300.0f, 100.0f), sf::Text("Spiel beenden!", font, 30), *this->window, position, this);

	activeButton = startButton;
	activeButton->highlight();
}

void MainMenu::draw(sf::RenderWindow& window) {
	//elapsed = menuClock.getElapsedTime();

	checkForKeyPress();
	window.draw(startButton->shape);
	window.draw(startButton->text);
	window.draw(middleButton->shape);
	window.draw(middleButton->text);
	window.draw(endButton->shape);
	window.draw(endButton->text);
}

void MainMenu::checkForKeyPress() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		activeButton->onPressW();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		activeButton->onPressA();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		activeButton->onPressS();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		activeButton->onPressD();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)) {
		activeButton->onPressEnter();
	}
}

void MainMenu::setActiveButton(MainMenuButton& IactiveButton)
{
	activeButton = &IactiveButton;
}

MainMenuStartButton& MainMenu::getStartButton()
{
	return *startButton;
}

MainMenuMiddleButton& MainMenu::getMiddleButton()
{
	return *middleButton;
}

MainMenuEndButton& MainMenu::getEndButton()
{
	return *endButton;
}

MainMenuButton& MainMenu::getActiveButton()
{
	return *activeButton;
}