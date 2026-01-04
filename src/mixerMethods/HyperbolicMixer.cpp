#include "../../include/mixerMethods/HyperbolicMixer.h"

HyperbolicMixer::~HyperbolicMixer() {
	for (const Sound sound : sounds) {
		UnloadSound(sound);
	}
}



void HyperbolicMixer::playSound() {
}

void HyperbolicMixer::initSounds(const std::vector<int> &arr) {
}
