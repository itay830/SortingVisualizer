#include "../include/SortingVisualizer.h"
#include "../include/sortingMethods/BubbleSort.h"
#include <random>

#include "../include/WindowParams.h"

SortingVisualizer::SortingVisualizer(const std::vector<int>& arr)
	: sortingMethod(nullptr),
	  drawingMethod(nullptr),
	  mixerMethod(nullptr),
	  arr(arr) {
}

void SortingVisualizer::setSortingMethod(SortingMethod *sorting_method) {
	this->sortingMethod = sorting_method;
}

void SortingVisualizer::setDrawingMethod(DrawingMethod *drawing_method) {
	delete this->drawingMethod;
	this->drawingMethod = drawing_method;
}

void SortingVisualizer::setMixerMethod(MixerMethod *mixer_method) {
	mixerMethod = mixer_method;
	mixerMethod->initSounds(arr);
}

void SortingVisualizer::setSpeed(const int newSpeed) {
	if (newSpeed <= 0) {
		this->speed = 1;
		return;
	}
	this->speed = newSpeed;
}

void SortingVisualizer::sort() {
	BubbleSort::sort(arr);
}

void SortingVisualizer::increaseSpeed() {
	setSpeed(speed + 1);
}

void SortingVisualizer::decreaseSpeed() {
	setSpeed(speed - 1);
}

void SortingVisualizer::translateSpeed(const int translation) {
	setSpeed(speed + translation);
}

void SortingVisualizer::draw(const WindowParams &window) const {
	DrawText(("Speed: " + std::to_string(speed)).c_str(), window.x + 10, window.y + 40, 25, WHITE);
	DrawText(("Step: " + std::to_string(0)).c_str(), window.x + 10, window.y + 70, 25, WHITE);
	drawingMethod->draw(arr, window);
}

void SortingVisualizer::nextSteps() {
	mixerMethod->playSound(arr, sortingMethod->next(arr, speed));
}

void SortingVisualizer::nextSteps(const int steps) {
	sortingMethod->next(arr, steps);
}

void SortingVisualizer::nextStep() {
	sortingMethod->next(arr, 1);
}

void SortingVisualizer::shuffle() {
	sortingMethod->reset();
	std::random_device rd;
	std::mt19937 g(rd());
	std::ranges::shuffle(arr, g);

	// std::ranges::shuffle(arr, std::default_random_engine());
	// PlaySound(shuffleSound);
}

SortingVisualizer::~SortingVisualizer() {
	delete mixerMethod;
	delete sortingMethod;
	delete drawingMethod;
}
