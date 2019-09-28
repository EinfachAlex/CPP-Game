#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include "GameState.h"
#include "Overworld/GameWorld.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "..//GameWindow.h"

class MainGame
{
public:
	static bool active;
	static GameState* gameState;
	static GameWorld gameWorld;
	static sf::View view;
	static sf::RenderWindow* window;

	static MainGame* instance;

	std::ifstream savedGameStateFile;

	MainGame();
	MainGame(sf::RenderWindow* window);
	void initialize();
	bool loadSaveGame();
	void startNewGame();
	void loop();
	void draw();
	void checkForKeyPress();

	static MainGame* getInstance();
};