#pragma once
#include <string>
#include "../Utils/CommandQueue/CommandQueue.h"

struct GameState
{
private:
	CommandQueue commandQueue;

public:
	GameState();

	virtual void handleKeyPress();
};

