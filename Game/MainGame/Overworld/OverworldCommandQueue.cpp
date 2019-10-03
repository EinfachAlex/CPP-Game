#include "OverworldCommandQueue.h"
#include "../../CommandQueue/Commands/MoveCommand.h"

OverworldCommandQueue* OverworldCommandQueue::instance;

OverworldCommandQueue::OverworldCommandQueue() {
	this->commands.push_back(std::make_shared<MoveCommand>(std::string("Dummy")));
}

OverworldCommandQueue* OverworldCommandQueue::getInstance() {
	if (OverworldCommandQueue::instance == NULL) {
		OverworldCommandQueue::instance = new OverworldCommandQueue();
	}

	return OverworldCommandQueue::instance;
}

void OverworldCommandQueue::addCommand(std::shared_ptr<Command> command) {
	this->commands.push_back(command);
}

void OverworldCommandQueue::removeCommand() {
	this->commands.erase(this->commands.begin());
	this->commands.shrink_to_fit();

	if (this->commands.size() > 1) {
		for (size_t i = 0; i < this->commands.size() - 1; i++)
		{
			this->commands[i] = this->commands[i + 1];
		}
	}
}

void OverworldCommandQueue::performNextCommand() {
	if (this->commands.size() > 0) {
		try
		{
			this->commands[0]->perform();
			this->removeCommand();
		}
		catch (const std::exception& wtf)
		{
			std::cout << wtf.what();
		}
	}
}