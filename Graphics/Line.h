#pragma once
#include "Shape.h"
class Line : public Shape
{
private:
	Point2D mEndpt;
public:
	Line(Point2D startPt, Point2D endPt, ConsoleColor color) 
		:Shape(startPt,color), mEndpt(endPt)
	{

	}

	Point2D Endpt() const
	{
		return mEndpt;
	}
	void Endpt(Point2D newEndpt)
	{
		mEndpt = newEndpt;
	}
	void draw() override;
	void PlotLine(int x0, int y0, int x1, int y1);
	void Plot(int x, int y);
};

