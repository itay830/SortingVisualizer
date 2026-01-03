#pragma once
#include <raylib-cpp/Sound.hpp>

#include "../SortingMethod.h"

class BubbleSort : public SortingMethod {
public:
	static void sort(std::vector<int> &arr);

	explicit BubbleSort();

	~BubbleSort() override;

	void reset() override;

	int next(std::vector<int> &arr, const int steps) override;

	void initSoundSamples();

private:
	int bubble_i = 0;
	int bubble_j = 0;
};

