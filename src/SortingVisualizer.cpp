#include "../include/SortingVisualizer.h"

#include <random>

#include "../include/sortingMethods/BubbleSort.h"

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

void SortingVisualizer::nextStep() {
	sortingMethod->next(arr, speed);
}

void SortingVisualizer::draw(const raylib::Window &window) const {
	drawingMethod->draw(arr, window);
}

void SortingVisualizer::shuffle() {
	sortingMethod->reset();
	std::ranges::shuffle(arr, std::default_random_engine());
	// PlaySound(shuffleSound);
}

SortingVisualizer::~SortingVisualizer() {
	// UnloadSound(shuffleSound);
	delete sortingMethod;
	delete drawingMethod;
}
