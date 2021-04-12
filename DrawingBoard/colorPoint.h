#ifndef COLOR_POINT_H
#define COLOR_POINT_H
#include <iostream>

class Color
{
public:
	int red;
	int green;
	int blue;

	Color();
	Color(int red_, int green_, int blue_);
	Color& operator=(const Color& right);
	void setGraphColor();
	friend std::ostream& operator<<(std::ostream& os, Color& color);
	friend std::istream& operator>>(std::istream& is, Color& color);
};

class Point
{
public:
	int x;
	int y;

	Point();
	Point(int x_, int y_);
	friend std::ostream& operator<<(std::ostream& os, Point& pt);
	friend std::istream& operator>>(std::istream& is, Point& pt);
	bool operator>(const Point& pt_);
};

#endif // COLOR_POINT_H