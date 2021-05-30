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
	static int typeDrawed;  // 所画图形的类型
	int pointCount; // 记录画板上选取的点的个数，如果是偶数则画图
	Point pt1, pt2;
	Line* aLine;
	Circle* aCircle;
	Rectangle_* aRectangle;
};

#endif // CANVAS_H