#include "../../include/drawingMethods/ColumnsDrawingMethod.h"

ColumnsDrawingMethod::ColumnsDrawingMethod() = default;

void ColumnsDrawingMethod::draw(const std::vector<int> &arr, const WindowParams &window) {
	const int dataSize = static_cast<int>(arr.size());
	const auto fDataSize = static_cast<float>(dataSize);
	const auto windowHeight = static_cast<float>(window.h);
	const auto colWidth = static_cast<float>(window.w) / fDataSize;
	for (int i = 0; i < dataSize; i++) {
		const float colorRatio = static_cast<float>(i) / fDataSize;
		const int yPos = static_cast<int>(windowHeight * (1 - static_cast<float>(arr[i]) / fDataSize));
		DrawRectangle(window.x + static_cast<int>(static_cast<float>(i) * colWidth),
		              window.y + yPos,
		              static_cast<int>(colWidth + 1),
		              static_cast<int>(windowHeight) - yPos,
		              Color(255,
		                    static_cast<unsigned char>(255.f * (1 - colorRatio)),
		                    static_cast<unsigned char>(255.f),
		                    255));
	}
}
