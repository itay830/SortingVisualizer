#include <ostream>
#include "raylib-cpp/Image.hpp"
#include "../include/Simulation.h"
#include <algorithm>
#include <random>

#include "../include/SoundUtils.h"
#include "../include/drawingMethods/ColumnsDrawingMethod.h"
#include "../include/sortingMethods/BubbleSort.h"

Simulation::Simulation(const int width, const int height, const std::string &title)
	: window(width, height, title) {
	window.SetIcon(raylib::Image("../resources/simulationVisualizerIcon.png"));
	window.SetFullscreen(true);
	window.SetTargetFPS(1500);

	InitAudioDevice();
	SetMasterVolume(1.f);

	std::vector<int> arr{};
	for (int i = 0; i < 1000; i++) {
		arr.push_back(i);
	}

	visualizer = SortingVisualizer();
	visualizer.setDrawingMethod(new ColumnsDrawingMethod(arr));
	visualizer.setSortingMethod(new BubbleSort(arr));
	visualizer.setSpeed(1);
}

void Simulation::mainLoop() {
	while (!window.ShouldClose()) {
		onInput();
		draw();
	}
}

void Simulation::logic() {
}

void Simulation::onInput() {
	if (IsKeyDown(KEY_SPACE)) {
		visualizer.nextStep();
	}
	if (IsKeyPressed(KEY_R)) {
		visualizer.shuffle();
		PlaySound(getSineSound(200.0f + (0.75f) * 800.0f, 0.1f));
	}
	if (IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT)) {
		visualizer.increaseSpeed();
	}
	if (IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT)) {
		visualizer.decreaseSpeed();
	}
}

void Simulation::draw() {
	window.BeginDrawing();
	window.ClearBackground(BLACK);
	DrawFPS(10, 10);
	// visualizer.sortingMethod->draw(window);
	visualizer.draw(window);
	window.EndDrawing();
}

void Simulation::run() {
	shouldRun = true;
	this->mainLoop();
}

void Simulation::stop() {
	shouldRun = false;
}
