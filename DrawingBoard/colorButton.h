#ifndef COLOR_BUTTON_H
#define COLOR_BUTTON_H
// 本头文件中包含了颜色按钮类

#include "buttonBase.h"
#include "color.h"

// 颜色按钮，用于设置图形的颜色
// 继承了按钮基类，无子类
// 字段中的颜色代表着按钮实例对应的颜色
class ColorButton final : public ButtonBase
{
private:
	Color buttonColor;
public:
	ColorButton(const Point& pt1_, const Point& pt2_, const Color& color);
	virtual void init();
	virtual void operation();
};

#endif // COLOR_BUTTON_H