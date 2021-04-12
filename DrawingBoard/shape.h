#ifndef SHAPE_H
#define SHAPE_H
#include "color.h"
#include "point.h"

enum TypeName
{
	typeLine = 1,
	typeCircle = 2,
	typeRectangle = 3
};

//Shape为抽象基类
//Line、Circle、Rectangle为派生类
class Shape
{
protected:
	Color color;
	bool isFill;
	int type;
	Point pt1, pt2;

public:
	Shape(int type_);
	virtual ~Shape() = default;

	void setColor(const Color& color_);
	void setIsFill(bool isFill_);
	void setPt1(int x_, int y_);
	void setPt2(int x_, int y_);

	Color getColor();
	int getType();
	Point getPt1();
	Point getPt2();

	virtual void drawShape() = 0; 

	friend std::ostream& operator<<(std::ostream& os, Shape& shape);
	friend std::istream& operator>>(std::istream& is, Shape& shape);
};

class Line : public Shape
{
public:
	Line();
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Line& line);
	friend std::istream& operator>>(std::istream& is, Line& line);
};

class Circle : public Shape
{
public:
	Circle();
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Circle& circle);
	friend std::istream& operator>>(std::istream& is, Circle& circle);
};

//类名后加下划线是因为ege库中存在一个Rectangle类，而将其放入命名空间中会产生一些麻烦
class Rectangle_ : public Shape
{
public:
	Rectangle_();
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Rectangle_& rectangle);
	friend std::istream& operator>>(std::istream& is, Rectangle_& rectangle);
};


#endif // SHAPE_H