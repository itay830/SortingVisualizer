#pragma once
#include "../DrawingMethod.h"

class DisparityLoop : public DrawingMethod{
public:
	void draw(const std::vector<int> &arr, const raylib::Window &window) override;
};



