/****************************************************************
*																*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4															*
*                                                               *
*****************************************************************/

#include "canvas.h"
#include <cassert>
#include "operationButton.h"

// 画板默认画直线
int Canvas::typeDrawed = lineButton;

Canvas::Canvas() :
	pointCount(0),
	pt1(),
	pt2(),
	aLine(nullptr),
	aCircle(nullptr),
	aRectangle(nullptr)
{}

bool Canvas::isClicked(const mouse_msg & msg) const
{
	return (msg.x >= 500 && msg.x <= 1440) && (msg.y >= 20 && msg.y <= 720);
}

void Canvas::operation(const mouse_msg& msg)
{
	++pointCount;
	if (pointCount % 2 == 1)
	{
		// 坐标换算
		// 在画图时会把视图区域的设置在(500, 20, 1440, 720)
		// 这样做可以避免图形超出画布的范围而遮盖掉用户操作区
		pt1.x = msg.x - 500;
		pt1.y = msg.y - 20;
	}
	else // pointCount为偶数时进行画图操作
	{
		clearBuffer();
		pt2.x = msg.x - 500;
		pt2.y = msg.y - 20;
		switch (typeDrawed) // 根据当前选择的图形类型画图
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
			// 程序运行正常时不应该进入default，防bug
			assert(false);
		}
	}
}

void Canvas::setTypeDrawed(int typeDrawed_)
{
	typeDrawed = typeDrawed_;
}
