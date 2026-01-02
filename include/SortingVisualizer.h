#pragma once
#include "DrawingMethod.h"
#include "SortingMethod.h"

class SortingVisualizer {
public:
	explicit SortingVisualizer(const std::vector<int> &arr);

	~SortingVisualizer();

	void setSortingMethod(SortingMethod *sorting_method);

	void setDrawingMethod(DrawingMethod *drawing_method);

	void draw(const raylib::Window &window) const;

	void setSpeed(int newSpeed);

	void increaseSpeed();

	void decreaseSpeed();

	void nextStep();


	void shuffle();

	SortingMethod *sortingMethod;
	DrawingMethod *drawingMethod;

private:
	int speed = 1;
	std::vector<int> arr;
};
