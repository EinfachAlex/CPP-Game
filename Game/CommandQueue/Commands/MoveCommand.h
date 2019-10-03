#pragma once
#include "Command.h"
#include <string>
#include "..//..//MainGame/MainGame.h"

struct Command;

class MoveCommand : public Command {
private:
	std::string direction;

public:
	MoveCommand(std::string direction);

	void perform();

	static const std::string MOVE_UP;
	static const std::string MOVE_DOWN;
	static const std::string MOVE_RIGHT;
	static const std::string MOVE_LEFT;
};

