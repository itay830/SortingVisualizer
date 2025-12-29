#include "../include/Simulation.h"

Simulation::Simulation(const int width, const int height, const std::string &title)
	: window(width, height, title) {
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
	if (IsKeyPressed(KEY_ESCAPE)) {
		// this->stop();
	}
}


void Simulation::draw() {
	window.BeginDrawing();
	window.ClearBackground(BLACK);
	window.EndDrawing();
}

void Simulation::run() {
	shouldRun = true;
	this->mainLoop();
}

void Simulation::stop() {
	// window.ShouldClose();
	shouldRun = false;
}
