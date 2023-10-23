#pragma once
#include "Point2D.h"
#include "Console.h"

class Shape
{
protected:
	Point2D mStartPt;
	ConsoleColor mColor;

public:
	Shape(Point2D startPt, ConsoleColor Color)
		:mStartPt(startPt), mColor(Color)
	{

	}
	Shape(int x, int y, ConsoleColor Color) :mStartPt(x,y), mColor(Color)
	{

	}
	Point2D StartPt() const 
	{
		return mStartPt;
	}
	void StartPt(Point2D newStartPt)
	{
		mStartPt = newStartPt;
	}
	ConsoleColor Color() const
	{
		return mColor;
	}
	void Color(ConsoleColor newColor)
	{
		mColor = newColor;
	}
	virtual void draw();
};

