#include "../include/SortingVisualizer.h"

SortingVisualizer::SortingVisualizer(SortingMethod *sortingMethod)
	: sortingMethod(sortingMethod) {
}

SortingVisualizer::~SortingVisualizer() {
	// TODO: FIX the deletion of the abstract object!
	// delete sortingMethod;
}
