#pragma once
#include "./..//GameState.h"
#include "./..//MainGame.h"

class OverworldGameState : public GameState
{
private:
	static OverworldGameState* instance;

public:
	OverworldGameState();

	static OverworldGameState* getInstance();

	void handleKeyPress();
};

