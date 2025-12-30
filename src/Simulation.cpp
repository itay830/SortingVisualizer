#include <ostream>
#include "raylib-cpp/Image.hpp"
#include "../include/Simulation.h"

#include <algorithm>
#include <random>

#include "../include/sortingMethods/BubbleSort.h"

Simulation::Simulation(const int width, const int height, const std::string &title)
	: window(width, height, title) {
	window.SetFullscreen(true);
	std::vector<int> arr{};
	for (int i = 0; i < 1000; i++) {
		arr.push_back(i);
	}
	std::ranges::shuffle(arr, std::default_random_engine());
	visualizer = SortingVisualizer(new BubbleSort(arr));
	// window.SetTargetFPS(60);
	window.SetIcon(raylib::Image("../resources/simulationVisualizerIcon.png"));
}

void Simulation::mainLoop() {
	while (!window.ShouldClose()) {
		onInput();
		draw();
	}
}

void Simulation::logic() {
}

void Simulation::onInput() const {
	if (IsKeyPressed(KEY_SPACE)) {
		visualizer.sortingMethod->nextStep();
	}
	if (IsKeyDown(KEY_SPACE)) {
		for (int i = 0; i < 25; i++) {
		visualizer.sortingMethod->nextStep();

		}
	}
}


void Simulation::draw() {
	window.BeginDrawing();
	window.ClearBackground(BLACK);
	visualizer.sortingMethod->draw(window);
	window.EndDrawing();
}

void Simulation::run() {
	shouldRun = true;
	this->mainLoop();
}

void Simulation::stop() {
	shouldRun = false;
}
