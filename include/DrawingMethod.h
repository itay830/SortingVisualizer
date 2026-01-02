#pragma once
#include <vector>
#include <raylib-cpp/Window.hpp>

class DrawingMethod {
public:
	explicit DrawingMethod(const std::vector<int> &arr);

	virtual ~DrawingMethod() = default;
	virtual void draw(const raylib::Window &window) = 0;

	std::vector<int> arr;

};
