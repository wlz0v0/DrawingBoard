#ifndef BUTTON_BASE_H
#define BUTTON_BASE_H
// 本头文件包含了按钮抽象基类

#include <graphics.h>
#include "point.h"

// 按钮抽象基类
// 字段中两个点代表着按钮的左上角的点和右下角的点，即按钮的范围
// 是否被点击通过判断鼠标位置是否在按钮的范围内
// 虚函数init负责各种按钮的初始化
// 虚函数operation负责实现各种按钮的操作
// 类的继承链见于ButtonClass.cd类图中
class ButtonBase
{
protected:
	Point pt1, pt2;
public:

	ButtonBase(const Point& pt1_, const Point& pt2_);
	virtual ~ButtonBase();
	
	bool isClicked(const mouse_msg& msg);
	virtual void init() = 0; // 按钮图样初始化
	virtual void operation() = 0; // 按钮对应操作
};

#endif // BUTTON_BASE_H