#pragma once
#include "Point2D.h"
#include "Console.h"
#include "Shape.h"
#include "Line.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

static int getRandom(int min, int max) {

	return  ((rand() % max) + min);
}
class ShapeFactory : public Shape
{
private:

public:

	static Point2D randomPoint()
	{
		return Point2D(getRandom(0, Console::GetWindowWidth()), getRandom(0, Console::GetWindowHeight()));
	}
	static ConsoleColor randomColor()
	{
		return ConsoleColor(getRandom(1,9));
	}
	static std::unique_ptr<Shape> randomShape()
	{
		return std::make_unique<Shape>(getRandom(0, Console::GetWindowWidth()), getRandom(0, Console::GetWindowHeight()), randomColor());
	}
	static std::unique_ptr<Line> randomLine()
	{
		return std::make_unique<Line>(randomPoint(), randomPoint(), randomColor());
	}
	static std::unique_ptr<Rectangle> randomRectangle()
	{
		int x = getRandom(0, Console::GetWindowWidth());
		int y = getRandom(0, Console::GetWindowHeight());
		Point2D topLeft(x, y);

		int width = getRandom(0, Console::GetWindowWidth() - x);
		int height = getRandom(0, Console::GetWindowHeight() - y);

		return std::make_unique<Rectangle>(width, height, topLeft, randomColor());
	}
	static std::unique_ptr<Triangle> randomTriangle()
	{
		Point2D p1(getRandom(0, Console::GetWindowWidth()), getRandom(0, Console::GetWindowHeight()));
		Point2D p2(getRandom(0, Console::GetWindowWidth()), getRandom(0, Console::GetWindowHeight()));
		Point2D p3(getRandom(0, Console::GetWindowWidth()), getRandom(0, Console::GetWindowHeight()));
		return std::make_unique<Triangle>(p1, p2, p3, randomColor());
	}
	static std::unique_ptr<Circle> randomCircle()
	{
		int x = 0;
		int y = 0;
		int radius = getRandom(5, 15);
		x = getRandom(radius + 1, Console::GetWindowWidth() - (radius * 2) - 1);
		y = getRandom(radius + 1, Console::GetWindowHeight() - (radius * 2) - 1);


		Point2D centerPoint(x, y);

		return std::make_unique<Circle>(radius, centerPoint,randomColor());

	}
};