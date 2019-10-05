#pragma once

#include <fstream>
#include <nlohmann/json.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Tiles/WorldTile.h"
#include <chrono>
#include <iostream>
#include <thread>
#include "Tiles/PlayerTile.h"
#include <memory>

class GameWorld
{
public:
	static const int tileSize = 48;

	std::vector<std::vector<WorldTile>> tiles;
	sf::VertexArray vertexArray;
	std::shared_ptr<PlayerTile> player;

	static GameWorld* getInstance();

	void loadWorld(int);
	void draw(sf::RenderWindow& window);

	std::shared_ptr<PlayerTile> getPlayer();

private:
	static GameWorld* instance;

	sf::RenderWindow* window;
	sf::Texture texture;
	
	nlohmann::json worldData;

	void loadWorldPart(int, int);
};