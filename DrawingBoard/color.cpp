/****************************************************************
*																*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4															*
*                                                               *
*****************************************************************/

#include "color.h"
#include <graphics.h>
#include <stdexcept>

//��������ŵ��Ǹ�����ɫ��RGBֵ�����ں����ӡ
const std::array<Color, 17> Color::colorset = {
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

bool Color::operator==(const Color& rhs) const
{
	return (red == rhs.red && green == rhs.green && blue == rhs.blue);
}

bool Color::operator!=(const Color& rhs) const
{
	// !=��==�Ľ���෴
	return !operator==(rhs);
}

int& Color::operator[](int index)
{
	if (index == 0)
		return red;
	else if (index == 1)
		return green;
	else if (index == 2)
		return blue;
	else
		throw std::out_of_range("Error index");
}

Color& Color::operator++()
{
	if (red < 255)
		++red;
	if (green < 255)
		++green;
	if (blue < 255)
		++blue;
	return *this;
}

Color Color::operator++(int)
{
	Color old = *this;
	++(*this);
	return old;
}

Color& Color::operator--()
{
	if (red > 0)
		--red;
	if (green > 0)
		--green;
	if (blue > 0)
		--blue;
	return *this;
}

Color Color::operator--(int)
{
	Color old = *this;
	--(*this);
	return old;
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