#include "../include/SortingVisualizer.h"

#include <random>
#include <iostream>

SortingVisualizer::SortingVisualizer(const std::vector<int> &arr)
	: sortingMethod(nullptr), drawingMethod(nullptr), arr(arr) {
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

void SortingVisualizer::increaseSpeed() {
	setSpeed(speed+1);
}

void SortingVisualizer::decreaseSpeed() {
	setSpeed(speed-1);
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
}

SortingVisualizer::~SortingVisualizer() {
	delete sortingMethod;
	delete drawingMethod;
}
