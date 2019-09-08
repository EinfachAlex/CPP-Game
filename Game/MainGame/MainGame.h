#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include "GameState.h"
#include "World/GameWorld.h"

class MainGame
{
public:
	static bool active;
	static GameState * gameState;
	static GameWorld * gameWorld;
	std::ifstream savedGameStateFile;

	MainGame();
	void initialize();
	bool loadSaveGame();
	void startNewGame();
	void draw();
};