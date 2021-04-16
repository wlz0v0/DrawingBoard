#ifndef POINT_H
#define POINT_H
// 本头文件中包含点类

#include <iostream>

// 点类
// 字段包含一个点的x坐标和y坐标
// 重载了流输入输出运算符和比较运算符
class Point
{
public:
	int x;
	int y;

	Point();
	Point(int x_, int y_);
	friend std::ostream& operator<<(std::ostream& os, Point& pt);
	friend std::istream& operator>>(std::istream& is, Point& pt);
	bool operator>(const Point& pt_);
};

#endif //POINT_H