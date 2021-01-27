/*本文件中存储用鼠标画直线、圆、填充圆、矩形、填充矩形函数*/

#include <graphics.h>
#include <math.h>
#include "allpaint_support.h"
#include "datasave.h"

extern DATA data[20];
extern unsigned int graphcount;

//用鼠标画直线函数
void mousepaintline()
{
	mouse_msg msg1, msg2;
	savegraphcolor();                                  //保存图形颜色
	data[graphcount].type = 1;
	setviewport(500, 20, 1440, 720);
	while (true)
	{
		msg1 = getmouse();
		if (msg1.is_left() && msg1.is_down())
		{
			data[graphcount].coord[0].x = msg1.x - 500; //坐标换算
			data[graphcount].coord[0].y = msg1.y - 20;  //坐标换算
			break;
		}
	}
	while (true)
	{
		msg2 = getmouse();
		if (msg2.is_left() && msg2.is_down())
		{
			data[graphcount].coord[1].x = msg2.x - 500; //坐标换算
			data[graphcount].coord[1].y = msg2.y - 20;  //坐标换算
			break;
		}
	}
	line(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].coord[1].x, data[graphcount].coord[1].y);
	reset(0); //重置画板属性
}

//用鼠标画空心圆函数
void mousepaintcircle()
{
	double x1, y1, x2, y2;
	mouse_msg msg1, msg2;
	data[graphcount].type = 2;
	savegraphcolor();                                  //保存图形颜色
	setviewport(500, 20, 1440, 720);
	while (true)
	{
		msg1 = getmouse();
		if (msg1.is_left() && msg1.is_down())
		{
			x1 = msg1.x - 500.0;  //坐标换算
			y1 = msg1.y - 20.0;   //坐标换算
			break;
		}
	}
	while (true)
	{
		msg2 = getmouse();
		if (msg2.is_left() && msg2.is_down())
		{
			x2 = msg2.x - 500.0;  //坐标换算
			y2 = msg2.y - 20.0;   //坐标换算
			break;
		}
	}
	data[graphcount].coord[0].x = x1;
	data[graphcount].coord[0].y = y1;
	data[graphcount].coord[1].x = x2;
	data[graphcount].coord[1].y = y2;
	data[graphcount].radius = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	circle(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].radius);
	reset(0); //重置画板属性
}

//用鼠标画填充函数
void mousepaintfillcircle()
{
	double x1, y1, x2, y2;
	mouse_msg msg1, msg2;
	data[graphcount].type = 2;
	data[graphcount].fillflag = 1;
	savegraphcolor();                                  //保存图形颜色
	setviewport(500, 20, 1440, 720);
	while (true)
	{
		msg1 = getmouse();
		if (msg1.is_left() && msg1.is_down())
		{
			x1 = msg1.x - 500.0;  //坐标换算
			y1 = msg1.y - 20.0;   //坐标换算
			break;
		}
	}
	while (true)
	{
		msg2 = getmouse();
		if (msg2.is_left() && msg2.is_down())
		{
			x2 = msg2.x - 500.0;  //坐标换算
			y2 = msg2.y - 20.0;   //坐标换算
			break;
		}
	}
	data[graphcount].coord[0].x = x1;
	data[graphcount].coord[0].y = y1;
	data[graphcount].coord[1].x = x2;
	data[graphcount].coord[1].y = y2;
	data[graphcount].radius = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	data[graphcount].stangle = 0;
	data[graphcount].endangle = 360;
	pieslice(data[graphcount].coord[0].x, data[graphcount].coord[0].y, 0, 360, data[graphcount].radius);
	reset(0); //重置画板属性
}

//用鼠标画空心矩形函数
void mousepaintrectangle()
{
	mouse_msg msg1, msg2;
	data[graphcount].type = 3;
	savegraphcolor();                                  //保存图形颜色
	setviewport(500, 20, 1440, 720);
	while (true)
	{
		msg1 = getmouse();
		if (msg1.is_left() && msg1.is_down())
		{
			data[graphcount].coord[0].x = msg1.x - 500;  //坐标换算
			data[graphcount].coord[0].y = msg1.y - 20;   //坐标换算
			break;
		}
	}
	while (true)
	{
		msg2 = getmouse();
		if (msg2.is_left() && msg2.is_down())
		{
			data[graphcount].coord[1].x = msg2.x - 500;  //坐标换算
			data[graphcount].coord[1].y = msg2.y - 20;   //坐标换算
			break;
		}
	}
	rectangle(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].coord[1].x, data[graphcount].coord[1].y);
	reset(0); //重置画板属性	
}

//用鼠标画填充矩形函数
void mousepaintbar()
{
	mouse_msg msg1, msg2;
	data[graphcount].type = 3;
	data[graphcount].fillflag = 1;
	savegraphcolor();                                  //保存图形颜色
	setviewport(500, 20, 1440, 720);
	while (true)
	{
		msg1 = getmouse();
		if (msg1.is_left() && msg1.is_down())
		{
			data[graphcount].coord[0].x = msg1.x - 500;  //坐标换算
			data[graphcount].coord[0].y = msg1.y - 20;   //坐标换算
			break;
		}
	}
	while (true)
	{
		msg2 = getmouse();
		if (msg2.is_left() && msg2.is_down())
		{
			data[graphcount].coord[1].x = msg2.x - 500;  //坐标换算
			data[graphcount].coord[1].y = msg2.y - 20;   //坐标换算
			break;
		}
	}
	bar(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].coord[1].x, data[graphcount].coord[1].y);
	reset(0); //重置画板属性
}