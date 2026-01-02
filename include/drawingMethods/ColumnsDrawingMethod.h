#pragma once
#include <vector>

#include "../DrawingMethod.h"

class ColumnsDrawingMethod : public DrawingMethod {
public:
	explicit ColumnsDrawingMethod(const std::vector<int> &arr);

	int dataSize;

	void draw(const raylib::Window &window) override;

};
