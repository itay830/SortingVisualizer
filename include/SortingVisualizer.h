#pragma once
#include "DrawingMethod.h"
#include "MixerMethod.h"
#include "SortingMethod.h"
#include "SoundUtils.h"

class SortingVisualizer {
public:
	explicit SortingVisualizer(const std::vector<int>& arr);

	~SortingVisualizer();

	void setSortingMethod(SortingMethod *sorting_method);

	void setDrawingMethod(DrawingMethod *drawing_method);

	void setMixerMethod(MixerMethod *mixer_method);

	void draw(const WindowParams &window) const;

	void setSpeed(int newSpeed);

	void sort();

	void increaseSpeed();

	void decreaseSpeed();

	void translateSpeed(int translation);

	void nextSteps();

	void nextSteps(int steps);

	void nextStep();

	void shuffle();

	SortingMethod *sortingMethod;
	DrawingMethod *drawingMethod;
	MixerMethod *mixerMethod;

private:
	std::vector<int> arr;
	int speed = 1;
};
