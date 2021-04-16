#include <graphics.h>
#include <iostream>
#include <cmath>
#include <iterator>
#include "shape.h"

using std::endl;
std::vector<Shape*> Shape::shapes;

Shape::Shape(int type_) :
	color(),
	isFill(false),
	type(type_),
	pt1(),
	pt2()
{}

void Shape::setColor(const Color& color_)
{
	color = color_;
}

void Shape::setIsFill(bool isFill_)
{
	isFill = isFill_;
}

void Shape::setPt1(int x_, int y_)
{
	pt1.x = x_;
	pt1.y = y_;
}

void Shape::setPt2(int x_, int y_)
{
	pt2.x = x_;
	pt2.y = y_;
}

Color Shape::getColor()
{
	return color;
}

int Shape::getType()
{
	return type;
}

Point Shape::getPt1()
{
	return pt1;
}

Point Shape::getPt2()
{
	return pt2;
}

size_t Shape::getShapeCount()
{
	return Shape::shapes.size();
}

Line::Line() :
	Shape(typeLine)
{}

void Line::drawShape()
{
	color.setGraphColor();
	setviewport(500, 20, 1440, 720);
	line(pt1.x, pt1.y, pt2.x, pt2.y);
	setviewport(0, 0, 1440, 720);
}

Circle::Circle() :
	Shape(typeCircle)
{}

//半径利用两点之间的距离计算
void Circle::drawShape()
{
	int radius = static_cast<int>(
		sqrt
		(pow(pt2.x - pt1.x, 2) +
		pow(pt2.y - pt1.y, 2))
		);
	color.setGraphColor();
	setviewport(500, 20, 1440, 720);
	if (isFill)
		pieslice(pt1.x, pt1.y, 0, 360, radius);
	else
		circle(pt1.x, pt1.y, radius);
	setviewport(0, 0, 1440, 720);
}

Rectangle_::Rectangle_() :
	Shape(typeRectangle)
{}

void Rectangle_::drawShape()
{
	color.setGraphColor();
	setviewport(500, 20, 1440, 720);
	if (isFill)
		bar(pt1.x, pt1.y, pt2.x, pt2.y);
	else
		rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
	setviewport(0, 0, 1440, 720);
}

std::ostream& operator<<(std::ostream& os, Shape& shape)
{
	os << shape.type << endl
		<< shape.isFill << endl
		<< shape.color << endl
		<< shape.pt1 << endl
		<< shape.pt2 << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Shape& shape)
{
	is >> shape.type >> shape.isFill >> shape.color
		>> shape.pt1 >> shape.pt2;
	return is;
}

std::ostream& operator<<(std::ostream& os, Line& line)
{
	os << line.type << endl
		<< line.isFill << endl
		<< line.color << endl
		<< line.pt1 << endl
		<< line.pt2 << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Line& line)
{
	is >> line.type >> line.isFill >> line.color
		>> line.pt1 >> line.pt2;
	return is;
}

std::ostream& operator<<(std::ostream& os, Circle& circle)
{
	os << circle.type << endl
		<< circle.isFill << endl
		<< circle.color << endl
		<< circle.pt1 << endl
		<< circle.pt2 << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Circle& circle)
{
	is >> circle.type >> circle.isFill >> circle.color
		>> circle.pt1 >> circle.pt2;
	return is;
}

std::ostream& operator<<(std::ostream& os, Rectangle_& rectangle)
{
	os << rectangle.type << endl
		<< rectangle.isFill << endl
		<< rectangle.color << endl
		<< rectangle.pt1 << endl
		<< rectangle.pt2 << endl;
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle_& rectangle)
{
	is >> rectangle.type >> rectangle.isFill >> rectangle.color
		>> rectangle.pt1 >> rectangle.pt2;
	return is;
}

void drawAShape(Shape& shape, bool isFill_)
{
	mouse_msg msg1, msg2;
	shape.setIsFill(isFill_);
	shape.setColor(Color(EGEGET_R(getcolor()),
		EGEGET_G(getcolor()),
		EGEGET_B(getcolor())));
	while (true)
	{
		msg1 = getmouse();
		if (msg1.is_left() && msg1.is_down())
		{
			shape.setPt1(msg1.x - 500, msg1.y - 20); //坐标换算
			if (shape.getPt1() > Point(0, 0))
				break;
			xyprintf(0, 510, "选点必须在可画区域内！");
		}
	}
	while (true)
	{
		msg2 = getmouse();
		if (msg2.is_left() && msg2.is_down())
		{
			shape.setPt2(msg2.x - 500, msg2.y - 20); //坐标换算
			if (shape.getPt2() > Point(0, 0))
				break;
			xyprintf(0, 510, "选点必须在可画区域内！");
		}
	}
	shape.drawShape();
	Shape::shapes.push_back(&shape);
}

void drawShapes()
{
	for (auto it = Shape::shapes.begin(); it != Shape::shapes.end(); it++)
	{
		(*it)->drawShape();
	}
}

void clearShapes()
{
	for (auto it = Shape::shapes.begin(); it != Shape::shapes.end(); it++)
	{
		delete *it;
	}
	Shape::shapes.clear();
}
