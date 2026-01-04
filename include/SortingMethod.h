#pragma once
#include <vector>

class SortingMethod {
public:
	explicit SortingMethod();

	virtual ~SortingMethod() = default;

	virtual void reset() = 0;

	/**
	 * @param arr
	 * @param steps
	 * @return the swapped value
	 */
	virtual int next(std::vector<int> &arr, int steps) = 0;
};
