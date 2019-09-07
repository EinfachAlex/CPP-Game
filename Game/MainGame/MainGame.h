#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

class MainGame
{
public:
	static bool active;
	nlohmann::json gameState;
	std::ifstream saveGame;

	MainGame();
	void initialize();
	bool loadSaveGame();
	void startNewGame();
	void draw();
};