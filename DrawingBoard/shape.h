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
	typeRectangle = 3,
	typeTriangle = 4
};

// 形状抽象基类
// 字段有形状的颜色，是否填充，类型和形状的两点
// 以及一个静态向量shapes用于储存形状的数据
// 方法有画出形状实例函数
// 重载了流输入输出运算符
class Shape
{
public:
	static std::vector<Shape*> shapes;

	explicit Shape(int type_); // 防止隐式类型转换
	Shape(const Color& color_, const Point& pt1_, const Point& pt2_,
		bool isFill, int type);
	virtual ~Shape() = default;

	void setType(int type_);
	void setColor(const Color& color_);
	void setIsFill(bool isFill_);
	void setPt1(int x_, int y_);
	void setPt2(int x_, int y_);

	Color getColor() const;
	int getType() const;
	Point getPt1() const;
	Point getPt2() const;
	static size_t getShapeCount();

	virtual void drawShape() = 0; // draw function

	friend std::ostream& operator<<(std::ostream& os, Shape& shape);
	friend std::istream& operator>>(std::istream& is, Shape& shape);

protected:
	Color color;
	bool isFill;
	int type;
	Point pt1, pt2;
};

// 直线类
// 继承于形状基类
// 直线无填充，是否填充默认为false
// 两点为确定直线的两点
class Line : public Shape
{
public:
	Line();
	Line(const Line& rhs);
	Line(const Point& pt1, const Point& pt2);
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Line& line);
	friend std::istream& operator>>(std::istream& is, Line& line);
	bool operator<(const Line& rhs) const;
	bool operator<=(const Line& rhs) const;
	bool operator>(const Line& rhs) const;
	bool operator>=(const Line& rhs) const;
	bool operator==(const Line& rhs) const;
	bool operator!=(const Line& rhs) const;
	Line& operator=(const Line& rhs);
	Point& operator[](int index);
};

// 圆类
// 继承于形状基类
// 圆可填充，填充圆用填充扇形实现
// 两点为中一点为圆心，另外一点到圆心的距离为半径
class Circle : public Shape
{
public:
	Circle();
	Circle(const Circle& rhs);
	Circle(const Point& pt1, const Point& pt2, bool isFill);
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Circle& circle);
	friend std::istream& operator>>(std::istream& is, Circle& circle);
	bool operator<(const Circle& rhs) const;
	bool operator<=(const Circle& rhs) const;
	bool operator>(const Circle& rhs) const;
	bool operator>=(const Circle& rhs) const;
	bool operator==(const Circle& rhs) const;
	bool operator!=(const Circle& rhs) const;
	Circle& operator=(const Circle& rhs);
	Point& operator[](int index);
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
	Rectangle_(const Rectangle_& rhs);
	Rectangle_(const Point& pt1, const Point& pt2, bool isFill);
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Rectangle_& rectangle);
	friend std::istream& operator>>(std::istream& is, Rectangle_& rectangle);
	bool operator<(const Rectangle_& rhs) const;
	bool operator<=(const Rectangle_& rhs) const;
	bool operator>(const Rectangle_& rhs) const;
	bool operator>=(const Rectangle_& rhs) const;
	bool operator==(const Rectangle_& rhs) const;
	bool operator!=(const Rectangle_& rhs) const;
	Rectangle_& operator=(const Rectangle_& rhs);
	Point& operator[](int index);
};

// 这个三角形类是为了作业，实际上的画板并没有画这个三角形的操作
// 原因是在画板的操作界面在设计之初只能容纳一个直线按钮，两个圆按钮和两个矩形按纽
// 没有给其他的图形留空间，所以仅在程序内写一个Triangle类，但在实际画板内没有画的操作
// 
class Triangle : public Shape
{
private:
	Point pt3;
public:
	Triangle();
	Triangle(const Triangle& rhs);
	Point getPt3();
	void setPt3(const Point& pt3_);
	virtual void drawShape();
};

// 非成员函数
void drawAShape(Shape& shape); // 利用多态画出一个形状
void drawShapes(); // 把shapes中储存的数据画出来
void clearShapes(); // 清空shapes


#endif // SHAPE_H