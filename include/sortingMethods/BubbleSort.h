#pragma once
#include <raylib-cpp/Sound.hpp>

#include "../SortingMethod.h"

class BubbleSort : public SortingMethod {
public:
	static void sort(std::vector<int> &arr);

	explicit BubbleSort(const std::vector<int> &arr);

	~BubbleSort() override;

	void nextStep() override;

	void draw(const raylib::Window &window) override;

	void shuffle() override;

	void initSoundSamples();

private:
	size_t dataSize;
	int bubble_i = 0;
	int bubble_j = 0;
	int soundSpeed = 2000;
	std::vector<Sound> sounds;
};
