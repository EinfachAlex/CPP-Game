#include "OverworldGameState.h"

OverworldGameState* OverworldGameState::instance;

void OverworldGameState::handleKeyPress() {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		MainGame::getInstance()->view.move(0, -0.1);
		MainGame::getInstance()->window->setView(MainGame::getInstance()->view.getView());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		MainGame::getInstance()->view.move(-0.1, 0);
		MainGame::getInstance()->window->setView(MainGame::getInstance()->view.getView());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		MainGame::getInstance()->view.move(0, 0.1);
		MainGame::getInstance()->window->setView(MainGame::getInstance()->view.getView());
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		MainGame::getInstance()->view.move(0.1, 0);
		MainGame::getInstance()->window->setView(MainGame::getInstance()->view.getView());
	}
}

OverworldGameState::OverworldGameState() : GameState::GameState(){
}

OverworldGameState* OverworldGameState::getInstance() {
	if (OverworldGameState::instance == NULL) {
		OverworldGameState::instance = new OverworldGameState();
	}

	return OverworldGameState::instance;
}