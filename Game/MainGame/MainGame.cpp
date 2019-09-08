#include "MainGame.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include "GameState.h"
#include "../MainMenu/MainMenu.h"
#include "World/GameWorld.h"

bool MainGame::active = false;
GameState * MainGame::gameState;
GameWorld * MainGame::gameWorld;

MainGame::MainGame()
{

}

void MainGame::initialize()
{
	if (!loadSaveGame()) {
		startNewGame();
	}
	else {
		std::cout << this->gameState->getName() << '\n';
		this->gameWorld = new GameWorld();
		this->gameWorld->loadWorld(1);
		for (size_t i = 0; i < 10; i++)
		{
			for (size_t j = 0; j < 10; j++)
			{
				if (this->gameWorld->blocks[i][j]) {
				}
			}
		}
	}

	this->active = true;
}

bool MainGame::loadSaveGame()
{
	this->savedGameStateFile.open("save.json");

	if (this->savedGameStateFile.is_open()) {
		std::string content((std::istreambuf_iterator<char>(this->savedGameStateFile)), std::istreambuf_iterator<char>());

		nlohmann::json jsonSave = nlohmann::json::parse(content);

		this->gameState = new GameState(jsonSave["name"]);

		return true;
	}
	else {
		std::cout << "Fehler beim öffnen der Save Datei";
		return false;
	}
}

void MainGame::startNewGame()
{

}

void MainGame::draw() {
	//this->gameState["color"];
}