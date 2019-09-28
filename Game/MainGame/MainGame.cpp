#include "MainGame.h"

bool MainGame::active = false;
GameState* MainGame::gameState;
GameWorld MainGame::gameWorld;
sf::View MainGame::view = sf::View::View(sf::Vector2f(500.0f, 500.0f), sf::Vector2f(1200.0f, 675.0f));
sf::RenderWindow* MainGame::window;

MainGame::MainGame() {
}

MainGame::MainGame(sf::RenderWindow* window)
{
	this->window = window;
}

void MainGame::initialize()
{
	this->window->setView(this->view);

	if (!loadSaveGame()) {
		startNewGame();
	}
	else {
		MainGame::gameWorld = *new GameWorld();

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
	MainGame::gameWorld.draw(*this->window);
MainGame* MainGame::getInstance() {
	if (MainGame::instance == NULL) {
		MainGame::instance = new MainGame(GameWindow::getInstance());
	}
	return MainGame::instance;
}