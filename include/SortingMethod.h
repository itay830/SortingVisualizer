#pragma once
#include <vector>
#include <raylib-cpp/Window.hpp>

class SortingMethod {
public:
	explicit SortingMethod(const std::vector<int> &arr);

	virtual ~SortingMethod() = default;

	int comparisons = 0;

	virtual void nextStep() = 0;

	virtual void draw(const raylib::Window &window);

protected:
	std::vector<int> arr;
};
