#include "../../include/sortingMethods/BubbleSort.h"

#include <iostream>
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

int BubbleSort::next(const int steps) {
	for (int i = 0; i < steps; i++) {
		if (bubble_i >= arr.size() - 1) {
			return -1;
		}
		step++;
		if (arr[bubble_j] > arr[bubble_j + 1]) {
			if (step % soundSpeed == 0) {
				PlaySound(sounds[bubble_j]);
			}
			std::swap(arr[bubble_j], arr[bubble_j + 1]);
		}
		bubble_j++;
		if (bubble_j >= dataSize - bubble_i - 1) {
			bubble_j = 0;
			bubble_i++;
		}
	}
	return -1;
}

BubbleSort::BubbleSort(const std::vector<int> &arr)
	: SortingMethod(arr),
	  dataSize(arr.size()),
	  sounds(dataSize) {
	initSoundSamples();
}

BubbleSort::~BubbleSort() {
	for (int i = 0; i < dataSize; i++) {
		UnloadSound(sounds[i]);
	}
}

void BubbleSort::draw(const raylib::Window &window) {
	const auto fDataSize = static_cast<float>(dataSize);
	const auto windowHeight = static_cast<float>(window.GetHeight());
	const auto colWidth = static_cast<float>(window.GetWidth()) / fDataSize;
	for (int i = 0; i < dataSize; i++) {
		const float colorRatio = static_cast<float>(i) / fDataSize;
		DrawRectangle(static_cast<int>(static_cast<float>(i) * colWidth),
		              static_cast<int>(windowHeight * (1 - static_cast<float>(arr[i]) / fDataSize)),
		              static_cast<int>(colWidth + 1),
		              static_cast<int>(windowHeight),
		              Color(255,
		                    static_cast<unsigned char>(255.f * (1 - colorRatio)),
		                    static_cast<unsigned char>(255.f),
		                    255));
	}
}

void BubbleSort::shuffle() {
	std::ranges::shuffle(arr, std::default_random_engine());
	this->bubble_i = 0;
	this->bubble_j = 0;
	this->step = 0;
}

void BubbleSort::initSoundSamples() {
	for (int i = 1; i < dataSize; i++) {
		const float ratio = static_cast<float>(i) / dataSize;
		// const float hz = ratio * 5000.0f;
		const float hz = 10000.f * (2.f * static_cast<float>(i) / static_cast<float>(i + dataSize));
		sounds[i] = getSineSound(hz, 0.02f);
		SetSoundVolume(sounds[i], .1f);
	}
}
