#include "MainGame.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>

bool MainGame::active = false;

MainGame::MainGame()
{

}

void MainGame::initialize()
{
	if (!loadSaveGame()) {
		startNewGame();
	}

	this->active = true;
}

bool MainGame::loadSaveGame()
{
	this->saveGame.open("save.json");
	if (this->saveGame.is_open()) {
		std::string content((std::istreambuf_iterator<char>(this->saveGame)), std::istreambuf_iterator<char>());
		this->gameState = nlohmann::json::parse(content);
		if (this->gameState["name"]) {
			std::cout << "Dein Name ist:" << this->gameState["name"];
		}
		
	}
	else {
	}
	
	return false;
}

void MainGame::startNewGame()
{

}

void MainGame::draw() {
}