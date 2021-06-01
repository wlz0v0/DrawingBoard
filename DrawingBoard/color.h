/****************************************************************
*																*
* 本头文件包含了颜色类    										*
* 颜色类与ege的color_t不同，使用了R,G,B三个变量分别存储RGB分量		*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4															*
*                                                               *
*****************************************************************/

#ifndef COLOR_H
#define COLOR_H

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
	// 预设的颜色，主要用于颜色按钮的初始化
	const static std::array<Color, 17> colorset; 

	Color();
	Color(int red_, int green_, int blue_);
	Color& operator=(const Color& right);
	~Color();
	// 用Color的实例设置画图的颜色，包括填充色
	void setGraphColor(); 
	// 重载流运算符便于文件读写
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