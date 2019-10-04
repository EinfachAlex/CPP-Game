#pragma once
#include "../../CommandQueue/CommandQueue.h"
#include <array>
#include <chrono>

struct CommandQueue;

class OverworldCommandQueue : public CommandQueue {
private:
	static OverworldCommandQueue* instance;

	std::vector<std::shared_ptr<Command>> commands;

	static const int cooldown = 500;
	std::chrono::time_point<std::chrono::system_clock> lastExecuteTime = std::chrono::system_clock::now();

	void removeCommand();

	bool cooldownActive();

public:
	static OverworldCommandQueue* getInstance();

	OverworldCommandQueue();

	void addCommand(std::shared_ptr<Command> command, bool addIfNotEmpty);
	
	void performNextCommand();
};

