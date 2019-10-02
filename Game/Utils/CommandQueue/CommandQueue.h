#pragma once
#include <vector>
#include "Command.h"

struct CommandQueue {
private:
	std::vector<Command> commands;
	int cooldown;

public:
	virtual void addCommand();
	virtual void performNextCommand();
};

