#pragma once
#include "Shape.h"
#include <vector>
#include "Line.h"
class Triangle : public Shape
{
private:
	Point2D mP2;
	Point2D mP3;
	std::vector<Line> _Lines;

public:
	Triangle(Point2D p1, Point2D p2, Point2D p3, ConsoleColor color)
		:Shape(p1, color), mP2(p2), mP3(p3)
	{
		Line line1(p1, p2, color);
		_Lines.push_back(line1);

		Line line2(p2, p3, color);
		_Lines.push_back(line2);

		Line line3(p3, p1, color);
		_Lines.push_back(line3);
	}

	Point2D P2 () const
	{
		return mP2;
	}
	void P2(Point2D newP2)
	{
		mP2 = newP2;
	}
	Point2D P3() const
	{
		return mP3;
	}
	void P3(Point2D newP3)
	{
		mP3 = newP3;
	}

	void draw() override;
};

