#include "Triangle.h"

void Triangle::draw()
{
	for (auto i = _Lines.begin(); i < _Lines.end(); i++)
	{
		(*i).draw();
	}

}
