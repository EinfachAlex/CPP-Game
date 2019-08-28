#pragma once

#include <chrono>
#include <iostream>

int frames = 0;
std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
std::chrono::time_point<std::chrono::system_clock> lasttimestamp = start;

void calculateFPS() {
	std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
	frames++;

	long int now_seconds = now.time_since_epoch().count() / 10000000;
	long int lasttimestamp_seconds = lasttimestamp.time_since_epoch().count() / 10000000;

	if (now_seconds != lasttimestamp_seconds) {
		std::cout << "FPS: " << (frames / (now_seconds - lasttimestamp_seconds)) << "\n";

		lasttimestamp = now;
		frames = 0;
		start = std::chrono::system_clock::now();
	}
}