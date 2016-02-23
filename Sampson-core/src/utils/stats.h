#pragma once

#include <GLFW/glfw3.h>
#include <stdio.h>

class Stats {
private:
	double lastTime = glfwGetTime();
	int nbFrames = 0;
public:
	void printFPS() {
		
		// Measure speed
		double currentTime = glfwGetTime();
		nbFrames++;

		// If last prinf() was more than 1 sec ago printf and reset timer
		if (currentTime - lastTime >= 1.0) {
			printf("%f ms/frame\n", 1000.0 / double(nbFrames));
			nbFrames = 0;
			lastTime += 1.0;
		}
	}
};