#pragma once
#include <vector>

#include "../DrawingMethod.h"

class ColumnsDrawingMethod : public DrawingMethod {
public:
	explicit ColumnsDrawingMethod();
	void draw(const std::vector<int> &arr, const raylib::Window &window) override;

};
