/****************************************************************
*																*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4															*
*                                                               *
*****************************************************************/

#include "colorButton.h"
#include <graphics.h>

ColorButton::ColorButton(const Point& pt1_, const Point& pt2_, const Color& color) :
	ButtonBase(pt1_, pt2_),
	buttonColor(color)
{}

// 颜色按钮图样是小正方形，其颜色为该按钮所设置的颜色
void ColorButton::init()
{
	buttonColor.setGraphColor();
	bar(pt1.x, pt1.y, pt2.x, pt2.y);
}

void ColorButton::operation()
{
	buttonColor.setGraphColor();
}
