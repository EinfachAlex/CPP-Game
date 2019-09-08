#include "GameState.h"

GameState::GameState(std::string name)
{
	this->name = name;
}

std::string GameState::getName() {
	return this->name;
}