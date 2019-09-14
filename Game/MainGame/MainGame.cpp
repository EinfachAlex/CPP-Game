#include "MainGame.h"

bool MainGame::active = false;
GameState* MainGame::gameState;
GameWorld MainGame::gameWorld;

MainGame::MainGame() {
}

MainGame::MainGame(sf::RenderWindow* window)
{
	this->window = window;
}

void MainGame::initialize()
{
	if (!loadSaveGame()) {
		startNewGame();
	}
	else {
		std::cout << this->gameState->getName() << '\n';
		MainGame::gameWorld.loadWorld(1);
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
	MainGame::gameWorld.draw(*this->window);
}