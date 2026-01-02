#pragma once
#include "DrawingMethod.h"
#include "SortingMethod.h"

class SortingVisualizer {
public:
	explicit SortingVisualizer();

	~SortingVisualizer();

	void setSortingMethod(SortingMethod *sorting_method);

	void setDrawingMethod(DrawingMethod *drawing_method);

	void draw(const raylib::Window &window);

	void setSpeed(int newSpeed);

	void increaseSpeed();

	void decreaseSpeed();

	void nextStep() const;


	void shuffle() const;

	SortingMethod *sortingMethod;
	DrawingMethod *drawingMethod;

private:
	int speed = 1;
	std::vector<int> arr;
};
