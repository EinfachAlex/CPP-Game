#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include "GameState.h"
#include "World/GameWorld.h"
#include <SFML/Graphics/RenderWindow.hpp>

class MainGame
{
public:
	static bool active;
	static GameState* gameState;
	static GameWorld gameWorld;
	sf::RenderWindow* window;
	std::ifstream savedGameStateFile;

	MainGame();
	MainGame(sf::RenderWindow* window);
	void initialize();
	bool loadSaveGame();
	void startNewGame();
	void draw();
};