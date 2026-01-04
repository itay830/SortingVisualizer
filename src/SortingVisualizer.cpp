#include "../include/SortingVisualizer.h"
#include "../include/sortingMethods/BubbleSort.h"
#include <random>

SortingVisualizer::SortingVisualizer(const std::vector<int> &arr)
	: sortingMethod(nullptr),
	  drawingMethod(nullptr),
	  // shuffleSound(getSineSound(200.0f + (0.75f) * 800.0f, 0.1f)),
	  arr(arr) {
}

void SortingVisualizer::setSortingMethod(SortingMethod *sorting_method) {
	this->sortingMethod = sorting_method;
}

void SortingVisualizer::setDrawingMethod(DrawingMethod *drawing_method) {
	this->drawingMethod = drawing_method;
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

void SortingVisualizer::draw(const raylib::Window &window) const {
	DrawText(("Speed: " + std::to_string(speed)).c_str(), 10, 40, 25, WHITE);
	DrawText(("Step: " + std::to_string(0)).c_str(), 10, 70, 25, WHITE);
	drawingMethod->draw(arr, window);
}

void SortingVisualizer::nextSteps() {
	sortingMethod->next(arr, speed);
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
	// UnloadSound(shuffleSound);
	delete sortingMethod;
	delete drawingMethod;
}
