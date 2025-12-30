#pragma once
#include <string>

#include "SortingVisualizer.h"
#include "raylib-cpp/Window.hpp"


class Simulation {
	bool shouldRun = false;
	raylib::Window window;
	SortingVisualizer visualizer = SortingVisualizer(nullptr);

	void mainLoop();

	void logic();

	void onInput() const;

	void draw();

public:
	Simulation(int width, int height, const std::string &title);

	void run();

	void stop();
};
