#include "../../include/drawingMethods/DisparityLoop.h"
#include "raylib.h"

void DisparityLoop::draw(const std::vector<int> &arr, const raylib::Window &window) {
	const auto width = static_cast<float>(window.GetWidth());
	const auto height = static_cast<float>(window.GetHeight());
	const Vector2 center(width / 2, height / 2);
	const float radius = 0.9f * height / 2;
	const int dataSize = static_cast<int>(arr.size());
	const auto fDataSize = static_cast<float>(dataSize);
	for (int i = 0; i < dataSize; i++) {
		const float indexRatio = static_cast<float>(i) / fDataSize;
		const float valueRatio = static_cast<float>(arr[i]) / fDataSize;
		const float angle = 2.f * PI * indexRatio;
		const float distance =
				radius *
				(1 -
				 static_cast<float>(2 * std::min(2 * abs(i - arr[i]),
				                                 2 * abs(dataSize - i - arr[i])))
				 / fDataSize);
		DrawCircle(static_cast<int>(center.x + cosf(angle) * distance),
		           static_cast<int>(center.y + sinf(angle) * distance),
		           2.f,
		           Color(255,
		                 static_cast<unsigned char>(255.f * (1 - valueRatio)),
		                 static_cast<unsigned char>(255.f),
		                 255));
	}
}
