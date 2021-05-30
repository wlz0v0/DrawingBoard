#ifndef COLOR_H
#define COLOR_H
// 本头文件中包含了颜色类

#include <iostream>
#include <array>

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
	const static std::array<Color, 17> colorset; // 预设的颜色

	Color();
	Color(int red_, int green_, int blue_);
	Color& operator=(const Color& right);
	~Color();
	void setGraphColor(); // 用Color的实例设置画图的颜色
	friend std::ostream& operator<<(std::ostream& os, Color& color);
	friend std::istream& operator>>(std::istream& is, Color& color);
	bool operator==(const Color& rhs) const;
	bool operator!=(const Color& rhs) const;
	int& operator[](int index);
	Color& operator++();
	Color operator++(int);
	Color& operator--();
	Color operator--(int);
};

#endif // COLOR_H