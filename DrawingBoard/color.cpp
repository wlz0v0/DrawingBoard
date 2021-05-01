#include <graphics.h>
#include "color.h"

//这个数组存放的是各种颜色的RGB值，便于后面打印
const std::array<Color, 17> colorset = {
	       Color(255, 0, 0),      //红色
		   Color(255, 97, 0),     //橙色
		   Color(255, 255, 0),    //黄色
		   Color(0, 255, 0),      //绿色
		   Color(0, 255, 255),    //青色
		   Color(135, 206, 235),  //天蓝色
		   Color(0, 0, 255),      //蓝色
		   Color(128, 0, 255),    //紫色
		   Color(0, 0, 0),        //黑色
		   Color(242, 156, 177),  //粉色
		   Color(255, 201, 14),   //金色
		   Color(239, 228, 176),  //浅黄色
		   Color(181, 230, 29),   //酸橙色
		   Color(153, 217, 234),  //淡青绿色
		   Color(112, 146, 190),  //蓝灰色
		   Color(200, 191, 231),  //浅紫色
		   Color(185, 122, 87),   //棕色
};

Color::Color() :
	red(0),
	green(0),
	blue(0)
{}

Color::Color(int red_, int green_, int blue_) :
	red(red_),
	green(green_),
	blue(blue_)
{}

Color& Color::operator=(const Color& rhs)
{
	if (this != &rhs)
	{
		red = rhs.red;
		green = rhs.green;
		blue = rhs.blue;
	}
	return *this;
}

Color::~Color()
{
}

void Color::setGraphColor()
{
	setcolor(EGERGB(red, green, blue));
	setfillcolor(EGERGB(red, green, blue));
}

std::ostream& operator<<(std::ostream& os, Color& color)
{
	os << color.red << " " << color.green << " " << color.blue;
	return os;
}

std::istream& operator>>(std::istream& is, Color& color)
{
	is >> color.red >> color.green >> color.blue;
	return is;
}