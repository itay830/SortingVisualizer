#pragma once
#include "../SortingMethod.h"

class BubbleSort : public SortingMethod {
public:
	static void sort(std::vector<int> &arr);

	void reset() override;

	int next(std::vector<int> &arr, int steps) override;

	void initSoundSamples();

private:
	int bubble_i = 0;
	int bubble_j = 0;
};

