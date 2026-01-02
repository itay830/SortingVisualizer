#pragma once
#include "SortingMethod.h"

class SortingVisualizer {
public:
	explicit SortingVisualizer(SortingMethod *sortingMethod);

	SortingMethod *sortingMethod;

	~SortingVisualizer();
};
