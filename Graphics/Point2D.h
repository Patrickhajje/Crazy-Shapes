#pragma once
#include <string>

struct Point2D
{
	int x;
	int y;
	Point2D(int x, int y)
		: x(x), y(y) {}

	std::string to_string() {
		return std::to_string(x) + ", " + std::to_string(y);
	}
};
