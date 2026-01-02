#include "../include/SortingMethod.h"
#include <random>

SortingMethod::SortingMethod(const std::vector<int> &arr)
	: arr(arr) {
}

void SortingMethod::shuffle() {
	std::ranges::shuffle(arr, std::default_random_engine()); // NOLINT(cert-msc51-cpp)
}
