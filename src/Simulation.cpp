#include <ostream>
#include "raylib-cpp/Image.hpp"
#include "../include/Simulation.h"
#include <algorithm>
#include <iostream>
#include <random>
#include "../include/sortingMethods/BubbleSort.h"
#include "raylib-cpp/AudioDevice.hpp"

Simulation::Simulation(const int width, const int height, const std::string &title)
	: window(width, height, title),
	  audioDevice(raylib::AudioDevice(false)) {
	window.SetIcon(raylib::Image("../resources/simulationVisualizerIcon.png"));
	window.SetFullscreen(true);

	audioDevice.SetVolume(0.5f);

	std::vector<int> arr{};
	for (int i = 0; i < 1000; i++) {
		arr.push_back(i);
	}
	std::ranges::shuffle(arr, std::default_random_engine());
	visualizer = SortingVisualizer(new BubbleSort(arr));
	visualizer.sortingMethod->setSpeed(100);
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
	if (IsKeyDown(KEY_SPACE)) {
		visualizer.sortingMethod->nextStep();
	}
	if (IsKeyPressed(KEY_R)) {
		visualizer.sortingMethod->shuffle();
	}
	if (IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT)) {
		visualizer.sortingMethod->incSpeed();
	}
	if (IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT)) {
		visualizer.sortingMethod->decSpeed();
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
