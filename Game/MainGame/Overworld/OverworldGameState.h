#pragma once
#include "./..//GameState.h"
#include "./..//MainGame.h"
#include "OverworldCommandQueue.h"

class OverworldGameState : public GameState
{
private:
	static OverworldGameState* instance;

	OverworldCommandQueue commandQueue;

public:
	OverworldGameState();

	static OverworldGameState* getInstance();

	void handleKeyPress();
};

