#include "MoveCommand.h"

const std::string MoveCommand::MOVE_UP = "W";
const std::string MoveCommand::MOVE_DOWN = "S";
const std::string MoveCommand::MOVE_LEFT = "A";
const std::string MoveCommand::MOVE_RIGHT = "D";

MoveCommand::MoveCommand(std::string direction) {
	this->direction = direction;
}

void MoveCommand::perform() {
	MainGame* mg = MainGame::getInstance();

	if (this->direction == MoveCommand::MOVE_UP) {
		//MainGame::getInstance()->gameWorld.player.move();
		mg->view.move(0, -1);
	}
	else if (this->direction == MoveCommand::MOVE_DOWN) {
		//MainGame::getInstance()->gameWorld.player.move();
		mg->view.move(0, 1);
	}
	else if (this->direction == MoveCommand::MOVE_LEFT) {
		//MainGame::getInstance()->gameWorld.player.move();
		mg->view.move(-1, 0);
	}
	else if (this->direction == MoveCommand::MOVE_RIGHT) {
		//MainGame::getInstance()->gameWorld.player.move();
		mg->view.move(1, 0);
	}

	mg->window->setView(mg->view.getView());
}
