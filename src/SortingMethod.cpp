#include "../include/SortingMethod.h"
#include <random>

SortingMethod::SortingMethod(const std::vector<int> &arr)
	: arr(arr) {
}

void SortingMethod::incSpeed() {
	speed++;
}

void SortingMethod::decSpeed() {
	speed--;
	if (speed <= 0) { speed = 1; }
}


void SortingMethod::setSpeed(const int newSpeed) {
	this->speed = newSpeed;
}
