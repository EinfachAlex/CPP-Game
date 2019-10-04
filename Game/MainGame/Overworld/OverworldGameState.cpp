#include "OverworldGameState.h"

OverworldGameState* OverworldGameState::instance;

void OverworldGameState::handleKeyPress() {
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		this->commandQueue->addCommand(std::make_shared<MoveCommand>(MoveCommand::MOVE_UP), false);
		/*MainGame::getInstance()->view.move(0, -0.1f);
		MainGame::getInstance()->window->setView(MainGame::getInstance()->view.getView());*/
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		this->commandQueue->addCommand(std::make_shared<MoveCommand>(MoveCommand::MOVE_LEFT), false);
		/*MainGame::getInstance()->view.move(-0.1, 0);
		MainGame::getInstance()->window->setView(MainGame::getInstance()->view.getView());*/
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		this->commandQueue->addCommand(std::make_shared<MoveCommand>(MoveCommand::MOVE_DOWN), false);
		/*MainGame::getInstance()->view.move(0, 0.1);
		MainGame::getInstance()->window->setView(MainGame::getInstance()->view.getView());*/
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		this->commandQueue->addCommand(std::make_shared<MoveCommand>(MoveCommand::MOVE_RIGHT), false);
		/*MainGame::getInstance()->view.move(0.1, 0);
		MainGame::getInstance()->window->setView(MainGame::getInstance()->view.getView());*/
	}
}

OverworldGameState::OverworldGameState() : GameState::GameState(){
	this->commandQueue = OverworldCommandQueue::getInstance();
}

OverworldGameState* OverworldGameState::getInstance() {
	if (OverworldGameState::instance == NULL) {
		OverworldGameState::instance = new OverworldGameState();
	}

	return OverworldGameState::instance;
}

CommandQueue* OverworldGameState::getCommandQueue() {
	return this->commandQueue;
}