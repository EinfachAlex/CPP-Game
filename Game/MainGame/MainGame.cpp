#include "MainGame.h"

#include "..//MainMenu/Buttons/MainMenuStartButton.h"

MainGame* MainGame::instance;

MainGame::MainGame() {
}

MainGame::MainGame(sf::RenderWindow* window) {
	this->window = window;
}

void MainGame::initialize() {
	this->window->setView(this->view.getView());

	if (!loadSaveGame()) {
		startNewGame();
	}
	else {
		MainGame::gameWorld = *new GameWorld();

		MainGame::gameWorld.loadWorld(1);
		this->camera.centerOnPlayer();
		this->window->setView(this->camera.getView());
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

void MainGame::checkForKeyPress() {
	//ToDo: Check if any Key is pressed.

	this->gameState->handleKeyPress();
}

void MainGame::draw() {
	MainGame::gameWorld.draw(*this->window);
}

void MainGame::loop() {
	this->checkForKeyPress();
	OverworldCommandQueue::getInstance()->performNextCommand();
	this->draw();
}

MainGame* MainGame::getInstance() {
	if (MainGame::instance == NULL) {
		MainGame::instance = new MainGame(GameWindow::getInstance());
	}

	return MainGame::instance;
}