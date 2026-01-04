#include "../../include/sortingMethods/BubbleSort.h"
#include <random>
#include "../../include/SoundUtils.h"

void BubbleSort::sort(std::vector<int> &arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		bool isSorted = true;
		for (int j = 0; j < arr.size() - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				isSorted = false;
			}
		}
		if (isSorted) {
			return;
		}
	}
}


int BubbleSort::next(std::vector<int> &arr, const int steps) {
	const int dataSize = static_cast<int>(arr.size());
	int stepsCounter = 0;
	int lastSwappedIndex = -1;
	while (stepsCounter < steps && bubble_i < arr.size() - 1) {
		if (arr[bubble_j] > arr[bubble_j + 1]) {
			stepsCounter++;
			lastSwappedIndex = bubble_j;
			std::swap(arr[bubble_j], arr[bubble_j + 1]);
		}
		bubble_j++;
		if (bubble_j >= dataSize - bubble_i - 1) {
			bubble_j = 0;
			bubble_i++;
		}
	}
	return lastSwappedIndex;
}


void BubbleSort::reset() {
	this->bubble_i = 0;
	this->bubble_j = 0;
}

void BubbleSort::initSoundSamples() {
}
