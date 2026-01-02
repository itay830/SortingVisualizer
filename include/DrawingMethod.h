#pragma once
#include <vector>
#include <raylib-cpp/Window.hpp>

class DrawingMethod {
public:
	explicit DrawingMethod();

	virtual ~DrawingMethod() = default;
	virtual void draw(const std::vector<int> &arr, const raylib::Window &window) = 0;
};
