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
	window.SetTargetFPS(60);

	InitAudioDevice();
	SetMasterVolume(1.f);

	std::vector<int> arr{};
	for (int i = 0; i < 4000; i++) {
		arr.push_back(i);
	}

	visualizerColumns = SortingVisualizer(arr);
	visualizerColumns.setSortingMethod(new BubbleSort());
	visualizerColumns.setDrawingMethod(new ColumnsDrawingMethod());
	visualizerColumns.setMixerMethod(new HyperbolicMixer());
	visualizerColumns.setSpeed(300);

	visualizerCircle = SortingVisualizer(arr);
	visualizerCircle.setSortingMethod(new BubbleSort());
	visualizerCircle.setDrawingMethod(new DisparityLoop());
	visualizerCircle.setMixerMethod(new HyperbolicMixer());
	visualizerCircle.setSpeed(300);
}

void Simulation::mainLoop() {
	while (!window.ShouldClose()) {
		onInput();
		draw();
	}
}

void Simulation::onInput() {
	if (IsKeyDown(KEY_SPACE)) {
		visualizerColumns.nextSteps();
		visualizerCircle.nextSteps();
	}
	if (IsKeyPressed(KEY_R)) {
		visualizerColumns.shuffle();
		visualizerCircle.shuffle();
	}
	if (IsKeyPressed(KEY_ONE)) {
		mode = 1;
	}
	if (IsKeyPressed(KEY_TWO)) {
		mode = 2;
	}
	if (IsKeyPressed(KEY_THREE)) {
		mode = 3;
	}

	if (IsKeyPressed(KEY_UP)) {
		visualizerColumns.nextStep();
		visualizerCircle.nextStep();
	}
	if (IsKeyPressed(KEY_S)) {
		visualizerColumns.sort();
		visualizerCircle.sort();
	}
	if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_RIGHT)) {
		visualizerColumns.translateSpeed(100);
		visualizerCircle.translateSpeed(100);
	} else if (IsKeyPressed(KEY_RIGHT) || IsKeyPressedRepeat(KEY_RIGHT)) {
		visualizerColumns.increaseSpeed();
		visualizerCircle.increaseSpeed();
	}
	if (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_LEFT)) {
		visualizerColumns.translateSpeed(-100);
		visualizerCircle.translateSpeed(-100);
	} else if (IsKeyPressed(KEY_LEFT) || IsKeyPressedRepeat(KEY_LEFT)) {
		visualizerColumns.decreaseSpeed();
		visualizerCircle.decreaseSpeed();
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
	switch (mode) {
		case 1:
			visualizerColumns.draw(
				WindowParams(0, 0, window.GetWidth(), window.GetHeight()));
			break;
		case 2:
			visualizerCircle.draw(
				WindowParams(0, 0, window.GetWidth(), window.GetHeight()));
			break;
		case 3:
			visualizerColumns.draw(
				WindowParams(0, 0, window.GetWidth() / 2, window.GetHeight()));
			visualizerCircle.draw(
				WindowParams(window.GetWidth() / 2, 0, window.GetWidth() / 2, window.GetHeight()));
			break;
		default:
			visualizerColumns.draw(
				WindowParams(0, 0, window.GetWidth(), window.GetHeight()));
	}
	window.EndDrawing();
}

void Simulation::run() {
	shouldRun = true;
	this->mainLoop();
}

void Simulation::stop() {
	shouldRun = false;
}
