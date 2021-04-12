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

bool Point::operator>(const Point& pt_)
{
	if (x > pt_.x && y > pt_.y)
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