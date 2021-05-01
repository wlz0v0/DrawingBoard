#include <graphics.h>
#include "point.h"

Point::Point() :
	x(0),
	y(0)
{}

Point::Point(int x_, int y_) :
	x(x_),
	y(y_)
{}

Point::Point(const Point & rhs) :
	x(rhs.x),
	y(rhs.y)
{}

bool Point::operator>(const Point& rhs)
{
	if (x > rhs.x && y > rhs.y)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, Point& pt)
{
	os << pt.x << " " << pt.y;
	return os;
}

std::istream& operator>>(std::istream& is, Point& pt)
{
	is >> pt.x >> pt.y;
	return is;
}