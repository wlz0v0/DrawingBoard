#include <graphics.h>
#include "colorPoint.h"

Color::Color() :
	red(0),
	green(0),
	blue(0)
{}

Color::Color(int red_, int green_, int blue_) :
	red(red_),
	green(green_),
	blue(blue_)
{}

Color& Color::operator=(const Color & right)
{
	if (this != &right)
	{
		red = right.red;
		green = right.green;
		blue = right.blue;
	}
	return *this;
}

void Color::setGraphColor()
{
	setcolor(EGERGB(red, green, blue));
	setfillcolor(EGERGB(red, green, blue));
}

Point::Point() :
	x(0),
	y(0)
{}

Point::Point(int x_, int y_) : 
	x(x_),
	y(y_)
{}

bool Point::operator>(const Point & pt_)
{
	if (x > pt_.x && y > pt_.y)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, Color& color)
{
	os << color.red << " " << color.green << " " << color.blue;
	return os;
}

std::istream& operator>>(std::istream& is, Color& color)
{
	is >> color.red >> color.green >> color.blue;
	return is;
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
