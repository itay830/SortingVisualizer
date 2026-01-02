#include <ostream>
#include "raylib-cpp/Image.hpp"
#include "../include/Simulation.h"
#include <algorithm>
#include <iostream>
#include <random>

#include "../include/SoundUtils.h"
#include "../include/sortingMethods/BubbleSort.h"
#include "raylib-cpp/AudioDevice.hpp"

Simulation::Simulation(const int width, const int height, const std::string &title)
	: window(width, height, title),
	  audioDevice(raylib::AudioDevice(true)) {
	window.SetIcon(raylib::Image("../resources/simulationVisualizerIcon.png"));
	window.SetFullscreen(true);
	window.SetTargetFPS(1500);
	InitAudioDevice();
	SetMasterVolume(1.f);
	// audioDevice.SetVolume(1.f);

	std::vector<int> arr{};
	for (int i = 0; i < 2500; i++) {
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
		const float hz = 200.0f + (static_cast<float>(200) / 250) * 800.0f;
		PlaySound(getSineSound(hz, 0.1f));
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
	visualizer.sortingMethod->draw(window);\
	DrawFPS(10, 10);
	window.EndDrawing();
}

void Simulation::run() {
	shouldRun = true;
	this->mainLoop();
}

void Simulation::stop() {
	shouldRun = false;
}
