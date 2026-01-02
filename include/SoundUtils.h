#pragma once
#include <vector>
#include "raylib.h"

inline Sound getSineSound(const float hz, const float dur) {
	constexpr int sampleRate = 44100;
	const int frameCount = static_cast<int>(sampleRate * dur);
	std::vector<short> samples(frameCount);
	for (int i = 0; i < frameCount; i++) {
		const float t = static_cast<float>(i) / static_cast<float>(sampleRate);
		constexpr float amplitude = 32000.0f;
		float envelope = 1.0f;
		constexpr int fadeFrames = 88;
		if (i < fadeFrames) envelope = static_cast<float>(i) / static_cast<float>(fadeFrames);
		if (i > frameCount - fadeFrames) envelope = static_cast<float>(frameCount - i) / fadeFrames;

		samples[i] = static_cast<short>(sinf(2.0f * PI * hz * t) * amplitude * envelope);
	}
	const Wave wave(
		static_cast<unsigned int>(frameCount),
		sampleRate,
		16, // 16-bit for 'short'
		1,  // Mono
		samples.data()
	);
	const Sound sound = LoadSoundFromWave(wave);
	return sound;
}