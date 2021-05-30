#ifndef CANVAS_H
#define CANVAS_H
#include <graphics.h>
#include "point.h"
#include "shape.h"

enum ShapeButtons
{
	lineButton = 1,
	rectangleButton = 2,
	fillRectangleButton = 3,
	circleButton = 4,
	fillCircleButton = 5
};

class Canvas
{
public:
	Canvas();
	bool isClicked(const mouse_msg& msg) const;
	void operation(const mouse_msg& msg);
	static void setTypeDrawed(int typeDrawed_);

private:
	static int typeDrawed;  // ����ͼ�ε�����
	int pointCount; // ��¼������ѡȡ�ĵ�ĸ����������ż����ͼ
	Point pt1, pt2;
	Line* aLine;
	Circle* aCircle;
	Rectangle_* aRectangle;
};

#endif // CANVAS_H