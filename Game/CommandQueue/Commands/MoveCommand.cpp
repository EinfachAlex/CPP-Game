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
		mg->camera.move(0, -GameWorld::tileSize);
	}
	else if (this->direction == MoveCommand::MOVE_DOWN) {
		//MainGame::getInstance()->gameWorld.player.move();
		mg->camera.move(0, GameWorld::tileSize);
	}
	else if (this->direction == MoveCommand::MOVE_LEFT) {
		//MainGame::getInstance()->gameWorld.player.move();
		mg->camera.move(-GameWorld::tileSize, 0);
	}
	else if (this->direction == MoveCommand::MOVE_RIGHT) {
		//MainGame::getInstance()->gameWorld.player.move();
		mg->camera.move(GameWorld::tileSize, 0);
	}

	mg->window->setView(mg->camera.getView());
}
