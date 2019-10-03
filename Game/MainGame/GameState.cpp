#include "GameState.h"

GameState::GameState(){
}

void GameState::handleKeyPress() {
}

CommandQueue* GameState::getCommandQueue(){
	return &this->commandQueue;
}
