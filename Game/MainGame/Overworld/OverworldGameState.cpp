#include "OverworldGameState.h"

OverworldGameState* OverworldGameState::instance;

void OverworldGameState::handleKeyPress() {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		this->commandQueue.addCommand();
		/*MainGame::getInstance()->view.move(0, -0.1f);
		MainGame::getInstance()->window->setView(MainGame::getInstance()->view.getView());*/
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		this->commandQueue.addCommand();
		/*MainGame::getInstance()->view.move(-0.1, 0);
		MainGame::getInstance()->window->setView(MainGame::getInstance()->view.getView());*/
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		this->commandQueue.addCommand();
		/*MainGame::getInstance()->view.move(0, 0.1);
		MainGame::getInstance()->window->setView(MainGame::getInstance()->view.getView());*/
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->commandQueue.addCommand();
		/*MainGame::getInstance()->view.move(0.1, 0);
		MainGame::getInstance()->window->setView(MainGame::getInstance()->view.getView());*/
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