#include <graphics.h>
#include "color.h"

//��������ŵ��Ǹ�����ɫ��RGBֵ�����ں����ӡ
const std::array<Color, 17> colorset = {
	       Color(255, 0, 0),      //��ɫ
		   Color(255, 97, 0),     //��ɫ
		   Color(255, 255, 0),    //��ɫ
		   Color(0, 255, 0),      //��ɫ
		   Color(0, 255, 255),    //��ɫ
		   Color(135, 206, 235),  //����ɫ
		   Color(0, 0, 255),      //��ɫ
		   Color(128, 0, 255),    //��ɫ
		   Color(0, 0, 0),        //��ɫ
		   Color(242, 156, 177),  //��ɫ
		   Color(255, 201, 14),   //��ɫ
		   Color(239, 228, 176),  //ǳ��ɫ
		   Color(181, 230, 29),   //���ɫ
		   Color(153, 217, 234),  //������ɫ
		   Color(112, 146, 190),  //����ɫ
		   Color(200, 191, 231),  //ǳ��ɫ
		   Color(185, 122, 87),   //��ɫ
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