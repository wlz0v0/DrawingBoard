/*本文件中存储画板和鼠标画图操作中通用的函数
* 包括清除部分文字、清除图画部分、重画、重置函数
*/

#include <graphics.h>
#include "datasave.h"

extern unsigned int graphcount;

//本函数功能为清除一部分文字
void clearword()
{
	int fillcolor;                          //fillcolor变量用于保存之前设置的填充色
	setviewport(0, 280, 460, 720);          //将视图区域设置在下半部文字区域
	clearviewport();                        //清空视图区域
	fillcolor = getfillcolor();             //保存之前设置的填充色
	setfillcolor(WHITE);                    //设置填充色为白色
	bar(0, 0, 460, 440);                    //在视图区域画一个白色填充矩形使背景保持白色
	setviewport(0, 0, 1440, 720);           //将视图区域设置为整个画板
	setfillcolor(fillcolor);                //恢复填充色为之前的颜色
}

//本函数用于清除图画部分
void clearpainting()
{
	setviewport(500, 20, 1440, 720);        //将视图区域设置在画图区域
	clearviewport();                        //清空视图区域
	setfillcolor(WHITE);                    //设置填充色为白色
	bar(0, 0, 1440, 720);                   //在视图区域画一个白色填充矩形使背景保持白色
	setviewport(0, 0, 1440, 720);           //将视图区域设置为整个画板
}

//重画函数
void repaint()
{
	xyprintf(0, 280, "确认要重画吗？之前保存的图形全部会被清除！");
	xyprintf(0, 300, "1.确认");
	xyprintf(0, 320, "2.再想想（键盘输入）");
	int msg = getch();
	if (msg == '1')
	{
		clearpainting();    //重画时清除图画内容
		dataclear();        //重画时清除保存的图形数据
		clearword();        //清除提示文字
	}
	if (msg == '2')
	{
		clearword();        //清除提示文字
	}
}

/*本函数用于在画图后重置画板的视图区域、颜色、填充色，顺便把图形个数+1
* kbflag是用于判断是键盘画图还是鼠标画图，因为鼠标画图不重置颜色，而键盘画图需要重置
* 1为键盘画图，0为鼠标画图
*/
void reset(int kbflag)
{
	if (kbflag == 1)
	{
		setviewport(0, 0, 1440, 720);//恢复视图区域为初始
		setcolor(BLACK);      //把字体颜色恢复为黑色
		setfillcolor(WHITE);  //把填充颜色恢复为画板背景色
		graphcount++;         //图形个数+1 
	}
	else
	{
		setviewport(0, 0, 1440, 720);//恢复视图区域为初始
		graphcount++;         //图形个数+1 
	}
}

//本函数用于设置图形的颜色（前景色+填充色）
void Setgraphcolor(int r, int g, int b)
{
	setcolor(EGERGB(r, g, b));
	setfillcolor(EGERGB(r, g, b));
}