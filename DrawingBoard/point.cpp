/****************************************************************
*																*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4															*
*                                                               *
*****************************************************************/

#include "point.h"
#include <graphics.h>
#include <stdexcept>

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

bool Point::operator>(const Point& rhs) const
{
	return (x > rhs.x && y > rhs.y);
}

Point Point::operator+(const Point& rhs)
{
	Point ret;
	ret.x = (x + rhs.x) / 2;
	ret.y = (y + rhs.y) / 2;
	return ret;
}

bool Point::operator==(const Point& rhs) const
{
	return (x == rhs.x && y == rhs.y);
}

bool Point::operator!=(const Point& rhs) const
{
	return !operator==(rhs);
}

int& Point::operator[](size_t index)
{
	if (index == 0)
		return x;
	else if (index == 1)
		return y;
	else
		throw std::out_of_range("Error index");
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