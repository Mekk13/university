#pragma once
#include <vector>
#include <algorithm>

template <typename T>
int findPositionOfElement(const std::vector<T>& vec , T elem) {
	auto it = std::find(vec.begin(), vec.end(), elem);
	if (it != vec.end())
		return static_cast<int>(std::distance(vec.begin(), it));
	return -1;
}
