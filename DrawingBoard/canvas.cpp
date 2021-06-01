/****************************************************************
*																*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4															*
*                                                               *
*****************************************************************/

#include "canvas.h"
#include <cassert>
#include "operationButton.h"

// ����Ĭ�ϻ�ֱ��
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
		// ���껻��
		// �ڻ�ͼʱ�����ͼ�����������(500, 20, 1440, 720)
		// ���������Ա���ͼ�γ��������ķ�Χ���ڸǵ��û�������
		pt1.x = msg.x - 500;
		pt1.y = msg.y - 20;
	}
	else // pointCountΪż��ʱ���л�ͼ����
	{
		clearBuffer();
		pt2.x = msg.x - 500;
		pt2.y = msg.y - 20;
		switch (typeDrawed) // ���ݵ�ǰѡ���ͼ�����ͻ�ͼ
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
			// ������������ʱ��Ӧ�ý���default����bug
			assert(false);
		}
	}
}

void Canvas::setTypeDrawed(int typeDrawed_)
{
	typeDrawed = typeDrawed_;
}
