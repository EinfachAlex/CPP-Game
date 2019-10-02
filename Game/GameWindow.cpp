#include "GameWindow.h"

GameWindow* GameWindow::instance;

GameWindow::GameWindow()
{
}

GameWindow::GameWindow(sf::VideoMode videoMode, sf::String title) : sf::RenderWindow(videoMode, title) {
}

GameWindow* GameWindow::getInstance(sf::VideoMode videoMode, sf::String title) {
	if (GameWindow::instance == NULL) {
		GameWindow::instance = new GameWindow(videoMode, title);
	}

	return GameWindow::instance;
}

GameWindow* GameWindow::getInstance() {
	if (GameWindow::instance != NULL) {
		return GameWindow::instance;
	}
	else {
		throw;
	}
}
