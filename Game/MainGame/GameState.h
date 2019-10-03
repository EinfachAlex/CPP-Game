#pragma once
#include <string>
#include "../CommandQueue/CommandQueue.h"

struct GameState
{
private:
	CommandQueue commandQueue;

public:
	GameState();

	virtual void handleKeyPress();

	virtual CommandQueue* getCommandQueue();
};

