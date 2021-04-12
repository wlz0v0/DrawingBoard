#include <graphics.h>
#include "paintBoard.h"
#include "color.h"
#include "point.h"
#include "shape.h"

int main()
{
	PaintBoard pb;
	Line line;
	Circle circle;
	Rectangle_ rectangle;
	bool isFill = true;
	bool noFill = false;
	//是否读取的部分。
	pb.clearFile(filePath);
	pb.initialize();
	pb.initGraph();
	pb.initText();
	while (true)
	{
		mouse_msg msg1 = getmouse();
		if (msg1.is_left() && msg1.is_down())//判断鼠标左键是否按下
		{
			int x = msg1.x, y = msg1.y;
			if ((x <= 90 && x >= 10) && (y <= 200 && y >= 160))      //清除模块
			{
				pb.clearPaint();
				//清除tempfile.txt中保存的数据
				pb.clearFile(tempFilePath);
				pb.setGraphCount(0);
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "清除成功！");
			}
			else if ((x <= 450 && x >= 370) && (y <= 200 && y >= 160))//退出模块
			{
				break; // 跳出while循环，退出程序
			}
			else if ((x <= 80 && x >= 20) && (y <= 140 && y >= 80))   //画直线模块
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "选择直线成功！");
				pb.deleteCancelGraph();
				pb.paintGraph(line, noFill);
				pb.writeToFile(line, tempFilePath);
			}
			else if ((x <= 150 && x >= 90) && (y <= 140 && y >= 80))   //画空心矩形模块
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "选择空心矩形成功！");
				pb.deleteCancelGraph();
				pb.paintGraph(rectangle, noFill);
				pb.writeToFile(rectangle, tempFilePath);
			}
			else if ((x <= 220 && x >= 160) && (y <= 140 && y >= 80))   //画填充矩形模块
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "选择填充矩形成功！");
				pb.deleteCancelGraph();
				pb.paintGraph(rectangle, isFill);
				pb.writeToFile(rectangle, tempFilePath);
			}
			else if ((x <= 290 && x >= 230) && (y <= 140 && y >= 80))   //画空心圆模块
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "选择空心圆成功！");
				pb.deleteCancelGraph();
				pb.paintGraph(circle, noFill);
				pb.writeToFile(circle, tempFilePath);
			}
			else if ((x <= 360 && x >= 300) && (y <= 140 && y >= 80))   //画填充圆模块
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				xyprintf(0, 510, "选择填充圆成功！");
				pb.deleteCancelGraph();
				pb.paintGraph(circle, isFill);
				pb.writeToFile(circle, tempFilePath);
			}
			else if ((x <= 40 && x >= 20) && (y <= 40 && y >= 20))       //红色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[0]);
				xyprintf(0, 510, "选择红色成功！");
			}
			else if ((x <= 65 && x >= 45) && (y <= 40 && y >= 20))       //橙色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[1]);
				xyprintf(0, 510, "选择橙色成功！");
			}
			else if ((x <= 90 && x >= 70) && (y <= 40 && y >= 20))       //黄色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[2]);
				xyprintf(0, 510, "选择黄色成功！");
			}
			else if ((x <= 115 && x >= 95) && (y <= 40 && y >= 20))      //绿色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[3]);
				xyprintf(0, 510, "选择绿色成功！");
			}
			else if ((x <= 140 && x >= 120) && (y <= 40 && y >= 20))      //青色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[4]);
				xyprintf(0, 510, "选择青色成功！");
			}
			else if ((x <= 165 && x >= 145) && (y <= 40 && y >= 20))      //天蓝色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[5]);
				xyprintf(0, 510, "选择天蓝色成功！");
			}
			else if ((x <= 190 && x >= 170) && (y <= 40 && y >= 20))      //蓝色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[6]);
				xyprintf(0, 510, "选择蓝色成功！");
			}
			else if ((x <= 215 && x >= 195) && (y <= 40 && y >= 20))      //紫色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[7]);
				xyprintf(0, 510, "选择紫色成功！");
			}
			else if ((x <= 240 && x >= 220) && (y <= 40 && y >= 20))      //黑色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[8]);
				xyprintf(0, 510, "选择黑色成功！");
			}
			else if ((x <= 40 && x >= 20) && (y <= 65 && y >= 45))        //粉色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[9]);
				xyprintf(0, 510, "选择粉色成功！");
			}
			else if ((x <= 65 && x >= 45) && (y <= 65 && y >= 45))        //金色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[10]);
				xyprintf(0, 510, "选择金色成功！");
			}
			else if ((x <= 90 && x >= 70) && (y <= 65 && y >= 45))        //浅黄色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[11]);
				xyprintf(0, 510, "选择浅黄色成功！");
			}
			else if ((x <= 115 && x >= 95) && (y <= 65 && y >= 45))       //酸橙色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[12]);
				xyprintf(0, 510, "选择酸橙色成功！");
			}
			else if ((x <= 140 && x >= 120) && (y <= 65 && y >= 45))      //淡青绿色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[13]);
				xyprintf(0, 510, "选择淡青绿色成功！");
			}
			else if ((x <= 165 && x >= 145) && (y <= 65 && y >= 45))      //蓝灰色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[14]);
				xyprintf(0, 510, "选择蓝灰色成功！");
			}
			else if ((x <= 190 && x >= 170) && (y <= 65 && y >= 45))      //浅紫色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[15]);
				xyprintf(0, 510, "选择浅紫色成功！");
			}
			else if ((x <= 215 && x >= 195) && (y <= 65 && y >= 45))       //棕色
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				pb.setGraphColor(colorset[16]);
				xyprintf(0, 510, "选择棕色成功！");
			}
			else if ((x <= 340 && x >= 300) && (y <= 65 && y >= 25))       //撤销
			{
				
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				if (pb.cancel())
					xyprintf(0, 510, "撤销成功！");
			}
			else if ((x <= 390 && x >= 350) && (y <= 65 && y >= 25))       //复原
			{
				xyprintf(0, 510, "                            ");//清除前一次打印的文字
				if (pb.restore())
					xyprintf(0, 510, "复原成功！");
			}
		}
	}
	pb.writeToFile();
	pb.clearFile(tempFilePath);
	closegraph();
	return 0;
}