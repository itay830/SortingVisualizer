#pragma once
#include <vector>
#include <raylib-cpp/Window.hpp>

#include "WindowParams.h"

class DrawingMethod {
public:
	explicit DrawingMethod();

	virtual ~DrawingMethod() = default;
	virtual void draw(const std::vector<int> &arr, const WindowParams &window) = 0;
};
