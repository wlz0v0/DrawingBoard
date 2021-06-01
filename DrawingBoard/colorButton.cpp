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

// ��ɫ��ťͼ����С�����Σ�����ɫΪ�ð�ť�����õ���ɫ
void ColorButton::init()
{
	buttonColor.setGraphColor();
	bar(pt1.x, pt1.y, pt2.x, pt2.y);
}

void ColorButton::operation()
{
	buttonColor.setGraphColor();
}
