#pragma once
#include <vector>
#include <raylib-cpp/Window.hpp>

class SortingMethod {
public:
	int step = 0;

	explicit SortingMethod(const std::vector<int> &arr);

	virtual ~SortingMethod() = default;

	virtual int next(int steps) = 0;

	virtual void shuffle();

	virtual void draw(const raylib::Window &window) = 0;


protected:
	std::vector<int> arr;
};
