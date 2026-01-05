#pragma once
#include <string>
#include <raylib-cpp/AudioDevice.hpp>

#include "SortingVisualizer.h"
#include "raylib-cpp/Window.hpp"


class Simulation {
public:
	bool shouldRun = false;

	Simulation(int width, int height, const std::string &title);

	void run();

	void onInput();

	void stop();

	void draw();

private:
	raylib::Window window;
	SortingVisualizer visualizerColumns = SortingVisualizer({});
	SortingVisualizer visualizerCircle = SortingVisualizer({});
	int mode = 0;
	void mainLoop();
};
