#include <ostream>
#include "raylib-cpp/Image.hpp"
#include "../include/Simulation.h"
#include <algorithm>
#include <random>

#include "../include/SoundUtils.h"
#include "../include/drawingMethods/ColumnsDrawingMethod.h"
#include "../include/drawingMethods/DisparityLoop.h"
#include "../include/mixerMethods/HyperbolicMixer.h"
#include "../include/sortingMethods/BubbleSort.h"

Simulation::Simulation(const int width, const int height, const std::string &title)
	: window(width, height, title) {
	window.SetIcon(raylib::Image("../resources/simulationVisualizerIcon.png"));
	window.SetTargetFPS(1500);

	InitAudioDevice();
	SetMasterVolume(1.f);

	std::vector<int> arr{};
	for (int i = 0; i < 100; i++) {
		arr.push_back(i);
	}

	visualizer = SortingVisualizer(arr);
	visualizer.setSortingMethod(new BubbleSort());
	visualizer.setDrawingMethod(new ColumnsDrawingMethod());
	visualizer.setMixerMethod(new HyperbolicMixer());
	visualizer.setSpeed(300);
}

void Simulation::mainLoop() {
	while (!window.ShouldClose()) {
		onInput();
		draw();
	}
}

void Simulation::onInput() {
	if (IsKeyDown(KEY_SPACE)) {
		visualizer.nextSteps();
	}
	if (IsKeyPressed(KEY_R)) {
		visualizer.shuffle();
	}


	if (IsKeyPressed(KEY_UP)) {
		visualizer.nextStep();
	}
	if (IsKeyPressed(KEY_S)) {
		visualizer.sort();
	}
	if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_RIGHT)) {
		visualizer.translateSpeed(100);
	} else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT)) {
		visualizer.increaseSpeed();
	}
	if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_LEFT)) {
		visualizer.translateSpeed(-100);
	} else if (IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT)) {
		visualizer.decreaseSpeed();
	}
	if (IsKeyPressed(KEY_F11)) {
		// TODO: FIX
		// ToggleFullscreen();
	}
}

void Simulation::draw() {
	window.BeginDrawing();
	window.ClearBackground(BLACK);
	DrawFPS(10, 10);
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
