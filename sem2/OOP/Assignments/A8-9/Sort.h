#pragma once
#include <vector>
#include "Comparator.h"

template <typename T>
void genericSort(std::vector<T>& vec, Comparator<T>& comp) {
	std::sort(vec.begin(), vec.end(), [&comp](const T& a, const T& b) {
		return comp.compare(a, b);
	});
}