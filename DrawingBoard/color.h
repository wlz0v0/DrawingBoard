#ifndef COLOR_H
#define COLOR_H
// 本头文件中包含了颜色类

#include <iostream>

// 颜色类
// 字段中包含颜色的RGB属性
// 方法中包含根据颜色设置画图颜色和填充颜色
// 重载了流输入输出运算符
// 还包含一个全局颜色数组的声明，里面有预先设定好的颜色
class Color
{
public:
	int red;
	int green;
	int blue;

	Color();
	Color(int red_, int green_, int blue_);
	Color& operator=(const Color& right);
	void setGraphColor();
	friend std::ostream& operator<<(std::ostream& os, Color& color);
	friend std::istream& operator>>(std::istream& is, Color& color);
};

extern const Color colorset[17];

#endif // COLOR_H