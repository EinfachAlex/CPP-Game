#pragma once

#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include "Overworld/GameWorld.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "..//GameWindow.h"
#include "Overworld/OverworldGameState.h"
#include "Camera.h"

class OverworldGameState;

class MainGame
{
public:
	bool active;
	GameState* gameState;
	GameWorld* gameWorld;
	Camera camera;
	sf::RenderWindow* window;

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