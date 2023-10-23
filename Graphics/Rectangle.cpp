#include "Rectangle.h"

void Rectangle::draw()
{
	for (auto i =  _Lines.begin(); i < _Lines.end(); i++)
	{
		(*i).draw();
	}
}
