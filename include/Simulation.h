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

	void logic();


	void draw();

private:
	raylib::Window window;
	SortingVisualizer visualizer = SortingVisualizer();

	void mainLoop();
};
