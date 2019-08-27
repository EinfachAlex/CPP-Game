#pragma once

#include <ctime>
#include <iostream>

int frames = 0;
long int start = static_cast<long int> (std::time(0));
long int lasttimestamp = start;

void calculateFPS() {
	frames++;
	long int now = static_cast<long int> (std::time(0));
	if (now != lasttimestamp) {
		lasttimestamp = now;
		if ((lasttimestamp - start) < 1) {
			lasttimestamp = start + 1;
		}
		std::cout << "FPS: " << (frames / (lasttimestamp - start)) << "\n";
		frames = 0;
		start = static_cast<long int> (std::time(0));
		//start = std::time(0);
	}
}
