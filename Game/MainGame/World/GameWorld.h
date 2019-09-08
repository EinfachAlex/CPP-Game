#pragma once

#include "WorldBlock.h"
#include <fstream>
#include <nlohmann/json.hpp>

class GameWorld
{
private:
	std::ifstream worldFile;
public:
	WorldBlock* blocks[10][10];
	void loadWorld(int);
};

