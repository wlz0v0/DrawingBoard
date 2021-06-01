/****************************************************************
*																*
* 本头文件包含了按钮抽象基类										*
* 按钮用于响应用户的点击并执行相应的操作							*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4                                                         *
*                                                               *
*****************************************************************/

#ifndef BUTTON_BASE_H
#define BUTTON_BASE_H


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
public:
	ButtonBase(const Point& pt1_, const Point& pt2_);
	virtual ~ButtonBase();
	
	bool isClicked(const mouse_msg& msg);
	// 按钮图样初始化，把按钮应该有的样子画到画板上
	virtual void init() = 0; 
	// 按钮对应操作
	virtual void operation() = 0;

protected:
	Point pt1, pt2;
};

#endif // BUTTON_BASE_H