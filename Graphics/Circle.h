#pragma once
#include "Shape.h"
class Circle : public Shape
{
private:
	int mRadius;

public:
	Circle(int radius, Point2D startPt, ConsoleColor color) 
		:Shape (startPt, color), mRadius(radius)
	{

	}

	int Radius() const 
	{
		return mRadius;
	}
	void Radius(int newRadius)
	{
		mRadius = newRadius;
	}

	void draw() override;
	void Plot(int x, int y);
	void DrawCirclePoints(int xc, int yc, int x, int y);
	void DrawCircle(int xc, int yc, int r);
};

