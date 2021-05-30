#include "shape.h"
#include <graphics.h>
#include <iostream>
#include <cmath>
#include <iterator>
#include <fstream>
#include <stdexcept>

using std::endl;
std::vector<Shape*> Shape::shapes;

Shape::Shape(int type_) :
	color(),
	isFill(false),
	type(type_),
	pt1(),
	pt2()
{}

Shape::Shape(const Color & color_,
	const Point & pt1_,
	const Point & pt2_,
	bool isFill_,
	int type_) :
	color(color_),
	pt1(pt1_),
	pt2(pt2_),
	isFill(isFill_),
	type(type_)
{}

void Shape::setType(int type_)
{
	type = type_;
}

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

Color Shape::getColor() const
{
	return color;
}

int Shape::getType() const
{
	return type;
}

Point Shape::getPt1() const
{
	return pt1;
}

Point Shape::getPt2() const
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

Line::Line(const Line & rhs) :
	Shape(rhs.color,
		rhs.pt1,
		rhs.pt2,
		false,
		typeLine)
{}

Line::Line(const Point & pt1, const Point & pt2) :
	Shape(Color(), pt1, pt2, false, typeLine)
{}

void Line::drawShape()
{
	color.setGraphColor();
	setviewport(500, 20, 1440, 720);
	line(pt1.x, pt1.y, pt2.x, pt2.y);
	setviewport(0, 0, 1440, 720);
}

bool Line::operator<(const Line& rhs) const
{
	return sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)) <
		sqrt(pow((rhs.pt2.x - rhs.pt1.x), 2) + pow((rhs.pt2.y - rhs.pt1.y), 2));
}

bool Line::operator<=(const Line& rhs) const
{
	return sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)) <=
		sqrt(pow((rhs.pt2.x - rhs.pt1.x), 2) + pow((rhs.pt2.y - rhs.pt1.y), 2));
}

bool Line::operator>(const Line& rhs) const
{
	return sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)) > 
		sqrt(pow((rhs.pt2.x - rhs.pt1.x), 2) + pow((rhs.pt2.y - rhs.pt1.y), 2));
}

bool Line::operator>=(const Line& rhs) const
{
	return sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)) >=
		sqrt(pow((rhs.pt2.x - rhs.pt1.x), 2) + pow((rhs.pt2.y - rhs.pt1.y), 2));
}

bool Line::operator==(const Line& rhs) const
{
	return sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)) ==
		sqrt(pow((rhs.pt2.x - rhs.pt1.x), 2) + pow((rhs.pt2.y - rhs.pt1.y), 2));
}

bool Line::operator!=(const Line& rhs) const
{
	return sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)) !=
		sqrt(pow((rhs.pt2.x - rhs.pt1.x), 2) + pow((rhs.pt2.y - rhs.pt1.y), 2));
}

Line& Line::operator=(const Line& rhs) 
{
	color = rhs.color;
	isFill = rhs.isFill;
	type = rhs.type;
	pt1 = rhs.pt1;
	pt2 = rhs.pt2;
	return *this;
	///*deep copy
	//下面所有拷贝得到的变量都应该是指针类型*/
	//if (*this != rhs)
	//{
	//	delete color;
	//	delete isFill;
	//	delete type;
	//	delete pt1;
	//	delete pt2;
	//	color = new Color(rhs.color);
	//	isFill = new bool(rhs.isFill);
	//	type = new int(rhs.type);
	//	pt1 = new Point(rhs.pt1);
	//	pt2 = new Point(rhs.pt2);
	//}
	//return *this;
}

Point& Line::operator[](int index)
{
	if (index == 0)
		return pt1;
	else if (index == 1)
		return pt2;
	else
		throw std::out_of_range("Error index");
}

Circle::Circle() :
	Shape(typeCircle)
{}

Circle::Circle(const Circle & rhs) :
	Shape(rhs.color,
		rhs.pt1,
		rhs.pt2,
		rhs.isFill,
		typeCircle)
{}

Circle::Circle(const Point & pt1, const Point & pt2, bool isFill) :
	Shape(Color(), pt1, pt2, isFill, typeCircle)
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

bool Circle::operator<(const Circle& rhs) const
{
	return sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)) <
		sqrt(pow((rhs.pt2.x - rhs.pt1.x), 2) + pow((rhs.pt2.y - rhs.pt1.y), 2));
}

bool Circle::operator<=(const Circle& rhs) const
{
	return sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)) <=
		sqrt(pow((rhs.pt2.x - rhs.pt1.x), 2) + pow((rhs.pt2.y - rhs.pt1.y), 2));
}

bool Circle::operator>(const Circle& rhs) const
{
	return sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)) >
		sqrt(pow((rhs.pt2.x - rhs.pt1.x), 2) + pow((rhs.pt2.y - rhs.pt1.y), 2));
}

bool Circle::operator>=(const Circle& rhs) const
{
	return sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)) >=
		sqrt(pow((rhs.pt2.x - rhs.pt1.x), 2) + pow((rhs.pt2.y - rhs.pt1.y), 2));
}
 
bool Circle::operator==(const Circle& rhs) const
{
	return sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)) ==
		sqrt(pow((rhs.pt2.x - rhs.pt1.x), 2) + pow((rhs.pt2.y - rhs.pt1.y), 2));
}

bool Circle::operator!=(const Circle& rhs) const
{
	return sqrt(pow((pt2.x - pt1.x), 2) + pow((pt2.y - pt1.y), 2)) !=
		sqrt(pow((rhs.pt2.x - rhs.pt1.x), 2) + pow((rhs.pt2.y - rhs.pt1.y), 2));
}

Circle& Circle::operator=(const Circle& rhs)
{
	color = rhs.color;
	isFill = rhs.isFill;
	type = rhs.type;
	pt1 = rhs.pt1;
	pt2 = rhs.pt2;
	return *this;
	///*deep copy
	//下面所有拷贝得到的变量都应该是指针类型*/
	//if (*this != rhs)
	//{
	//	delete color;
	//	delete isFill;
	//	delete type;
	//	delete pt1;
	//	delete pt2;
	//	color = new Color(rhs.color);
	//	isFill = new bool(rhs.isFill);
	//	type = new int(rhs.type);
	//	pt1 = new Point(rhs.pt1);
	//	pt2 = new Point(rhs.pt2);
	//}
	//return *this;
}

Point& Circle::operator[](int index)
{
	if (index == 0)
		return pt1;
	else if (index == 1)
		return pt2;
	else
		throw std::out_of_range("Error index");
}

Rectangle_::Rectangle_() :
	Shape(typeRectangle)
{}

Rectangle_::Rectangle_(const Rectangle_ & rhs) :
	Shape(rhs.color,
		rhs.pt1,
		rhs.pt2,
		rhs.isFill,
		typeRectangle)
{}

Rectangle_::Rectangle_(const Point & pt1, const Point & pt2, bool isFill) :
	Shape(Color(), pt1, pt2, isFill, typeRectangle)
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

bool Rectangle_::operator<(const Rectangle_& rhs) const
{
	return abs(pt2.x - pt1.x) + abs(pt2.y - pt1.y) <
		abs(rhs.pt2.x - rhs.pt1.x) + abs(rhs.pt2.y - rhs.pt1.y);
}

bool Rectangle_::operator<=(const Rectangle_& rhs) const
{
	return abs(pt2.x - pt1.x) + abs(pt2.y - pt1.y) <=
		abs(rhs.pt2.x - rhs.pt1.x) + abs(rhs.pt2.y - rhs.pt1.y);
}

bool Rectangle_::operator>(const Rectangle_& rhs) const
{
	return abs(pt2.x - pt1.x) + abs(pt2.y - pt1.y) >
		abs(rhs.pt2.x - rhs.pt1.x) + abs(rhs.pt2.y - rhs.pt1.y);
}

bool Rectangle_::operator>=(const Rectangle_& rhs) const
{
	return abs(pt2.x - pt1.x) + abs(pt2.y - pt1.y) >=
		abs(rhs.pt2.x - rhs.pt1.x) + abs(rhs.pt2.y - rhs.pt1.y);
}

bool Rectangle_::operator==(const Rectangle_& rhs) const
{
	return abs(pt2.x - pt1.x) + abs(pt2.y - pt1.y) ==
		abs(rhs.pt2.x - rhs.pt1.x) + abs(rhs.pt2.y - rhs.pt1.y);
}

bool Rectangle_::operator!=(const Rectangle_& rhs) const
{
	return abs(pt2.x - pt1.x) + abs(pt2.y - pt1.y) !=
		abs(rhs.pt2.x - rhs.pt1.x) + abs(rhs.pt2.y - rhs.pt1.y);
}

Rectangle_& Rectangle_::operator=(const Rectangle_& rhs)
{
	color = rhs.color;
	isFill = rhs.isFill;
	type = rhs.type;
	pt1 = rhs.pt1;
	pt2 = rhs.pt2;
	return *this;
	///*deep copy
	//下面所有拷贝得到的变量都应该是指针类型*/
	//if (*this != rhs)
	//{
	//	delete color;
	//	delete isFill;
	//	delete type;
	//	delete pt1;
	//	delete pt2;
	//	color = new Color(rhs.color);
	//	isFill = new bool(rhs.isFill);
	//	type = new int(rhs.type);
	//	pt1 = new Point(rhs.pt1);
	//	pt2 = new Point(rhs.pt2);
	//}
	//return *this;
}

Point& Rectangle_::operator[](int index)
{
	if (index == 0)
		return pt1;
	else if (index == 1)
		return pt2;
	else
		throw std::out_of_range("Error index");
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
	/*is >> line.type >> line.isFill >> line.color
		>> line.pt1 >> line.pt2;*/
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

void drawAShape(Shape& shape)
{
	shape.setColor(Color(EGEGET_R(getcolor()),
		EGEGET_G(getcolor()),
		EGEGET_B(getcolor())));
	shape.drawShape();
	Shape::shapes.push_back(&shape);
}

void drawShapes()
{
	for (auto it = Shape::shapes.begin(); it != Shape::shapes.end(); ++it)
	{
		(*it)->drawShape();
	}
}

void clearShapes()
{
	for (auto it = Shape::shapes.begin(); it != Shape::shapes.end(); ++it)
	{
		delete *it;
	}
	Shape::shapes.clear();
}

Triangle::Triangle() :
	Shape(typeTriangle),
	pt3()
{}

Triangle::Triangle(const Triangle & rhs) :
	Shape(rhs.color,
		rhs.pt1,
		rhs.pt2,
		rhs.isFill,
		typeTriangle),
	pt3(rhs.pt3)
{}

Point Triangle::getPt3()
{
	return pt3;
}

void Triangle::setPt3(const Point& pt3_)
{
	pt3 = pt3_;
}

void Triangle::drawShape()
{
	// do nothing
	// 使用多边形画三角形即可
}
