#pragma once
#include "../MixerMethod.h"

class HyperbolicMixer : public MixerMethod{
public:
	~HyperbolicMixer() override;

	void playSound() override;

	void initSounds(const std::vector<int> &arr) override;
};
