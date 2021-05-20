#include <graphics.h>
#include "colorButton.h"

ColorButton::ColorButton(const Point& pt1_, const Point& pt2_, const Color& color) :
	ButtonBase(pt1_, pt2_),
	buttonColor(color)
{}

void ColorButton::init()
{
	buttonColor.setGraphColor();
	bar(pt1.x, pt1.y, pt2.x, pt2.y);
}

void ColorButton::operation()
{
	buttonColor.setGraphColor();
}
