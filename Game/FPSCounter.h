#pragma once

#include <chrono>
#include <iostream>

int frames = 0;
std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
std::chrono::time_point<std::chrono::system_clock> lasttimestamp = start;

void calculateFPS() {
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	frames++;

	auto timePassed = std::chrono::duration_cast<std::chrono::seconds>(now - lasttimestamp);

	if (timePassed.count() >= 1) {
		std::cout << "FPS: " << (frames) << "\n";

		lasttimestamp = now;
		frames = 0;
		start = std::chrono::system_clock::now();
	}
}