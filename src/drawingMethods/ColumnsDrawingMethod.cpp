#include "../../include/drawingMethods/ColumnsDrawingMethod.h"

ColumnsDrawingMethod::ColumnsDrawingMethod(const std::vector<int> &arr)
	: DrawingMethod(arr),
	  dataSize(arr.size()) {
}

void ColumnsDrawingMethod::draw(const raylib::Window &window) {
	const auto fDataSize = static_cast<float>(dataSize);
	const auto windowHeight = static_cast<float>(window.GetHeight());
	const auto colWidth = static_cast<float>(window.GetWidth()) / fDataSize;
	for (int i = 0; i < dataSize; i++) {
		const float colorRatio = static_cast<float>(i) / fDataSize;
		DrawRectangle(static_cast<int>(static_cast<float>(i) * colWidth),
		              static_cast<int>(windowHeight * (1 - static_cast<float>(arr[i]) / fDataSize)),
		              static_cast<int>(colWidth + 1),
		              static_cast<int>(windowHeight),
		              Color(255,
		                    static_cast<unsigned char>(255.f * (1 - colorRatio)),
		                    static_cast<unsigned char>(255.f),
		                    255));
	}
}
