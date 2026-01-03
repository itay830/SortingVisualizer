#include "../../include/drawingMethods/DisparityLoop.h"
#include "raylib.h"

void DisparityLoop::draw(const std::vector<int> &arr, const raylib::Window &window) {
	const auto width = static_cast<float>(window.GetWidth());
	const auto height = static_cast<float>(window.GetHeight());
	const Vector2 center(width / 2, height / 2);
	const float radius = 0.9f * height / 2;
	const auto fDataSize = static_cast<float>(arr.size());

	for (int i = 0; i < arr.size(); i++) {
		const float colorRatio = static_cast<float>(i) / fDataSize;
		const float angle = 2.f * PI * static_cast<float>(i) / fDataSize;
		const float distance = radius * (1-static_cast<float>(abs(i - arr[i])) / fDataSize);
		DrawCircle(static_cast<int>(center.x + cos(angle) * distance),
		           static_cast<int>(center.y + sin(angle) * distance),
		           2.f,
		           Color(255,
							static_cast<unsigned char>(255.f * (1 - colorRatio)),
							static_cast<unsigned char>(255.f),
							255));
	}
}
