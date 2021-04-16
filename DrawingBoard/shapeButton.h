#ifndef SHAPE_BUTTON_H
#define SHAPE_BUTTON_H
// 本头文件中包含了形状按钮类及其子类：直线按钮类、圆按钮类、矩形按钮类

#include "buttonBase.h"
#include "shape.h"

// 形状按钮，用于画出各种形状
// 继承了按钮基类，还有各种形状子类
// 字段中含是否填充
class ShapeButton : public ButtonBase
{
protected:
	bool isFill;
public:
	ShapeButton(const Point& pt1_, const Point& pt2_, bool isFill_);
	virtual void init() = 0;
	virtual void operation() = 0;
};

// 直线图形按钮
// 继承了形状按钮类，无子类
// 字段有一个直线指针变量，每画出一个直线都会被new出然后添加到Shape类静态vector shapes中
// 直线无填充，isFill默认为false
class LineButton final : public ShapeButton
{
private:
	Line* aLine;

public:
	LineButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// 圆形图形按钮
// 继承了形状按钮类，无子类
// 字段有一个圆形指针变量，每画出一个圆都会被new出然后添加到Shape类静态vector shapes中
// 圆有填充圆和空心圆
class CircleButton final : public ShapeButton
{
private:
	Circle* aCircle;

public:
	CircleButton(const Point& pt1_, const Point& pt2_, bool isFill_);
	virtual void init();
	virtual void operation();
};

// 矩形图形按钮
// 继承了形状按钮类，无子类
// 字段有一个矩形指针变量，每画出一个矩形都会被new出然后添加到Shape类静态vector shapes中
// 矩形有实心和空心
class RectangleButton final : public ShapeButton
{
private:
	Rectangle_* aRectangle;

public:
	RectangleButton(const Point& pt1_, const Point& pt2_, bool isFill_);
	virtual void init();
	virtual void operation();
};

#endif // SHAPE_BUTTON_H