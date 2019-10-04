#include "OverworldCommandQueue.h"
#include "../../CommandQueue/Commands/MoveCommand.h"

OverworldCommandQueue* OverworldCommandQueue::instance;
const int OverworldCommandQueue::cooldown;

OverworldCommandQueue::OverworldCommandQueue() {
	this->commands.push_back(std::make_shared<MoveCommand>(std::string("Dummy")));
}

OverworldCommandQueue* OverworldCommandQueue::getInstance() {
	if (OverworldCommandQueue::instance == NULL) {
		OverworldCommandQueue::instance = new OverworldCommandQueue();
	}

	return OverworldCommandQueue::instance;
}

bool OverworldCommandQueue::cooldownActive() {
	if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count() > std::chrono::duration_cast<std::chrono::milliseconds>(this->lastExecuteTime.time_since_epoch()).count() + this->cooldown) {
		return false;
	}
	else {
		return true;
	}
}

void OverworldCommandQueue::addCommand(std::shared_ptr<Command> command, bool addIfNotEmpty) {
	if (this->cooldownActive() == false || addIfNotEmpty == true) {
		this->commands.push_back(command);

	}
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
		std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();

		if (std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() > std::chrono::duration_cast<std::chrono::milliseconds>(this->lastExecuteTime.time_since_epoch()).count() + this->cooldown) {

			this->commands[0]->perform();
			this->removeCommand();

			this->lastExecuteTime = std::chrono::system_clock::now();
		}
	}
}