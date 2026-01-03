#pragma once
#include <vector>

#include "raylib.h"

class MixerMethod {
public:
	virtual ~MixerMethod() = default;

	virtual void playSound() = 0;

	virtual void initSounds(const std::vector<int> &arr) = 0;

protected:
	Sound getSound(int hz, int dur);
	std::vector<Sound> sounds;
};
