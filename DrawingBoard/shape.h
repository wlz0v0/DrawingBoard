#ifndef SHAPE_H
#define SHAPE_H
// 本头文件中包含形状抽象基类及其子类和用于画图的非成员函数：
// 直线类、圆类、矩形类

#include <vector>
#include "color.h"
#include "point.h"

enum TypeName
{
	typeLine = 1,
	typeCircle = 2,
	typeRectangle = 3
};

// 形状抽象基类
// 字段有形状的颜色，是否填充，类型和形状的两点
// 以及一个静态向量shapes用于储存形状的数据
// 方法有画出形状实例函数
// 重载了流输入输出运算符
class Shape
{
protected:
	Color color;
	bool isFill;
	int type;
	Point pt1, pt2;

public:
	static std::vector<Shape*> shapes;

	Shape(int type_);
	virtual ~Shape() = default;

	void setColor(const Color& color_);
	void setIsFill(bool isFill_);
	void setPt1(int x_, int y_);
	void setPt2(int x_, int y_);

	Color getColor();
	int getType();
	Point getPt1();
	Point getPt2();
	static size_t getShapeCount();

	virtual void drawShape() = 0; 

	friend std::ostream& operator<<(std::ostream& os, Shape& shape);
	friend std::istream& operator>>(std::istream& is, Shape& shape);
};

// 直线类
// 继承于形状基类
// 直线无填充，是否填充默认为false
// 两点为确定直线的两点
class Line : public Shape
{
public:
	Line();
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Line& line);
	friend std::istream& operator>>(std::istream& is, Line& line);
};

// 圆类
// 继承于形状基类
// 圆可填充，填充圆用填充扇形实现
// 两点为中一点为圆心，另外一点到圆心的距离为半径
class Circle : public Shape
{
public:
	Circle();
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Circle& circle);
	friend std::istream& operator>>(std::istream& is, Circle& circle);
};

// 矩形类
// 继承于形状基类
// 矩形可填充
// 两点为矩形的左上角点和右下角点
// 类名后加下划线是因为ege库中存在一个Rectangle类
// ege库似乎直接using namespace ege;使得命名空间有些混乱
class Rectangle_ : public Shape
{
public:
	Rectangle_();
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Rectangle_& rectangle);
	friend std::istream& operator>>(std::istream& is, Rectangle_& rectangle);
};

// 非成员函数
void drawAShape(Shape& shape, bool isFill_); // 利用多态画出一个形状
void drawShapes(); // 把shapes中储存的数据画出来
void clearShapes(); // 清空shapes

#endif // SHAPE_H