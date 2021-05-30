#include <vector>
#include <graphics.h>
#include <iterator>
#include <algorithm>
#include "drawingBoard.h"

std::vector<ButtonBase*> DrawingBoard::buttons;
//bool isExit = false;

DrawingBoard::DrawingBoard() :
	redButton(Point(20, 20), Point(40, 40), Color::colorset[0]),
	orangeButton(Point(45, 20), Point(65, 40), Color::colorset[1]),
	yellowButton(Point(70, 20), Point(90, 40), Color::colorset[2]),
	greenButton(Point(95, 20), Point(115, 40), Color::colorset[3]),
	cyanButton(Point(120, 20), Point(140, 40), Color::colorset[4]),
	skyBlueButton(Point(145, 20), Point(165, 40), Color::colorset[5]),
	blueButton(Point(170, 20), Point(190, 40), Color::colorset[6]),
	violetButton(Point(195, 20), Point(215, 40), Color::colorset[7]),
	blackButton(Point(220, 20), Point(240, 40), Color::colorset[8]),
	pinkButton(Point(20, 45), Point(40, 65), Color::colorset[9]),
	goldenButton(Point(45, 45), Point(65, 65), Color::colorset[10]),
	lightYellowButton(Point(70, 45), Point(90, 65), Color::colorset[11]),
	limeButton(Point(95, 45), Point(115, 65), Color::colorset[12]),
	lightYellowGreenButton(Point(120, 45), Point(140, 65), Color::colorset[13]),
	blueGreyButton(Point(145, 45), Point(165, 65), Color::colorset[14]),
	lightVioletButton(Point(170, 45), Point(190, 65), Color::colorset[15]),
	brownButton(Point(195, 45), Point(215, 65), Color::colorset[16]),
	lineButton(Point(20, 80), Point(80, 140)),
	circleButton(Point(230, 80), Point(290, 140), false),
	fillCircleButton(Point(300, 80), Point(360, 140), true),
	rectangleButton(Point(90, 80), Point(150, 140), false),
	fillRectangleButton(Point(160, 80), Point(220, 140), true),
	exitButton(Point(280, 160), Point(360, 200)),
	clearButton(Point(10, 160), Point(90, 200)),
	cancelButton(Point(300, 25), Point(340, 65)),
	restoreButton(Point(350, 25), Point(390, 65)),
	readButton(Point(100, 160), Point(180, 200)),
	writeButton(Point(190, 160), Point(270, 200)),
	canvas()
{
	buttons = {
		&redButton,
		&orangeButton,
		&yellowButton,
		&greenButton,
		&cyanButton,
		&skyBlueButton,
		&blueButton,
		&violetButton,
		&blackButton,
		&pinkButton,
		&goldenButton,
		&lightYellowButton,
		&limeButton,
		&lightYellowGreenButton,
		&blueGreyButton,
		&lightVioletButton,
		&brownButton,
		&lineButton,
		&circleButton,
		&fillCircleButton,
		&rectangleButton,
		&fillRectangleButton,
		&exitButton,
		&clearButton,
		&cancelButton,
		&restoreButton,
		&readButton,
		&writeButton
	};
}

void DrawingBoard::initialize()
{
	//初始化界面和设置
	initgraph(1440, 720);                                          //设置画板大小
	setcaption("托马斯小火车画板（1440*720，有效大小为920*680)");     //设置画板名称
	setbkcolor(WHITE);                                             //设置背景颜色
	setcolor(BLACK);                                               //设置字体颜色
	setfont(16, 0, "楷体");                                        //设置字体样式
	setfillcolor(WHITE);

	line(499, 20, 499, 720);                                       //打印一条竖线分隔画图区域
	line(499, 19, 1440, 19);                                       //打印一条横线分隔画图区域
	//以下打印坐标基本点                           
	int coordinate;
	for (coordinate = 0; coordinate <= 940; coordinate += 40)
	{
		setviewport(500, 0, 1440, 720);
		xyprintf(coordinate, 0, "%d", coordinate);              //打印横坐标
		setviewport(0, 20, 1440, 720);
		xyprintf(470, coordinate, "%d", coordinate);            //打印纵坐标
	}
	setviewport(0, 0, 1440, 720);

	//初始化按钮
	for (auto it = buttons.begin(); it != buttons.end(); it++)
	{
		(*it)->init();
	}

	//打印提示语句
	setfont(16, 0, "楷体");
	setcolor(RED);
	xyprintf(0, 270, "退出时请不要点击右上角的×，请点击画板内部的退出键！");
	xyprintf(0, 300, "本画板使用鼠标画图时，默认颜色和填充色均为黑色；");
	xyprintf(0, 330, "点击各个边框内可以进行操作；");
	xyprintf(0, 360, "右上角两个箭头，左边是撤销右边是复原；");
	xyprintf(0, 390, "画图时需点击鼠标左键两次：");
	xyprintf(0, 420, "1.画直线时，选取两点，在两点之间画直线；");
	xyprintf(0, 450, "2.画圆时，第一次选取圆心，第二点与第一点之间的距离为半径；");
	xyprintf(0, 480, "3.画矩形时，选取两点，以这两个点分别为矩形的对角线的点。");
	setcolor(BLACK);
	xyprintf(380, 110, "直线");
}

void DrawingBoard::chooseOperations()
{
	mouse_msg choice;
	//isExit = false;
	while (true)
	{
		choice = getmouse();
		if (choice.is_down() && choice.is_left())
		{
			// 利用find_if函数和lambda表达式判断按钮是否被点击
			auto it = std::find_if(buttons.begin(),
				buttons.end(),
				[&choice](ButtonBase* aButton) { return aButton->isClicked(choice); });
			if (it != buttons.end())
				(*it)->operation();
			if (canvas.isClicked(choice))
				canvas.operation(choice);
			/*for (auto it = buttons.begin(); it != buttons.end(); it++)
			{
				if ((*it)->isClicked(choice))
				{
					(*it)->operation();
					break;
				}
			}*/
		}

		/*if (isExit)
		{
			return;
		}*/
	}
}

void DrawingBoard::exit()
{
	//clearBuffer(); // 清空缓冲区
	//clearShapes(); // 清空形状
	//closegraph();  // 退出画板
}
