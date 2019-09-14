#include <SFML/Graphics.hpp>

#include "FPSCounter.h"
#include "desktopResolution.h"
#include "MainMenu/MainMenu.h"
#include "MainGame/MainGame.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode((getDesktopResolution().right / 2), (getDesktopResolution().bottom) / 2), "SFML works!");

	MainMenu mainMenu = MainMenu(&window);

	MainGame mainGame = MainGame(&window);

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

			if (mainMenu.active) {
				mainMenu.draw();
			}

			if (mainGame.active) {
				mainGame.draw();
			}

			window.display();

			calculateFPS();
		}
	}

	return 0;
}

