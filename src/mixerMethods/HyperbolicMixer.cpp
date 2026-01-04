#include "../../include/mixerMethods/HyperbolicMixer.h"
#include "../../include/SoundUtils.h"
HyperbolicMixer::~HyperbolicMixer() {
	unloadSounds();
}


void HyperbolicMixer::playSound(const std::vector<int> &arr, const int index) {
	if (index < 0) {
		return;
	}
	PlaySound(sounds[arr[index]]);
}

void HyperbolicMixer::initSounds(const std::vector<int> &arr) {
	unloadSounds();
	sounds.clear();
	sounds.resize(arr.size());
	const auto dataSize = static_cast<int>(arr.size());
	for (int i = 0; i < dataSize; i++) {
		const float hz = 10000.f * (2.f * static_cast<float>(i) / static_cast<float>(i + dataSize));
		sounds[i] = getSineSound(hz, 0.02f);
		SetSoundVolume(sounds[i], .1f);
	}
}

void HyperbolicMixer::unloadSounds() const {
	for (const Sound sound : sounds) {
		UnloadSound(sound);
	}
}
