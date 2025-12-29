#pragma once
#include <string>
#include "raylib-cpp/Window.hpp"


class Simulation {
	bool shouldRun = false;
	raylib::Window window;

public:
	Simulation(int width, int height, const std::string &title);

	void mainLoop();

	void logic();

	void onInput();

	void draw();


	void run();

	void stop();
};
