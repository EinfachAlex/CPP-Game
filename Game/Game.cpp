#include <SFML/Graphics.hpp>

#include "Utils/FPSCounter.h"
#include "Utils/desktopResolution.h"
#include "MainMenu/MainMenu.h"
#include "MainGame/MainGame.h"
#include "GameWindow.h"


int main()
{
	GameWindow& window = *GameWindow::getInstance(sf::VideoMode((getDesktopResolution().right / 2), (getDesktopResolution().bottom) / 2), "SFML works!");

	MainMenu* mainMenu = MainMenu::getInstance();

	MainGame* mainGame = MainGame::getInstance();

	//window.setVerticalSyncEnabled(true);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (window.hasFocus()) {
			window.clear();

			if (mainMenu->active) {
				mainMenu->loop();
			}

			if (mainGame->active) {
				mainGame->draw();
			}

			window.display();

			calculateFPS();
		}
	}

	return 0;
}

