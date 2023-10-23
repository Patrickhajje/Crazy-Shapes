#pragma once
#include "Shape.h"
#include <vector>
#include "Line.h"
class Rectangle : public Shape
{
private:
	int mWidth;
	int mHeight;
	std::vector<Line> _Lines;
public:
	Rectangle(int Width, int Height, Point2D StartPt, ConsoleColor Color) 
		: Shape(StartPt, Color), mWidth(Width), mHeight(Height)
	{
		Point2D ep1(StartPt.x + Width, StartPt.y);
		Line line1(StartPt, ep1, Color);
		_Lines.push_back(line1);

		Point2D ep2(ep1.x, StartPt.y + Height);
		Line line2(ep1, ep2, Color);
		_Lines.push_back(line2);

		Point2D ep3(StartPt.x, ep2.y);
		Line line3(ep2, ep3, Color);
		_Lines.push_back(line3);

		Line line4(ep3, StartPt, Color);
		_Lines.push_back(line4);
	}


	int width() const
	{
		return mWidth;
	}
	void width(int newWidth)
	{
		mWidth = newWidth;
	}
	int height() const
	{
		return mHeight;
	}
	void height(int newHeight)
	{
		mHeight = newHeight;
	}

	void draw() override;
};

