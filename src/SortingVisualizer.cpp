#include "../include/SortingVisualizer.h"

#include <iostream>

SortingVisualizer::SortingVisualizer()
	: sortingMethod(nullptr), drawingMethod(nullptr) {
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

void SortingVisualizer::nextStep() const {
	sortingMethod->next(speed);
}

void SortingVisualizer::draw(const raylib::Window &window) {
	drawingMethod->draw(window);
}

void SortingVisualizer::shuffle() const {
	sortingMethod->shuffle();
}

SortingVisualizer::~SortingVisualizer() {
	delete sortingMethod;
	delete drawingMethod;
}
