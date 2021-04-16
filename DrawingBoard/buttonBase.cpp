#include <graphics.h>
#include "buttonBase.h"

ButtonBase::ButtonBase(const Point& pt1_, const Point& pt2_) :
	pt1(pt1_),
	pt2(pt2_)
{}

ButtonBase::~ButtonBase(){}

bool ButtonBase::isClicked(const mouse_msg & msg)
{
	if ((msg.x >= pt1.x && msg.x <= pt2.x) && (msg.y >= pt1.y && msg.y <= pt2.y))
		return true;
	return false;
}
