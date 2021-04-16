#include "shapeButton.h"
#include "operationButton.h"

ShapeButton::ShapeButton(const Point& pt1_, const Point& pt2_, bool isFill_) :
	ButtonBase(pt1_, pt2_),
	isFill(isFill_)
{}

LineButton::LineButton(const Point& pt1_, const Point& pt2_) :
	ShapeButton(pt1_, pt2_, false),
	aLine(nullptr)
{}

void LineButton::init()
{
	setcolor(BLACK);
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
	setcolor(BLUE);
	line(pt1.x + 5, pt1.y + 5, pt2.x - 5, pt2.y - 5);         //画直线选项块
}

void LineButton::operation()
{
	clearBuffer();
	aLine = new Line;
	drawAShape(*aLine, false);
}

CircleButton::CircleButton(const Point& pt1_, const Point& pt2_, bool isFill_) :
	ShapeButton(pt1_, pt2_, isFill_),
	aCircle(nullptr)
{}

void CircleButton::init()
{
	if (isFill)
	{
		setcolor(BLACK);
		rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
		setcolor(BLUE);
		setfillcolor(BLUE);
		pieslice(
			(pt1.x + pt2.x) / 2, (pt1.y + pt2.y) / 2,
			 0, 360, (pt2.x - pt1.x) / 2 - 5);//画填充圆形选项块
	}
	else
	{
		setcolor(BLACK);
		rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
		setcolor(BLUE);
		circle(
			(pt1.x + pt2.x) / 2,
			(pt1.y + pt2.y) / 2,
			(pt2.x - pt1.x) / 2 - 5); //画圆形选项块
	}
}

void CircleButton::operation()
{
	clearBuffer();
	aCircle = new Circle;
	drawAShape(*aCircle, isFill);
}

RectangleButton::RectangleButton(const Point& pt1_, const Point& pt2_, bool isFill_) :
	ShapeButton(pt1_, pt2_, isFill_),
	aRectangle(nullptr)
{}

void RectangleButton::init()
{
	if (isFill)
	{
		setfillcolor(BLUE);
		bar(160, 80, 220, 140);        //画填充矩形选项块
	}
	else
	{
		setcolor(BLUE);
		rectangle(90, 80, 150, 140);   //画矩形选项块
	}
}

void RectangleButton::operation()
{
	clearBuffer();
	aRectangle = new Rectangle_;
	drawAShape(*aRectangle, isFill);
}
