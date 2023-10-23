#include "Shape.h"
#include <iostream>

void Shape::draw()
{
	Console::SetBackgroundColor(mColor);
	Console::SetCursorPosition(mStartPt.x,mStartPt.y);
	std::cout << " ";
	Console::Reset();
}
