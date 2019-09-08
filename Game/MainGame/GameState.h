#pragma once
#include <string>

class GameState
{
public:
	GameState(std::string name);
	std::string getName();

private:
	std::string name;
};

