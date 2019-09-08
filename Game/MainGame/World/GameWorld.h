#pragma once

#include "WorldBlock.h"
#include <fstream>
#include <nlohmann/json.hpp>

class GameWorld
{
private:
	WorldBlock* blocks[10][10];
	std::ifstream worldFile;
public:
	void loadWorld(int);
};

