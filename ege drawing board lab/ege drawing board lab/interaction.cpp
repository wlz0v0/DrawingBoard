/*本文件中存储初始化函数、读取文件函数、根据读取文件的结果显示键盘菜单
*键盘作图函数、鼠标操作初始化图片部分函数、鼠标操作初始化文本部分函数
*根据读取文件的结果显示键盘菜单、键盘作图函数。
*/

#include <graphics.h>
#include "interaction.h"
#include "kbpaint_support.h"
#include "mousepaint_support.h"
#include "allpaint_support.h"
#include "datasave.h"

extern unsigned int cancelcount;               //计算撤销次数的变量，在datasave.cpp中存储
extern DATA data[20];                          //结构体数组，用于存储所有图形的数据，在datasave.cpp中存储

//本函数为初始化函数
void initialize()
{
	//初始化界面和设置
	initgraph(1440, 720);                                          //设置画板大小
	setcaption("托马斯小火车画板（1440*720，有效大小为920*680)");     //设置画板名称
	setbkcolor(WHITE);                                             //设置背景颜色
	setcolor(BLACK);                                               //设置字体颜色
	setfont(60, 0, "楷体");                                        //设置字体样式
	xyprintf(350, 200, "请问您使用鼠标还是键盘？");
	xyprintf(350, 270, "1.鼠标");
	xyprintf(350, 340, "2.键盘");
	setfont(16, 0, "楷体");                                        //设置字体样式
	int mouseflag = getch();                                       //获取用户的选择
	cleardevice();

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

	if (mouseflag == '1')
	{
		mousemenu();       //显示鼠标操作菜单
	}
	else if (mouseflag == '2')
	{
		kbmenu();          //显示键盘操作菜单
	}
	else                   //检查错误并处理
	{
		cleardevice();     //把上面打印的坐标点和两条线清掉
		setfont(60, 0, "楷体");
		xyprintf(400, 200, "Error!!!!!!!!!");
		xyprintf(400, 350, "按任意键退出画板。");//简单粗暴的解决方式XD
		getch();
	}
}

//本函数用于读取文件，成功返回1，否则返回0
int readFile(void)
{
	xyprintf(0, 10, "欢迎您进入托马斯小火车画板，请根据菜单选择您想进行的操作：");
	xyprintf(0, 30, "1.读取文件");
	xyprintf(0, 50, "2.不读取文件");
	xyprintf(0, 70, "请输入您的选择：");
	//询问用户是否读取之前的信息储存文件

	int keyboardmsg = getch();
	if (keyboardmsg == '1')
	{
		return 1;
	}
	else return 0;
}

//本函数为画图函数
void kbpainting()
{
	cancelcount = 0;                           //开始画图时撤销次数为0
	int keyboardmsg1, keyboardmsg2, fillflag;  //fillflag为判断是否填充的变量，等于0为不填充，等于1为填充
	//选择颜色
	xyprintf(0, 280, "请选择您需要的颜色：");
	xyprintf(0, 300, "1.红色");
	xyprintf(0, 320, "2.蓝色");
	xyprintf(0, 340, "3.黑色");
	xyprintf(0, 360, "4.绿色");
	xyprintf(0, 380, "5.自定义");

	//设置颜色
	keyboardmsg1 = getch();
	switch (keyboardmsg1)
	{
	case '1':
		setcolor(EGERGB(255, 0, 0));       //颜色设置为红色
		setfillcolor(EGERGB(255, 0, 0));   //填充色设置为红色
		clearword();                       //清除部分文字提示
		break;
	case '2':
		setcolor(EGERGB(0, 0, 255));       //颜色设置为蓝色
		setfillcolor(EGERGB(0, 0, 255));   //填充色设置为蓝色
		clearword();                       //清除部分文字提示
		break;
	case '3':
		setcolor(EGERGB(0, 0, 0));         //颜色设置为黑色   
		setfillcolor(EGERGB(0, 0, 0));     //填充色设置为黑色
		clearword();                       //清除部分文字提示
		break;
	case '4':
		setcolor(EGERGB(0, 255, 0));       //颜色设置为绿色
		setfillcolor(EGERGB(0, 255, 0));   //填充色设置为绿色
		clearword();                       //清除部分文字提示
		break;
	case '5':
		rgbcolor();                        //根据用户输入自定义颜色函数
		clearword();                       //清除部分文字提示
		break;
	}

	//询问是否填充图形
	xyprintf(0, 280, "是否填充？（直线不可填充）");
	xyprintf(0, 300, "1.是");
	xyprintf(0, 320, "2.否");
	fillflag = getch();                     //获取是否填充的结果
	clearword();

	//选择所需要的图形
	xyprintf(0, 280, "请选择您需要的图形：");
	xyprintf(0, 300, "1.直线");
	xyprintf(0, 320, "2.圆形");
	xyprintf(0, 340, "3.矩形");
	xyprintf(0, 360, "4.弧线");
	xyprintf(0, 380, "5.多边形");

	//设置所需要的图形
	keyboardmsg2 = getch();
	switch (keyboardmsg2)
	{
	case '1':
		paintline();      //根据用户输入自定义直线
		clearword();      //清除部分文字提示
		break;
	case '2':
		if (fillflag == '1')
		{
			paintfillcircle();     //根据用户输入自定义填充圆
		}
		else { paintcircle(); }    //根据用户输入自定义空心圆
		clearword();               //清除部分文字提示
		break;
	case '3':
		if (fillflag == '1')
		{
			paintbar();            //根据用户输入自定义填充矩形
		}
		else { paintrectangle(); } //根据用户输入自定义空心矩形
		clearword();               //清除部分文字提示
		break;
	case '4':
		if (fillflag == '1')
		{
			paintpieslice();       //根据用户输入自定义填充扇形
		}
		else { paintarc(); }       //根据用户输入自定义弧线
		clearword();               //清除部分文字提示
		break;
	case '5':
		if (fillflag == '1')
		{
			paintfillpoly();       //根据用户输入自定义填充多边形
		}
		else { paintdrawpoly(); }  //根据用户输入自定义空心多边形
		clearword();               //清除部分文字提示
		break;
	}
}

//根据读取文件的结果显示键盘操作菜单
void kbmenu()
{
	//以下打印提醒用户使用英文输入法
	setcolor(RED);
	xyprintf(200, 30, "WARNING!");
	xyprintf(150, 50, "本画板必须使用英文输入法，");
	xyprintf(150, 70, "否则会引起异常！");
	setcolor(BLACK);

	int readflag = readFile();
	if (readflag == 1)
	{
		xyprintf(0, 90, "读取成功！");
		readFromFile();
		restore();
	}
	else
	{
		xyprintf(0, 90, "文件未被读取");
	}

	//用户根据菜单提示进行操作
	xyprintf(0, 130, "欢迎您进入托马斯小火车画板，请根据菜单选择您想进行的操作：");
	xyprintf(0, 150, "1.清除屏幕");
	xyprintf(0, 170, "2.作画");
	xyprintf(0, 190, "3.退出");
	xyprintf(0, 210, "4.撤销 5.恢复");
	xyprintf(0, 230, "6.保存图像至文件 7.重画");
	xyprintf(0, 250, "请输入您的选择：");

	while (true)
	{
		bool flag = false;      //控制退出画板
		int keyboardmsg = getch();

		switch (keyboardmsg)
		{
		case '1':
			clearpainting();    //只清除图画内容的函数
			break;
		case '2':
			kbpainting();        //键盘画图函数
			break;
		case '3':
			flag = true;        //退出画板
			break;
		case '4':
			cancel();           //撤销函数
			break;
		case '5':
			restore();          //复原函数（与撤销函数相对应）
			break;
		case '6':
			writeToFile(data);  //将数据保存到文件中的函数
			break;
		case '7':
			repaint();          //重画函数
			break;
		}

		if (flag)	break;      //case 3中flag为true则跳出循环退出画板
	}
}

//本函数为鼠标输入界面初始化函数，主要打印图形
void mousepaintinit_graph()
{
	int i;
	constexpr int colorset[17][3] = { //这个二维数组存放的是各种颜色的RGB值，便于后面打印
		{255, 0, 0},      //红色
		{255, 97, 0},     //橙色
		{255, 255, 0},    //黄色
		{0, 255, 0},      //绿色
		{0, 255, 255},    //青色
		{135, 206, 235},  //天蓝色
		{0, 0, 255},      //蓝色
		{128, 0, 255},    //紫色
		{0, 0, 0},        //黑色
		{242, 156, 177},  //粉色
		{255, 201, 14},   //金色
		{239, 228, 176},  //浅黄色
		{181, 230, 29},   //酸橙色
		{153, 217, 234},  //淡青绿色
		{112, 146, 190},  //蓝灰色
		{200, 191, 231},  //浅紫色
		{185, 122, 87},   //棕色
	};

	//以下打印色块
	for (i = 0; i < 17; i++)
	{
		setfillcolor(EGERGB(colorset[i][0], colorset[i][1], colorset[i][2]));
		if (i < 9)//第一行
		{ 
			bar(20 + 25 * i, 20, 40 + 25 * i, 40);            //打印填充矩形作为可选取的色块
		}
		else      //第二行
		{
			bar(20 + 25 * (i - 9), 45, 40 + 25 * (i - 9), 65);//打印填充矩形作为可选取的色块
		}
	}
	setfillcolor(WHITE);//白色
	rectangle(220, 45, 240, 65);//打印个黑色边框作为白色的色块，其实没啥用，后面也没加可选取白色，加了画板背景也是白的，啥都看不见
	setfont(40, 0, "楷体");
	setcolor(BLACK);
	xyprintf(300, 25, "<-");//撤销键
	rectangle(300, 25, 340, 65);
	xyprintf(350, 25, "->");//恢复键
	rectangle(350, 25, 390, 65);

	//以下打印的是选择要画的图形区域
	rectangle(20, 80, 80, 140);
	setcolor(BLUE);
	line(25, 85, 75, 135);         //画直线选项块
	rectangle(90, 80, 150, 140);   //画矩形选项块
	setcolor(BLACK);
	setfillcolor(BLUE);
	bar(160, 80, 220, 140);        //画填充矩形选项块
	setcolor(BLACK);
	rectangle(230, 80, 290, 140);
	setcolor(BLUE);
	circle(260, 110, 25);          //画圆形选项块
	setcolor(BLACK);
	rectangle(300, 80, 360, 140);
	setcolor(BLUE);
	setfillcolor(BLUE);
	pieslice(330, 110, 0, 360, 25);//画填充圆形选项块
	setcolor(BLACK);
	setfillcolor(WHITE);
}

//本函数为鼠标输入界面初始化函数，主要打印文本
void mousepaintinit_text()
{
	//以下打印各种操作的选项块
	xyprintf(10, 160, "读取");
	rectangle(10, 160, 90, 200);
	xyprintf(100, 160, "重画");
	rectangle(100, 160, 180, 200);
	xyprintf(190, 160, "保存");
	rectangle(190, 160, 270, 200);
	xyprintf(280, 160, "清屏");
	rectangle(280, 160, 360, 200);
	xyprintf(370, 160, "退出");
	rectangle(370, 160, 450, 200);

	//以下打印提示语句
	setfont(16, 0, "楷体");
	setcolor(RED);
	xyprintf(0, 300, "本画板使用鼠标画图时，默认颜色和填充色均为黑色；");
	xyprintf(0, 330, "点击各个边框内可以进行操作；");
	xyprintf(0, 360, "右上角两个箭头，左边是撤销右边是复原；");
	xyprintf(0, 390, "画图时需点击鼠标左键两次：");
	xyprintf(0, 420, "1.画直线时，选取两点，在两点之间画直线；");
	xyprintf(0, 450, "2.画圆时，第一次选取圆心，第二点与第一点之间的距离为半径；");
	xyprintf(0, 480, "3.画矩形时，选取两点，以这两个点分别为矩形的对角线的点。");
	setcolor(BLACK);
}

//显示鼠标操作菜单
void mousemenu()
{
	mousepaintinit_graph();
	mousepaintinit_text();
	mousepainting();
}

/*鼠标作图函数
*（分支有点多，我自己都不想看了T_T，没用switch是觉得用了也是这么多，没简洁到哪去XD）
* （200多行的函数也是没谁了:( , 简化也不知道怎么简化)
* （我麻了）
*/
void mousepainting()
{
	while (true)
	{
		bool flag = false;
		mouse_msg msg1 = getmouse();
		if (msg1.is_left() && msg1.is_down())//判断鼠标左键是否按下
		{
			int x_flag = msg1.x;
			int y_flag = msg1.y;
			if ((x_flag <= 90 && x_flag >= 10) && (y_flag <= 200 && y_flag >= 160))      //读取模块
			{
				readFromFile();
				restore();
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "读取成功！");
			}
			else if ((x_flag <= 180 && x_flag >= 100) && (y_flag <= 200 && y_flag >= 160))//重画模块
			{
				setviewport(0, 230, 1440, 720);//设置视图区域是为了让repaint函数里面打印的文字能打印在指定的位置上
				repaint();                     //这个函数会清除一些文字内容
				setcolor(RED);
				setviewport(0, 0, 1440, 720);
				xyprintf(0, 300, "本画板使用鼠标画图时，默认颜色和填充色均为黑色；");//打印本段语句的原因是repaint会清除这段文字内容（我吐了），因此在repaint函数后再打印一遍
				xyprintf(0, 330, "点击各个边框内可以进行操作（先颜色后图形）；");
				xyprintf(0, 360, "右上角两个箭头，左边是撤销右边是复原；");
				xyprintf(0, 390, "画图时需点击鼠标左键两次：");
				xyprintf(0, 420, "1.画直线时，选取两点，在两点之间画直线；");
				xyprintf(0, 450, "2.画圆时，第一次选取圆心，第二点与第一点之间的距离为半径；");
				xyprintf(0, 480, "3.画矩形时，选取两点，以这两个点分别为矩形的对角线的点。");
				setcolor(BLACK);
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "重画成功！");
			}
			else if ((x_flag <= 270 && x_flag >= 190) && (y_flag <= 200 && y_flag >= 160))//保存模块
			{
				writeToFile(data);
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "保存成功！");
			}
			else if ((x_flag <= 360 && x_flag >= 280) && (y_flag <= 200 && y_flag >= 160))//清屏模块
			{
				clearpainting();
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "清除成功！");
			}
			else if ((x_flag <= 450 && x_flag >= 370) && (y_flag <= 200 && y_flag >= 160))//退出模块
			{
				flag = true;
			}
			else if ((x_flag <= 80 && x_flag >= 20) && (y_flag <= 140 && y_flag >= 80))   //画直线模块
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "选择直线成功！");
				mousepaintline();
			}
			else if ((x_flag <= 150 && x_flag >= 90) && (y_flag <= 140 && y_flag >= 80))   //画空心矩形模块
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "选择空心矩形成功！");
				mousepaintrectangle();
			}
			else if ((x_flag <= 220 && x_flag >= 160) && (y_flag <= 140 && y_flag >= 80))   //画填充矩形模块
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "选择填充矩形成功！");
				mousepaintbar();
			}
			else if ((x_flag <= 290 && x_flag >= 230) && (y_flag <= 140 && y_flag >= 80))   //画空心圆模块
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "选择空心圆成功！");
				mousepaintcircle();
			}
			else if ((x_flag <= 360 && x_flag >= 300) && (y_flag <= 140 && y_flag >= 80))   //画填充圆模块
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "选择填充圆成功！");
				mousepaintfillcircle();
			}
			else if ((x_flag <= 40 && x_flag >= 20) && (y_flag <= 40 && y_flag >= 20))       //红色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(255, 0, 0);
				xyprintf(0, 510, "选择红色成功！");
			}
			else if ((x_flag <= 65 && x_flag >= 45) && (y_flag <= 40 && y_flag >= 20))       //橙色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(255, 97, 0);
				xyprintf(0, 510, "选择橙色成功！");
			}
			else if ((x_flag <= 90 && x_flag >= 70) && (y_flag <= 40 && y_flag >= 20))       //黄色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(255, 255, 0);
				xyprintf(0, 510, "选择黄色成功！");
			}
			else if ((x_flag <= 115 && x_flag >= 95) && (y_flag <= 40 && y_flag >= 20))      //绿色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(0, 255, 0);
				xyprintf(0, 510, "选择绿色成功！");
			}
			else if ((x_flag <= 140 && x_flag >= 120) && (y_flag <= 40 && y_flag >= 20))      //青色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(0, 255, 255);
				xyprintf(0, 510, "选择青色成功！");
			}
			else if ((x_flag <= 165 && x_flag >= 145) && (y_flag <= 40 && y_flag >= 20))      //天蓝色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(135, 206, 235);
				xyprintf(0, 510, "选择天蓝色成功！");
			}
			else if ((x_flag <= 190 && x_flag >= 170) && (y_flag <= 40 && y_flag >= 20))      //蓝色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(0, 0, 255);
				xyprintf(0, 510, "选择蓝色成功！");
			}
			else if ((x_flag <= 215 && x_flag >= 195) && (y_flag <= 40 && y_flag >= 20))      //紫色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(128, 0, 255);
				xyprintf(0, 510, "选择紫色成功！");
			}
			else if ((x_flag <= 240 && x_flag >= 220) && (y_flag <= 40 && y_flag >= 20))      //黑色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(0, 0, 0);
				xyprintf(0, 510, "选择黑色成功！");
			}
			else if ((x_flag <= 40 && x_flag >= 20) && (y_flag <= 65 && y_flag >= 45))        //粉色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(242, 156, 177);
				xyprintf(0, 510, "选择粉色成功！");
			}
			else if ((x_flag <= 65 && x_flag >= 45) && (y_flag <= 65 && y_flag >= 45))        //金色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(255, 201, 14);
				xyprintf(0, 510, "选择金色成功！");
			}
			else if ((x_flag <= 90 && x_flag >= 70) && (y_flag <= 65 && y_flag >= 45))        //浅黄色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(239, 228, 176);
				xyprintf(0, 510, "选择浅黄色成功！");
			}
			else if ((x_flag <= 115 && x_flag >= 95) && (y_flag <= 65 && y_flag >= 45))       //酸橙色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(181, 230, 29);
				xyprintf(0, 510, "选择酸橙色成功！");
			}
			else if ((x_flag <= 140 && x_flag >= 120) && (y_flag <= 65 && y_flag >= 45))      //淡青绿色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(153, 217, 234);
				xyprintf(0, 510, "选择淡青绿色成功！");
			}
			else if ((x_flag <= 165 && x_flag >= 145) && (y_flag <= 65 && y_flag >= 45))      //蓝灰色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(112, 146, 190);
				xyprintf(0, 510, "选择蓝灰色成功！");
			}
			else if ((x_flag <= 190 && x_flag >= 170) && (y_flag <= 65 && y_flag >= 45))      //浅紫色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(200, 191, 231);
				xyprintf(0, 510, "选择浅紫色成功！");
			}
			else if ((x_flag <= 215 && x_flag >= 195) && (y_flag <= 65 && y_flag >= 45))       //棕色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				Setgraphcolor(185, 122, 87);
				xyprintf(0, 510, "选择棕色成功！");
			}
			else if ((x_flag <= 340 && x_flag >= 300) && (y_flag <= 65 && y_flag >= 25))       //撤销
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				cancel();
				xyprintf(0, 510, "撤销成功！");
			}
			else if ((x_flag <= 390 && x_flag >= 350) && (y_flag <= 65 && y_flag >= 25))       //复原
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				restore();
				xyprintf(0, 510, "复原成功！");
			}
		}
		if (flag) break;  //退出画板
	}
}