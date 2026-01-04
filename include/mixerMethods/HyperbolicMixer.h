#pragma once
#include "../MixerMethod.h"

class HyperbolicMixer : public MixerMethod{
public:
	~HyperbolicMixer() override;

	void playSound(const std::vector<int> &arr, int index) override;

	void initSounds(const std::vector<int> &arr) override;

	void unloadSounds() const;
};
