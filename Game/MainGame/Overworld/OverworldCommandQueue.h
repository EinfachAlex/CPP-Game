#pragma once
#include "../../CommandQueue/CommandQueue.h"
#include <array>

struct CommandQueue;

class OverworldCommandQueue : public CommandQueue {
private:
	static OverworldCommandQueue* instance;

	std::vector<std::shared_ptr<Command>> commands;
	int cooldown;

	void removeCommand();

public:
	static OverworldCommandQueue* getInstance();

	OverworldCommandQueue();

	void addCommand(std::shared_ptr<Command> command);
	
	void performNextCommand();
};

