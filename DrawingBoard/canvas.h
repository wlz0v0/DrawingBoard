/****************************************************************
*																*
* 本头文件包含了画布类    										*
* 画布被点击则会记录点的位置，当点击两次时画当前选择的图形			*
* 画布与按钮有共同点，但不完全具有按钮的特性，因此未继承按钮基类		*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *															*
* lab 4                                                         *
*                                                               *
*****************************************************************/

#ifndef CANVAS_H
#define CANVAS_H
#include <graphics.h>
#include "point.h"
#include "shape.h"

// 
// 枚举常量，便于记录当前选择绘画的图形
// 
enum ShapeButtons
{
	lineButton = 1,
	rectangleButton = 2,
	fillRectangleButton = 3,
	circleButton = 4,
	fillCircleButton = 5
};

// 
// 画布不需要初始化，其图形界面初始化在画板初始化时就已经初始化完毕了
// 画布的操作需要获取鼠标点击的位置，因为需要保存该点的坐标才能完成画图
// 故画图不继承按钮基类
// 
class Canvas
{
public:
	Canvas();
	bool isClicked(const mouse_msg& msg) const;
	void operation(const mouse_msg& msg);

	// 提供给形状按钮的接口，便于设置所画图形
	static void setTypeDrawed(int typeDrawed_); 
	

private:
	// 记录所画图形的类型
	static int typeDrawed;  
	// 记录画板上选取的点的个数，如果是偶数则画图
	int pointCount; 
	// 每一个图形都有两个点，因此只需两个点对象
	Point pt1, pt2;
	// 直接在类内构造三个图形的对象，可以不用重复的在函数里创建对象
	// 构造为指针可以new出来，然后存到图形数组中，便于进行撤销删除保存读取操作
	Line* aLine;
	Circle* aCircle;
	Rectangle_* aRectangle;
};

#endif // CANVAS_H