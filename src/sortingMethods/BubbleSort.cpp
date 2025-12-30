#include "../../include/sortingMethods/BubbleSort.h"

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

void BubbleSort::nextStep() {
	if (bubble_i >= arr.size() - 1) {
		return;
	}
	step++;
	if (arr[bubble_j] > arr[bubble_j + 1]) {
		std::swap(arr[bubble_j], arr[bubble_j + 1]);
	}
	bubble_j++;
	if (bubble_j >= arr.size() - bubble_i - 1) {
		bubble_j = 0;
		bubble_i++;
	}
}

BubbleSort::BubbleSort(const std::vector<int> &arr)
	: SortingMethod(arr),
	  dataSize(arr.size()) {
}

void BubbleSort::draw(const raylib::Window &window) {
	DrawText(std::to_string(step).c_str(), 10, 45, 55, WHITE);
	const double windowHeight = window.GetHeight();
	const double colWidth = static_cast<double>(window.GetWidth()) / dataSize;
	for (int i = 0; i < dataSize; i++) {
		DrawRectangle(i * colWidth,
		              windowHeight * (1 - arr[i] / static_cast<float>(dataSize)),
		              colWidth,
		              windowHeight,
		              Color(25,125, 255 * static_cast<double>(i) / static_cast<double>(dataSize),255));
	}
}
