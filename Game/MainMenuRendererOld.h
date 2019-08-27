#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "MainMenuButton.h"

MainMenuButton * startButton;
MainMenuButton * middleButton;
MainMenuButton * endButton;
MainMenuButton * activeButton;

sf::Font font;

sf::Clock menuClock;
sf::Time elapsed;

int mainMenuDelay = 300;

namespace MainMenu {
	boolean active = true;
}

void loadMainMenu(sf::RenderWindow& window) {
	font.loadFromFile("Terminus.ttf");

	const_cast<sf::Texture&>(font.getTexture(30)).setSmooth(false);
	const_cast<sf::Texture&>(font.getTexture(30)).generateMipmap();

	sf::Vector2f position = sf::Vector2f(window.getSize().x / 2, 100.0f);
	startButton = new MainMenuButton(sf::Vector2f(300.0f, 100.0f), sf::Text("Spiel starten...!", font, 30), window, position);

	position = sf::Vector2f(window.getSize().x / 2, 200.0f);
	middleButton = new MainMenuButton(sf::Vector2f(300.0f, 100.0f), sf::Text("Irgendwas hier!", font, 30), window, position);

	position = sf::Vector2f(window.getSize().x / 2, 300.0f);
	endButton = new MainMenuButton(sf::Vector2f(300.0f, 100.0f), sf::Text("Spiel beenden!", font, 30), window, position);

	activeButton = startButton;
	activeButton->highlight();
}

bool operator==(const MainMenuButton& a, const MainMenuButton& b)
{
	return a.text.getString() == b.text.getString() && a.getPosition() == b.getPosition();
}

void checkForKeyPress() {
	if (elapsed.asMicroseconds() / 1000 > mainMenuDelay) {

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			if (activeButton == startButton) {
				activeButton->unhighlight();
				middleButton->highlight();

				activeButton = middleButton;
			}
			else if (activeButton == middleButton) {
				activeButton->unhighlight();
				endButton->highlight();

				activeButton = endButton;

			}

			menuClock.restart();
		}

		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			if (activeButton == endButton) {
				activeButton->unhighlight();
				middleButton->highlight();

				activeButton = middleButton;
			}
			else if (activeButton == middleButton) {
				activeButton->unhighlight();
				startButton->highlight();

				activeButton = startButton;
			}

			menuClock.restart();
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			if (activeButton == endButton) {
				std::exit(0);
			}

			if (activeButton == startButton) {
				MainMenu::active = false;
			}

			menuClock.restart();
		}
	}
}

void drawMainMenu(sf::RenderWindow& window) {
	elapsed = menuClock.getElapsedTime();

	checkForKeyPress();
	window.draw(startButton->shape);
	window.draw(startButton->text);
	window.draw(middleButton->shape);
	window.draw(middleButton->text);
	window.draw(endButton->shape);
	window.draw(endButton->text);
}