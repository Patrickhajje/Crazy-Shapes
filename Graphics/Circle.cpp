#include "Circle.h"
#include<iostream>

void Circle::draw()
{
	Console::SetBackgroundColor(mColor);
	DrawCircle(mStartPt.x, mStartPt.y, mRadius);
	Console::Reset();
}

void Circle::Plot(int x, int y)
{
	Console::SetCursorPosition(x, y);
	std::cout << " " << std::endl;
}

void Circle::DrawCirclePoints(int xc, int yc, int x, int y)
{
	Plot(xc + x, yc + y);
	Plot(xc - x, yc + y);
	Plot(xc + x, yc - y);
	Plot(xc - x, yc - y);
	Plot(xc + y, yc + x);
	Plot(xc - y, yc + x);
	Plot(xc + y, yc - x);
	Plot(xc - y, yc - x);
}

void Circle::DrawCircle(int xc, int yc, int r)
{
	int x = 0;
	int y = r;
	int d = 3 - 2 * r;
	DrawCirclePoints(xc, yc, x, y);
	while (y >= x)
	{
		x = x + 1;
		if (d > 0)
		{
			y = y - 1;
			d = d + 4 * (x - y) + 10;
		}
		else
		{
			d = d + 4 * x + 6;
			DrawCirclePoints(xc, yc, x, y);
		}
	}
}
