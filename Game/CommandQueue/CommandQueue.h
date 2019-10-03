#pragma once
#include <vector>
#include "Commands/Command.h"

struct CommandQueue {
private:
	Command* commands[100];
	int cooldown;

public:
	virtual void addCommand(Command command);
	void performNextCommand();
};

