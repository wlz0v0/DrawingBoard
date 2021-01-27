/*本文件包含键盘操作画图的函数，有纠错函数、根据用户输入自定义颜色函数、
*根据用户输入自定义直线、圆、矩形（可填充）、圆弧、多边形（可填充）函数。
*/

#include <graphics.h>
#include "allpaint_support.h"
#include "datasave.h"

extern DATA data[20];                       //结构体数组，用于存储所有图形的数据，在datasave.cpp中存储
extern unsigned int graphcount;             //图形个数变量，在datasave.cpp中存储

/*本函数是纠错函数，对rgb颜色参数，x坐标和y坐标，半径，圆弧起始角，圆弧终止角，多边形顶点数进行纠错
*纠错方式：当输入数据超出范围时，显示数据超出范围，并再让用户重新输入一次 
*type变量：0为颜色，1为x坐标，2为y坐标，3为半径，4为圆弧起始角，5为圆弧终止角，6为多边形顶点数
*input变量：待检测的数据，其中颜色范围为0~255，x坐标范围为0~920，y坐标范围为0~680，半径范围为0~340，
*          起始角范围为0~360，终止角范围为0~360，多边形顶点数范围为3~9
*xyprintf_x变量：使用xyprintf打印提示语句时的x坐标
*xyprintf_y变量：使用xyprintf打印提示语句时的y坐标
*/
void inputcheck(int type, int *input, int xyprintf_x, int xyprintf_y)
{
	if (type == 0)//颜色
	{
		if (*input < 0 || *input > 255)
		{
			xyprintf(xyprintf_x, xyprintf_y, "数据超出范围，请按回车重新输入");      //打印提示
			getch();                                            //等待用户按回车
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//清除打印的提示
			*input = inputdata();                               //重新输入数据
		}
	}
	else if (type == 1)//x坐标
	{
		if (*input < 0 || *input > 920)
		{
			xyprintf(xyprintf_x, xyprintf_y, "数据超出范围，请按回车重新输入");      //打印提示
			getch();                                            //等待用户按回车
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//清除打印的提示
			*input = inputdata();                               //重新输入数据
		}
	}
	else if (type == 2)//y坐标
	{
		if (*input < 0 || *input > 680)
		{
			xyprintf(xyprintf_x, xyprintf_y, "数据超出范围，请按回车重新输入");      //打印提示
			getch();                                            //等待用户按回车
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//清除打印的提示
			*input = inputdata();                               //重新输入数据
		}
	}
	else if (type == 3)//圆和圆弧的半径
	{
		if (*input < 0 || *input > 340)
		{
			xyprintf(xyprintf_x, xyprintf_y, "数据超出范围，请按回车重新输入");      //打印提示
			getch();                                            //等待用户按回车
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//清除打印的提示
			*input = inputdata();                               //重新输入数据
		}
	}
	else if (type == 4)//起始角角度
	{
		if (*input < 0 || *input > 360)
		{
			xyprintf(xyprintf_x, xyprintf_y, "数据超出范围，请按回车重新输入");      //打印提示
			getch();                                            //等待用户按回车
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//清除打印的提示
			*input = inputdata();                               //重新输入数据
		}
	}
	else if (type == 5)//终止角角度
	{
		if (*input < 0 || *input > 360)
		{
			xyprintf(xyprintf_x, xyprintf_y, "数据超出范围，请按回车重新输入");      //打印提示
			getch();                                            //等待用户按回车
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//清除打印的提示
			*input = inputdata();                               //重新输入数据
		}
	}
	else if (type == 6)//多边形点数
	{
		if (*input < 3 || *input > 9)
		{
			xyprintf(xyprintf_x, xyprintf_y, "数据超出范围，请按回车重新输入");      //打印提示
			getch();                                            //等待用户按回车
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//清除打印的提示
			*input = inputdata();                               //重新输入数据
		}
	}
}

//本函数功能为根据用户自定义输入的RGB值进行调色
void rgbcolor()
{
	int red, green, blue;//red为EGERGB的r参数，green为EGERGB的g参数，blue为EGERGB的b参数
	xyprintf(0, 420, "请输入RGB的参数:");//打印提示语句
	xyprintf(0, 440, "R, G, B");
	xyprintf(0, 460, "请注意，参数最多三位数，每输完一个坐标请按回车");
	red = inputdata();                   //获取用户输入的r参数
	inputcheck(0, &red, 0, 480);          //检查输入是否正确
	xyprintf(0, 480, "red=%d", red);      //打印r参数的值
	green = inputdata();                 //获取用户输入的g参数
	inputcheck(0, &green, 0, 500);        //检查输入是否正确
	xyprintf(0, 500, "green=%d", green);  //打印g参数的值
	blue = inputdata();                  //获取用户输入的b参数
	inputcheck(0, &blue, 0, 520);         //检查输入是否正确
	xyprintf(0, 520, "blue=%d", blue);    //打印b参数的值
	Setgraphcolor(red, green, blue);      //设置图形颜色
}

//本函数功能为根据用户自定义输入的坐标画直线
void paintline()
{
	data[graphcount].type = 1;
	savegraphcolor();                                  //保存图形颜色
	xyprintf(0, 420, "请按顺序输入直线坐标:");           //打印提示语句
	xyprintf(0, 440, "x1, y1, x2, y2");
	xyprintf(0, 460, "请注意，参数最多三位数，每输完一个坐标请按回车");
	data[graphcount].coord[0].x = inputdata();             //获取用户输入的x1坐标 
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);    //检查输入是否正确
	xyprintf(0, 480, "x1=%d", data[graphcount].coord[0].x); //打印用户输入的x1坐标
	data[graphcount].coord[0].y = inputdata();             //获取用户输入的y1坐标
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);    //检查输入是否正确
	xyprintf(0, 500, "y1=%d", data[graphcount].coord[0].y); //打印用户输入的y1坐标
	data[graphcount].coord[1].x = inputdata();             //获取用户输入的x2坐标
	inputcheck(1, &data[graphcount].coord[1].x, 0, 520);    //检查输入是否正确
	xyprintf(0, 520, "x2=%d", data[graphcount].coord[1].x); //打印用户输入的x2坐标
	data[graphcount].coord[1].y = inputdata();             //获取用户输入的y2坐标
	inputcheck(2, &data[graphcount].coord[1].y, 0, 540);    //检查输入是否正确
	xyprintf(0, 540, "y2=%d", data[graphcount].coord[1].y); //打印用户输入的y2坐标
	setviewport(500, 20, 1440, 720);                        //把视图区域设置在画图区域
	line(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].coord[1].x, data[graphcount].coord[1].y);
	reset(1); //重置画板属性
}

//本函数功能为根据用户自定义输入的坐标画圆
void paintcircle()
{
	data[graphcount].type = 2;
	data[graphcount].fillflag = 0;
	savegraphcolor();                                  //保存图形颜色
	xyprintf(0, 420, "请按顺序输入圆的参数:");           //打印提示语句
	xyprintf(0, 440, "x, y, r");
	xyprintf(0, 460, "请注意，参数最多三位数，每输完一个坐标请按回车");
	data[graphcount].coord[0].x = inputdata();
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);//检查输入是否正确
	xyprintf(0, 480, "x=%d", data[graphcount].coord[0].x);
	data[graphcount].coord[0].y = inputdata();
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);//检查输入是否正确
	xyprintf(0, 500, "y=%d", data[graphcount].coord[0].y);
	data[graphcount].radius = inputdata();
	inputcheck(3, &data[graphcount].radius, 0, 520);//检查输入是否正确
	xyprintf(0, 520, "r=%d", data[graphcount].radius);
	setviewport(500, 20, 1440, 720);//设置视图区域为画图区域
	circle(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].radius);
	reset(1); //重置画板属性
}

//本函数功能为根据用户自定义输入的坐标画填充圆(实际上是画一个起始角为0，终止角为360的填充扇形)
void paintfillcircle()
{
	data[graphcount].type = 2;
	data[graphcount].fillflag = 1;
	savegraphcolor();                                  //保存图形颜色
	xyprintf(0, 420, "请按顺序输入圆的参数:");            //打印提示语句
	xyprintf(0, 440, "x, y, r");
	xyprintf(0, 460, "请注意，参数最多三位数，每输完一个坐标请按回车");
	data[graphcount].coord[0].x = inputdata();
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);//检查输入是否正确
	xyprintf(0, 480, "x=%d", data[graphcount].coord[0].x);
	data[graphcount].coord[0].y = inputdata();
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);//检查输入是否正确
	xyprintf(0, 500, "y=%d", data[graphcount].coord[0].y);
	data[graphcount].radius = inputdata();
	inputcheck(3, &data[graphcount].radius, 0, 520);    //检查输入是否正确
	xyprintf(0, 560, "r=%d", data[graphcount].radius);
	data[graphcount].stangle = 0;
	data[graphcount].endangle = 360;
	setviewport(500, 20, 1440, 720);//设置视图区域为画图区域
	pieslice(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].stangle, data[graphcount].endangle, data[graphcount].radius);
	reset(1); //重置画板属性
}

//本函数功能为根据用户自定义输入的坐标画空心矩形
void paintrectangle()
{
	data[graphcount].type = 3;
	data[graphcount].fillflag = 0;
	savegraphcolor();                                  //保存图形颜色
	xyprintf(0, 420, "请按顺序输入矩形坐标:");
	xyprintf(0, 440, "x1, y1, x2, y2");
	xyprintf(0, 460, "请注意，参数最多三位数，每输完一个坐标请按回车");
	data[graphcount].coord[0].x = inputdata();
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);//检查输入是否正确
	xyprintf(0, 480, "x1=%d", data[graphcount].coord[0].x);
	data[graphcount].coord[0].y = inputdata();
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);//检查输入是否正确
	xyprintf(0, 500, "y1=%d", data[graphcount].coord[0].y);
	data[graphcount].coord[1].x = inputdata();
	inputcheck(1, &data[graphcount].coord[1].x, 0, 520);//检查输入是否正确
	xyprintf(0, 520, "x2=%d", data[graphcount].coord[1].x);
	data[graphcount].coord[1].y = inputdata();
	inputcheck(2, &data[graphcount].coord[1].y, 0, 540);//检查输入是否正确
	xyprintf(0, 540, "y2=%d", data[graphcount].coord[1].y);
	setviewport(500, 20, 1440, 720);//设置视图区域为画图区域
	rectangle(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].coord[1].x, data[graphcount].coord[1].y);
	reset(1); //重置画板属性
}

//本函数功能为根据用户自定义输入的坐标画填充矩形
void paintbar()
{
	data[graphcount].type = 3;
	data[graphcount].fillflag = 1;
	savegraphcolor();                                  //保存图形颜色
	xyprintf(0, 420, "请按顺序输入矩形坐标:");
	xyprintf(0, 440, "x1, y1, x2, y2");
	xyprintf(0, 460, "请注意，参数最多三位数，每输完一个坐标请按回车");
	data[graphcount].coord[0].x = inputdata();
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);//检查输入是否正确
	xyprintf(0, 480, "x1=%d", data[graphcount].coord[0].x);
	data[graphcount].coord[0].y = inputdata();
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);//检查输入是否正确
	xyprintf(0, 500, "y1=%d", data[graphcount].coord[0].y);
	data[graphcount].coord[1].x = inputdata();
	inputcheck(1, &data[graphcount].coord[1].x, 0, 520);//检查输入是否正确
	xyprintf(0, 520, "x2=%d", data[graphcount].coord[1].x);
	data[graphcount].coord[1].y = inputdata();
	inputcheck(2, &data[graphcount].coord[1].y, 0, 540);//检查输入是否正确
	xyprintf(0, 540, "y2=%d", data[graphcount].coord[1].y);
	setviewport(500, 20, 1440, 720);//设置视图区域为画图区域
	bar(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].coord[1].x, data[graphcount].coord[1].y);
	reset(1); //重置画板属性
}

//本函数功能为根据用户自定义输入的坐标画圆弧
void paintarc()
{
	data[graphcount].type = 4;
	data[graphcount].fillflag = 0;
	savegraphcolor();                                  //保存图形颜色
	xyprintf(0, 420, "请按顺序输入圆弧的参数:");
	xyprintf(0, 440, "x, y, 起始角度, 终止角度, r");
	xyprintf(0, 460, "请注意，参数最多三位数，每输完一个坐标请按回车");
	data[graphcount].coord[0].x = inputdata();
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);//检查输入是否正确
	xyprintf(0, 480, "x=%d", data[graphcount].coord[0].x);
	data[graphcount].coord[0].y = inputdata();
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);//检查输入是否正确
	xyprintf(0, 500, "y=%d", data[graphcount].coord[0].y);
	data[graphcount].stangle = inputdata();
	inputcheck(4, &data[graphcount].stangle, 0, 520);//检查输入是否正确
	xyprintf(0, 520, "起始角度=%d°", data[graphcount].stangle);
	data[graphcount].endangle = inputdata();
	inputcheck(5, &data[graphcount].endangle, 0, 540);//检查输入是否正确
	xyprintf(0, 540, "终止角度=%d°", data[graphcount].endangle);
	data[graphcount].radius = inputdata();
	inputcheck(3, &data[graphcount].radius, 0, 560);//检查输入是否正确
	xyprintf(0, 560, "r=%d", data[graphcount].radius);
	setviewport(500, 20, 1440, 720);//设置视图区域为画图区域
	arc(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].stangle, data[graphcount].endangle, data[graphcount].radius);
	reset(1); //重置画板属性
}

//本函数功能为根据用户自定义输入的坐标画扇形
void paintpieslice()
{
	data[graphcount].type = 4;
	data[graphcount].fillflag = 1;
	savegraphcolor();                                  //保存图形颜色
	xyprintf(0, 420, "请按顺序输入圆弧的参数:");
	xyprintf(0, 440, "x, y, 起始角度, 终止角度, r");
	xyprintf(0, 460, "请注意，参数最多三位数，每输完一个坐标请按回车");
	data[graphcount].coord[0].x = inputdata();
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);//检查输入是否正确
	xyprintf(0, 480, "x=%d", data[graphcount].coord[0].x);
	data[graphcount].coord[0].y = inputdata();
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);//检查输入是否正确
	xyprintf(0, 500, "y=%d", data[graphcount].coord[0].y);
	data[graphcount].stangle = inputdata();
	inputcheck(4, &data[graphcount].stangle, 0, 520);//检查输入是否正确
	xyprintf(0, 520, "起始角度=%d°", data[graphcount].stangle);
	data[graphcount].endangle = inputdata();
	inputcheck(5, &data[graphcount].endangle, 0, 540);//检查输入是否正确
	xyprintf(0, 540, "终止角度=%d°", data[graphcount].endangle);
	data[graphcount].radius = inputdata();
	inputcheck(3, &data[graphcount].radius, 0, 560);//检查输入是否正确
	xyprintf(0, 560, "r=%d", data[graphcount].radius);
	setviewport(500, 20, 1440, 720);//设置视图区域为画图区域
	pieslice(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].stangle, data[graphcount].endangle, data[graphcount].radius);
	reset(1); //重置画板属性
}

//本函数功能为根据用户自定义输入的坐标画空心多边形
void paintdrawpoly()
{
	int i;
	data[graphcount].type = 5;
	data[graphcount].fillflag = 0;
	savegraphcolor();                                  //保存图形颜色
	xyprintf(0, 420, "请按顺序输入填充多边形的参数:");
	xyprintf(0, 440, "多边形顶点个数(最多九个)，顶点坐标");
	xyprintf(0, 460, "请注意，参数最多三位数，每输完一个坐标请按回车");
	data[graphcount].pointcount = getch();//输入多边形顶点数
	data[graphcount].pointcount = data[graphcount].pointcount - 48;//换算多边形顶点数
	inputcheck(6, &data[graphcount].pointcount, 0, 480);//检查输入是否正确
	xyprintf(0, 480, "顶点个数为%d", data[graphcount].pointcount);
	for (i = 0; i < data[graphcount].pointcount; i++)
	{
		data[graphcount].polycoord[2 * i] = inputdata();//输入多边形顶点的x坐标
		if ((500 + i * 40) <= 700)//判断打印内容是否超出画板，不超出则正常打印提示内容
		{
			inputcheck(1, &data[graphcount].polycoord[2 * i], 0, 500 + i * 40);//检查输入是否正确
			xyprintf(0, 500 + i * 40, "第%d个坐标x坐标为%d", i + 1, data[graphcount].polycoord[2 * i]);
		}
		else if ((500 + i * 40) > 700)//超出则在画板与用户交互界面右侧打印提示内容
		{
			inputcheck(1, &data[graphcount].polycoord[2 * i], 220, 300 + i * 40);//检查输入是否正确
			xyprintf(220, 300 + i * 40, "第%d个坐标x坐标为%d", i + 1, data[graphcount].polycoord[2 * i]);
		}
		data[graphcount].polycoord[2 * i + 1] = inputdata();//输入多边形顶点的y坐标
		if ((520 + i * 40) <= 700)//判断打印内容是否超出画板，不超出则正常打印提示内容
		{
			inputcheck(2, &data[graphcount].polycoord[2 * i], 0, 520 + i * 40);//检查输入是否正确
			xyprintf(0, 520 + i * 40, "第%d个坐标y坐标为%d", i + 1, data[graphcount].polycoord[2 * i + 1]);
		}
		else if ((520 + i * 40) > 700)//超出则在画板与用户交互界面右侧打印提示内容
		{
			inputcheck(2, &data[graphcount].polycoord[2 * i], 220, 320 + i * 40);//检查输入是否正确
			xyprintf(220, 320 + i * 40, "第%d个坐标y坐标为%d", i + 1, data[graphcount].polycoord[2 * i + 1]);
		}
	}
	setviewport(500, 20, 1440, 720);//设置视图区域为画图区域
	drawpoly(data[graphcount].pointcount, data[graphcount].polycoord);
	reset(1); //重置画板属性
}

//本函数功能为根据用户自定义输入的坐标画填充多边形
void paintfillpoly()
{
	int i;
	data[graphcount].type = 5;
	data[graphcount].fillflag = 1;
	savegraphcolor();                                  //保存图形颜色
	xyprintf(0, 420, "请按顺序输入填充多边形的参数:");
	xyprintf(0, 440, "多边形顶点个数，顶点坐标");
	xyprintf(0, 460, "请注意，参数最多三位数，每输完一个坐标请按回车");
	data[graphcount].pointcount = getch();//输入多边形顶点数
	data[graphcount].pointcount = data[graphcount].pointcount - 48;//换算多边形顶点数
	inputcheck(6, &data[graphcount].pointcount, 0, 480);//检查输入是否正确
	xyprintf(0, 480, "顶点个数为%d", data[graphcount].pointcount);
	for (i = 0; i < data[graphcount].pointcount; i++)
	{
		data[graphcount].polycoord[2 * i] = inputdata();//输入多边形顶点的x坐标
		if ((500 + i * 40) <= 700)//判断打印内容是否超出画板，不超出则正常打印提示内容
		{
			inputcheck(1, &data[graphcount].polycoord[2 * i], 0, 500 + i * 40);//检查输入是否正确
			xyprintf(0, 500 + i * 40, "第%d个坐标x坐标为%d", i + 1, data[graphcount].polycoord[2 * i]);
		}
		else if ((500 + i * 40) > 700)//超出则在画板与用户交互界面右侧打印提示内容
		{
			inputcheck(1, &data[graphcount].polycoord[2 * i], 220, 300 + i * 40);//检查输入是否正确
			xyprintf(220, 300 + i * 40, "第%d个坐标x坐标为%d", i + 1, data[graphcount].polycoord[2 * i]);
		}
		data[graphcount].polycoord[2 * i + 1] = inputdata();//输入多边形顶点的y坐标
		if ((520 + i * 40) <= 700)//判断打印内容是否超出画板，不超出则正常打印提示内容
		{
			inputcheck(2, &data[graphcount].polycoord[2 * i], 0, 520 + i * 40);//检查输入是否正确
			xyprintf(0, 520 + i * 40, "第%d个坐标y坐标为%d", i + 1, data[graphcount].polycoord[2 * i + 1]);
		}
		else if ((520 + i * 40) > 700)//超出则在画板与用户交互界面右侧打印提示内容
		{
			inputcheck(2, &data[graphcount].polycoord[2 * i], 220, 320 + i * 40);//检查输入是否正确
			xyprintf(220, 320 + i * 40, "第%d个坐标y坐标为%d", i + 1, data[graphcount].polycoord[2 * i + 1]);
		}
	}
	setviewport(500, 20, 1440, 720);//设置视图区域为画图区域
	fillpoly(data[graphcount].pointcount, data[graphcount].polycoord);
	reset(1); //重置画板属性
}