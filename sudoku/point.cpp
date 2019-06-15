#include "point.h"

point::point():x(0),y(0){}

point::point(int _x, int _y)
{
	x = _x;
	y = _y;
}

void point::set_x(const int _x)
{
	x = _x;
}

void point::set_y(const int _y)
{
	y = _y;
}

int point::get_x() const
{
	return x;
}

int point::get_y() const
{
	return y;
}
