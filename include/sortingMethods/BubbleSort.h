#pragma once
#include "../SortingMethod.h"

class BubbleSort : public SortingMethod {
public:
	static void sort(std::vector<int> &arr);

	explicit BubbleSort(const std::vector<int> &arr);

	void nextStep() override;

	void draw(const raylib::Window &window) override;

private:
	int dataSize;
	int bubble_i = 0;
	int bubble_j = 0;
	int step = 0;
};
