/****************************************************************
*																*
* 本头文件包含了颜色按钮类    										*
* 颜色按钮执行的操作是设置颜色										*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *															*
* lab 4                                                         *
*                                                               *
*****************************************************************/

#ifndef COLOR_BUTTON_H
#define COLOR_BUTTON_H

#include "buttonBase.h"
#include "color.h"

// 颜色按钮，用于设置图形的颜色
// 继承了按钮基类，无子类
// 字段中的颜色代表着按钮实例对应的颜色
class ColorButton final : public ButtonBase
{
public:
	ColorButton(const Point& pt1_, const Point& pt2_, const Color& color);
	virtual void init();
	virtual void operation();
private:
	Color buttonColor; // 颜色按钮的颜色
};

#endif // COLOR_BUTTON_H