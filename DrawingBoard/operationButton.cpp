/****************************************************************
*																*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4															*
*                                                               *
*****************************************************************/

#include "operationButton.h"
#include <graphics.h>
#include <vector>
#include <iterator>
#include <fstream>
#include <exception>
#include <string>
#include <stdexcept>
#include <cassert>

//extern bool isExit;
std::vector<Shape*> OperationButton::buffer;
const std::filesystem::path filePath("file.txt");
// getline函数读取后利用正则表达式判断读取格式是否正确
const std::regex typePattern("(1|2|3)");
const std::regex isFillPattern("(0|1)");
const std::regex colorPattern("(\\d{0,3}) (\\d{0,3}) (\\d{0,3})");
const std::regex pointPattern("(\\d{0,3}) (\\d{0,3})");

OperationButton::OperationButton(const Point& pt1_, const Point& pt2_) :
	ButtonBase(pt1_, pt2_)
{}

ClearButton::ClearButton(const Point& pt1_, const Point& pt2_) :
	OperationButton(pt1_, pt2_)
{}

void ClearButton::init()
{
	setfont(40, 0, "楷体");
	setcolor(BLACK);
	xyprintf(pt1.x, pt1.y, "清屏");
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void ClearButton::operation()
{
	// 清除图画内容
	clearPainting();
	// 清除保存数据
	clearShapes();   
}

ExitButton::ExitButton(const Point& pt1_, const Point& pt2_) :
	OperationButton(pt1_, pt2_)
{}

void ExitButton::init()
{
	setfont(40, 0, "楷体");
	setcolor(BLACK);
	xyprintf(pt1.x, pt1.y, "退出");
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void ExitButton::operation()
{
	// 清空缓冲区
	clearBuffer();
	// 清空形状
	clearShapes(); 
	// 退出画板
	closegraph(); 
	// 退出程序
	exit(0);
}

CancelButton::CancelButton(const Point& pt1_, const Point& pt2_) :
	OperationButton(pt1_, pt2_)
{}

void CancelButton::init()
{
	setfont(40, 0, "楷体");
	setcolor(BLACK); 
	xyprintf(pt1.x, pt1.y, "<-");//撤销键
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void CancelButton::operation()
{
	if (Shape::shapes.empty())
		return;
	// 先将shapes尾部元素压入buffer
	// 再把shapes尾部元素弹出，也可以用个stack啥的，不一定vector
	OperationButton::buffer.push_back(Shape::shapes.back()); 
	Shape::shapes.pop_back(); 
	// 清屏后将shapes中剩余的图形重新画出
	clearPainting();
	drawShapes();
}

RestoreButton::RestoreButton(const Point& pt1_, const Point& pt2_) :
	OperationButton(pt1_, pt2_)
{}

void RestoreButton::init()
{
	setfont(40, 0, "楷体");
	setcolor(BLACK);
	xyprintf(pt1.x, pt1.y, "->"); // 撤销键
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void RestoreButton::operation()
{
	if (OperationButton::buffer.empty())
		return;
	// buffer尾部元素压入shapes
	// buffer尾部元素弹出，也可以用个stack啥的，不一定vector
	Shape::shapes.push_back(buffer.back());
	OperationButton::buffer.pop_back();
	// 清屏后将shapes中剩余的图形重新画出
	clearPainting();
	drawShapes();
}

WriteButton::WriteButton(const Point& pt1_, const Point& pt2_) :
	OperationButton(pt1_, pt2_)
{}

void WriteButton::init()
{
	setfont(40, 0, "楷体");
	setcolor(BLACK);
	xyprintf(pt1.x, pt1.y, "保存");
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void WriteButton::operation()
{
	std::ofstream ofs(filePath);
	for (auto it = Shape::shapes.begin(); it != Shape::shapes.end(); it++)
	{
		ofs << (*it)->getType() << std::endl
			<< **it;
	}
}

ReadButton::ReadButton(const Point& pt1_, const Point& pt2_) :
	OperationButton(pt1_, pt2_)
{}

void ReadButton::init()
{
	setfont(40, 0, "楷体");
	setcolor(BLACK);
	xyprintf(pt1.x, pt1.y, "读取");
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

// 
// 读取流程：
// 调用readShape函数来读取数据
// 首先使用getline函数获取一行数据
// 再使用正则表达式判断数据格式是否正确
//	 若正确则再判断数据的范围是否正确
//	   正确则将图形压入存储图形的数组shapes中
//     不正确则throw跳过该图形并进行下一个图形的读取
//   不正确则throw跳过该图形并进行下一个图形的读取
void ReadButton::operation()
{
	std::ifstream ifs(filePath);
	int type;
	std::string str;
	std::smatch s;
	Line* aLine;
	Circle* aCircle;
	Rectangle_* aRectangle;

	// 由于要从文件中读取数据并画出，
	// 故需要清除图画内容并清除保存数据
	// 不这么做也会崩掉
	clearPainting(); 
	clearShapes();   
	while (!ifs.eof())
	{
		try
		{
			std::getline(ifs, str); // type
			if (std::regex_match(str, s, typePattern))
				type = std::stoi(s[0]);
			// 由于在最后一个图形输出到文本之后还会换行，
			// 所以最后一个读入的str为空才会到达eof，
			// 不进行判断则会继续往下读取
			// 但此时文件已读取完毕，所以读取的全为空
			// 故加上这个判空，以便在读到最后一行空行时停止读取
			else if (str.empty())
				break;
			else
				throw std::runtime_error("Error type!");
			switch (type)
			{
			case typeLine:
				aLine = new Line;
				readShape(ifs, *aLine, s, str);
				//checkInputShape(*aLine);
				Shape::shapes.push_back(aLine);
				break;
			case typeCircle:
				aCircle = new Circle;
				readShape(ifs, *aCircle, s, str);
				//checkInputShape(*aCircle);
				Shape::shapes.push_back(aCircle);
				break;
			case typeRectangle:
				aRectangle = new Rectangle_;
				readShape(ifs, *aRectangle, s, str);
				//checkInputShape(*aRectangle);
				Shape::shapes.push_back(aRectangle);
				break;
			default:
				// 程序运行正常时不应该进入default，防bug
				assert(false);
			}
		}
		catch (std::runtime_error& error)
		{
			xyprintf(0, 510, "          ");
			xyprintf(0, 510, error.what());
		}
	}
	drawShapes();
}

// 本函数用于按行读取数据，
// 并且对数据的正确性进行检查，
// str用于保存按行读取的字符串
// s用于保存按照正则表达式匹配后提取出的数据
void ReadButton::readShape(std::ifstream& ifs, Shape& shape, std::smatch& s, std::string& str)
{
	// type
	std::getline(ifs, str); 
	// str为空说明读到了eof
	if (str.empty())
		return;

	if (std::regex_match(str, s, typePattern))
		shape.setType(std::stoi(s[0]));
	else
		throw std::runtime_error("Error type!");

	// isFill
	std::getline(ifs, str); 
	if (std::regex_match(str, s, isFillPattern))
		shape.setIsFill(std::stoi(s[0]));
	else
		throw std::runtime_error("Error isFill!");

	// color
	std::getline(ifs, str); 
	if (std::regex_match(str, s, colorPattern))
		shape.setColor(
			Color(
				std::stoi(s[1]),
				std::stoi(s[2]),
				std::stoi(s[3])));
	/*
	* 此处应该有读取进来的颜色的范围检查（0~255）
	*/
	else
		throw std::runtime_error("Error color!");

	// point1
	std::getline(ifs, str);
	if (std::regex_match(str, s, pointPattern))
		shape.setPt1(std::stoi(s[1]), std::stoi(s[2]));
	/*
	* 此处应该有读取进来的点的范围检查x(0~940), y(0~700)
	*/
	else
		throw std::runtime_error("Error point!");

	// point2
	std::getline(ifs, str);
	if (std::regex_match(str, s, pointPattern))
		shape.setPt2(std::stoi(s[1]), std::stoi(s[2]));
	/*
	* 此处应该有读取进来的点的范围检查x(0~940), y(0~700)
	*/
	else
		throw std::runtime_error("Error point!");
}


void clearPainting()
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

// 清空缓冲区
void clearBuffer()
{
	// 若为空则直接跳过
	if (!OperationButton::buffer.empty())
	{
		for (auto it = OperationButton::buffer.begin(); it != OperationButton::buffer.end(); ++it)
			delete* it;
		OperationButton::buffer.clear();
	}
}
