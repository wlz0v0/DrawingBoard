#include "canvas.h"

int Canvas::typeDrawed = 1;

Canvas::Canvas() :
	pointCount(0),
	pt1(),
	pt2(),
	aLine(nullptr),
	aCircle(nullptr),
	aRectangle(nullptr)
{}

bool Canvas::isClicked(const mouse_msg & msg)
{
	if ((msg.x >= 500 && msg.x <= 1440) && (msg.y >= 20 && msg.y <= 720))
		return true;
	return false;
}

void Canvas::operation(const mouse_msg& msg)
{
	++pointCount;
	if (pointCount % 2 == 1)
	{
		pt1.x = msg.x - 500;
		pt1.y = msg.y - 20;
	}
	else
	{
		pt2.x = msg.x - 500;
		pt2.y = msg.y - 20;
		switch (typeDrawed)
		{
		case lineButton:
			aLine = new Line(pt1, pt2);
			drawAShape(*aLine);
			break;
		case rectangleButton:
			aRectangle = new Rectangle_(pt1, pt2, false);
			drawAShape(*aRectangle);
			break;
		case fillRectangleButton:
			aRectangle = new Rectangle_(pt1, pt2, true);
			drawAShape(*aRectangle);
			break;
		case circleButton:
			aCircle = new Circle(pt1, pt2, false);
			drawAShape(*aCircle);
			break;
		case fillCircleButton:
			aCircle = new Circle(pt1, pt2, true);
			drawAShape(*aCircle);
			break;
		default:
			throw "?";
		}
	}
}

void Canvas::setTypeDrawed(int typeDrawed_)
{
	typeDrawed = typeDrawed_;
}
