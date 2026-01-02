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


	void stop();

private:
	raylib::Window window;
	raylib::AudioDevice audioDevice;
	SortingVisualizer visualizer = SortingVisualizer(nullptr);

	void mainLoop();

	void logic();

	void onInput() const;

	void draw();
};
