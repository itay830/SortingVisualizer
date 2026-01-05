#pragma once
#include "../DrawingMethod.h"

class DisparityLoop : public DrawingMethod{
public:
	void draw(const std::vector<int> &arr, const WindowParams &window) override;
};



