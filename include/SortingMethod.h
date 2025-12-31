#pragma once
#include <vector>
#include <raylib-cpp/Window.hpp>

class SortingMethod {
public:
	int speed = 0;
	int step = 0;

	explicit SortingMethod(const std::vector<int> &arr);

	virtual ~SortingMethod() = default;

	virtual void nextStep() = 0;

	virtual void draw(const raylib::Window &window) = 0;

	virtual void shuffle() = 0;

	void incSpeed();

	void decSpeed();

	void setSpeed(int newSpeed);

	int getSpeed() const {
		return speed;
	}

protected:
	std::vector<int> arr;
};
