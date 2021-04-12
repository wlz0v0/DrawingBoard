#include <graphics.h>
#include <fstream>
#include <string>
#include "paintBoard.h"

using std::endl;
namespace fs = std::filesystem;

size_t PaintBoard::cancelCount = 0;
size_t PaintBoard::graphCount = 0;
const fs::path tempFilePath("tempfile.txt");
const fs::path filePath("file.txt");

void PaintBoard::initialize()
{
	//初始化界面和设置
	initgraph(1440, 720);                                          //设置画板大小
	setcaption("托马斯小火车画板（1440*720，有效大小为920*680)");     //设置画板名称
	setbkcolor(WHITE);                                             //设置背景颜色
	setcolor(BLACK);                                               //设置字体颜色
	setfont(60, 0, "楷体");                                        //设置字体样式
	xyprintf(350, 200, "是否读取文件？");
	xyprintf(350, 270, "1.是");
	xyprintf(350, 340, "2.否");
	int msg = getch();
	if (msg == '1')
		readFromFile();

	cleardevice();
	setfont(16, 0, "楷体");                                        //设置字体样式
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
}

void PaintBoard::initGraph()
{
	//以下打印色块
	for (int i = 0; i < 17; i++)
	{
		setGraphColor(colorset[i]);
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
	setcolor(BLACK);
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

void PaintBoard::initText()
{
	//以下打印各种操作的选项块
	xyprintf(10, 160, "清屏");
	rectangle(10, 160, 90, 200);
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

void PaintBoard::setGraphCount(size_t graphCount_)
{
	graphCount = graphCount_;
}

void PaintBoard::clearPaint()
{
	//清除图画内容
	color_t fillcolor = getfillcolor();
	setviewport(500, 20, 1440, 720);        //将视图区域设置在画图区域
	clearviewport();                        //清空视图区域
	setfillcolor(WHITE);                    //设置填充色为白色
	bar(0, 0, 1440, 720);                   //在视图区域画一个白色填充矩形使背景保持白色
	setviewport(0, 0, 1440, 720);           //将视图区域设置为整个画板
	setfillcolor(fillcolor);
}

void PaintBoard::paintGraph(Shape& shape, bool isFill_)
{
	mouse_msg msg1, msg2;
	shape.setIsFill(isFill_);
	shape.setColor(Color(EGEGET_R(getcolor()),
		EGEGET_G(getcolor()),
		EGEGET_B(getcolor())));
	while (true)
	{
		msg1 = getmouse();
		if (msg1.is_left() && msg1.is_down())
		{
			shape.setPt1(msg1.x - 500, msg1.y - 20); //坐标换算
			if (shape.getPt1() > Point(0, 0))
				break;
			xyprintf(0, 510, "选点必须在可画区域内！");
		}
	}
	while (true)
	{
		msg2 = getmouse();
		if (msg2.is_left() && msg2.is_down())
		{
			shape.setPt2(msg2.x - 500, msg2.y - 20); //坐标换算
			if (shape.getPt2() > Point(0, 0))
				break;
			xyprintf(0, 510, "选点必须在可画区域内！");
		}
	}
	shape.drawShape();
	graphCount++;
}

//把tempfile文件中保存的数据画在画板上,用于撤销和复原
void PaintBoard::paintData(size_t graphCount)
{
	std::ifstream ifs(tempFilePath);
	int shapeType = 0;
	Line line;
	Circle circle;
	Rectangle_ rectangle;

	for (int i = 0; i < graphCount; i++)
	{
		ifs >> shapeType;
		switch (shapeType)
		{
		case typeLine:
			ifs >> line;
			line.drawShape();
			break;
		case typeCircle:
			ifs >> circle;
			circle.drawShape();
			break;
		case typeRectangle:
			ifs >> rectangle;
			rectangle.drawShape();
			break;
		}
	}
	ifs.close();
}

//撤销，成功返回1，失败返回0
int PaintBoard::cancel()
{
	if (graphCount == 0 || graphCount == cancelCount)
		return 0;
	clearPaint();
	cancelCount++;
	paintData(graphCount-cancelCount);
	return 1;
}

//复原，成功返回1，失败返回0
int PaintBoard::restore()
{
	if (cancelCount == 0)
		return 0;
	clearPaint();
	cancelCount--;
	paintData(graphCount-cancelCount);
	return 1;
}

//把tempfile.txt中所有数据写入file.txt
void PaintBoard::writeToFile()
{
	std::ifstream ifs(tempFilePath);
	int shapeType = 0;
	Line line;
	Circle circle;
	Rectangle_ rectangle;

	for (int i = 0; i < graphCount - cancelCount; i++)
	{
		ifs >> shapeType;
		switch (shapeType)
		{
		case typeLine:
			ifs >> line;
			writeToFile(line, filePath);
			break;
		case typeCircle:
			ifs >> circle;
			writeToFile(circle, filePath);
			break;
		case typeRectangle:
			ifs >> rectangle;
			writeToFile(rectangle, filePath);
			break;
		}
	}
	ifs.close();
}

//把一个图形的数据写入filename文件中,以追加的方式
void PaintBoard::writeToFile(Shape& shape, const std::filesystem::path& path)
{
	std::ofstream ofs(path, std::ios::app);
	ofs << shape.getType() << endl 
		<< shape << endl;
	ofs.close();
}

//从file.txt中读取数据并写入tempfile.txt
void PaintBoard::readFromFile()
{
	std::ifstream ifs(filePath);
	int shapeType = 0;
	Line line;
	Circle circle;
	Rectangle_ rectangle;
	
	while (ifs >> shapeType)
	{
		switch (shapeType)
		{
		case typeLine:
			ifs >> line;
			writeToFile(line, tempFilePath);
			break;
		case typeCircle:
			ifs >> circle;
			writeToFile(circle, tempFilePath);
			break;
		case typeRectangle:
			ifs >> rectangle;
			writeToFile(rectangle, tempFilePath);
			break;
		}
	}
	ifs.close();
}

//设置图画的颜色
void PaintBoard::setGraphColor(const Color& color)
{
	setcolor(EGERGB(color.red, color.green, color.blue));
	setfillcolor(EGERGB(color.red, color.green, color.blue));
}

//删除被撤销掉的图形的数据
void PaintBoard::deleteCancelGraph()
{
	if (cancelCount == 0)
		return;
	writeToFile();
	graphCount -= cancelCount;
	cancelCount = 0;
	clearFile(tempFilePath);
	readFromFile();
	clearFile(filePath);
}

//清空path文件中的数据
void PaintBoard::clearFile(const std::filesystem::path& path)
{
	std::ofstream ofs(path);
	ofs.close();
}