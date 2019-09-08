#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include "GameState.h"

class MainGame
{
public:
	static bool active;
	static GameState * gameState;
	std::ifstream savedGameStateFile;

	MainGame();
	void initialize();
	bool loadSaveGame();
	void startNewGame();
	void draw();
};