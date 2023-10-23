#include "Line.h"
#include <math.h>
#include <iostream>

void Line::Plot(int x, int y)
{
	Console::SetCursorPosition(x, y);
	std::cout << " " << std::endl;
}

void Line::draw()
{
	Console::SetBackgroundColor(mColor);
	PlotLine(mStartPt.x,mStartPt.y, mEndpt.x, mEndpt.y);
	Console::Reset();
}

void Line::PlotLine(int x0, int y0, int x1, int y1)
{
	double dx = abs(x1 - x0);
	double sx = x0 < x1 ? 1 : -1;
	double dy = -abs(y1 - y0);
	double sy = y0 < y1 ? 1 : -1;
	double error = dx + dy;

	while (true)
	{
		Plot(x0, y0);
		if (x0 == x1 && y0 == y1)
		{
			break;
		}
		double e2 = 2 * error;
		if (e2 >= dy)
		{
			if (x0 == x1)
			{
				break;
			}
			error = error + dy;
			x0 = x0 + sx;
		}
		if (e2 <= dx)
		{
			if (y0 == y1)
			{
				break;
			}
			error = error + dx;
			y0 = y0 + sy;
		}
	}
}
