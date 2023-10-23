#include <iostream>
#include "Console.h"
#include "Input.h"
#include <algorithm>
#include <memory>
#include "Shape.h"
#include "Point2D.h"
#include "Line.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include <memory>
#include "ShapeFactory.h"



int main()
{
	srand((unsigned int)time(NULL)); //seed the random # generator

	Console::ResizeWindow(150, 40);

	int menuSelection = 0;
	std::vector<std::string> menuOptions{ "1. Draw Shape", "2. Draw Line", "3. Draw Rectangle", "4. Draw Triangle",  "5. Draw Circle", "6. Draw Random Shapes", "7. Exit" };

	do
	{
		Console::Clear();
		menuSelection = Input::GetMenuSelection(menuOptions);
		Console::Clear();

		switch (menuSelection)
		{
		case 1:
		{
			Point2D p1(getRandom(0, Console::GetWindowWidth()), getRandom(0, Console::GetWindowHeight()));
			Shape newShape(p1,ConsoleColor::Red);

			newShape.draw();

			break;
		}
		case 2:
		{	
			Point2D startPt(getRandom(0, Console::GetWindowWidth()), getRandom(0, Console::GetWindowHeight()));
			Point2D endPt(getRandom(0, Console::GetWindowWidth()), getRandom(0, Console::GetWindowHeight()));
			Line newLine(startPt, endPt, ConsoleColor::Blue);
			newLine.draw();
			break;
		}
		case 3:
		{

			int x = getRandom(0, Console::GetWindowWidth());
			int y = getRandom(0, Console::GetWindowHeight());
			Point2D topLeft(x, y);
			
			int width = getRandom(0, Console::GetWindowWidth() - x);
			int height = getRandom(0, Console::GetWindowHeight() - y);

			Rectangle newRectangle(width, height, topLeft, ConsoleColor::Green);
			newRectangle.draw();
			break;
		}
		case 4:
		{
			Point2D p1(getRandom(0, Console::GetWindowWidth()), getRandom(0, Console::GetWindowHeight()));
			Point2D p2(getRandom(0, Console::GetWindowWidth()), getRandom(0, Console::GetWindowHeight()));
			Point2D p3(getRandom(0, Console::GetWindowWidth()), getRandom(0, Console::GetWindowHeight()));
			Triangle newTriangle(p1,p2,p3,ConsoleColor::Cyan);
			newTriangle.draw();
			break;
		}
		case 5:
		{
			
			int x = 0;
			int y = 0;
			int radius = getRandom(5, 15);
			x = getRandom(radius + 1, Console::GetWindowWidth() - (radius * 2) - 1);
			y = getRandom(radius + 1, Console::GetWindowHeight() - (radius * 2) - 1);
			
			
			Point2D centerPoint(x, y);
			
			Circle myCircle(radius, centerPoint, ConsoleColor::Magenta);
			myCircle.draw();
			std::cout << "x: " << x << ", " << "y: " << y << ", radius: " << radius<< ", " << Console::GetWindowWidth() - radius - 1 << ", " << Console::GetWindowHeight() - radius - 1;
			break;
		}
		case 6:
		{
			
			std::vector<std::unique_ptr<Shape>>shapes;

			for (int i = 0; i < 100; i++)
			{
				switch (getRandom(1,5))
				{
				case 1:
					shapes.push_back(ShapeFactory::randomLine());
					break;
				case 2:
					shapes.push_back(ShapeFactory::randomShape());
					break;
				case 3:
					shapes.push_back(ShapeFactory::randomCircle());
					break;
				case 4:
					shapes.push_back(ShapeFactory::randomTriangle());
					break;
				case 5:
					shapes.push_back(ShapeFactory::randomRectangle());
					break;
				default:
					break;
				}					
			}
			for (auto& Shape : shapes)
			{
				Shape->draw();
			}
		}
		default:
			break;
		}

		Input::PressEnter(true);

	} while (menuSelection != menuOptions.size());
}