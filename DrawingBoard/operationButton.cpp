#include <graphics.h>
#include <vector>
#include <iterator>
#include <fstream>
#include <exception>
#include <string>
#include <stdexcept>
#include "operationButton.h"

//extern bool isExit;
std::vector<Shape*> OperationButton::buffer;
const std::filesystem::path filePath("file.txt");
const std::regex typePattern("(\\d)");
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
	setfont(40, 0, "����");
	setcolor(BLACK);
	xyprintf(pt1.x, pt1.y, "����");
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void ClearButton::operation()
{
	clearPainting(); // ���ͼ������
	clearShapes();   // �����������
}

ExitButton::ExitButton(const Point& pt1_, const Point& pt2_) :
	OperationButton(pt1_, pt2_)
{}

void ExitButton::init()
{
	setfont(40, 0, "����");
	setcolor(BLACK);
	xyprintf(pt1.x, pt1.y, "�˳�");
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void ExitButton::operation()
{
	clearBuffer(); // ��ջ�����
	clearShapes(); // �����״
	closegraph();  // �˳�����
	exit(0);
}

CancelButton::CancelButton(const Point& pt1_, const Point& pt2_) :
	OperationButton(pt1_, pt2_)
{}

void CancelButton::init()
{
	setfont(40, 0, "����");
	setcolor(BLACK); 
	xyprintf(pt1.x, pt1.y, "<-");//������
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void CancelButton::operation()
{
	if (Shape::shapes.empty())
		return;
	OperationButton::buffer.push_back(Shape::shapes.back());
	Shape::shapes.pop_back();
	clearPainting();
	drawShapes();
}

RestoreButton::RestoreButton(const Point& pt1_, const Point& pt2_) :
	OperationButton(pt1_, pt2_)
{}

void RestoreButton::init()
{
	setfont(40, 0, "����");
	setcolor(BLACK);
	xyprintf(pt1.x, pt1.y, "->");//������
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void RestoreButton::operation()
{
	if (OperationButton::buffer.empty())
		return;
	Shape::shapes.push_back(buffer.back());
	OperationButton::buffer.pop_back();
	clearPainting();
	drawShapes();
}

WriteButton::WriteButton(const Point& pt1_, const Point& pt2_) :
	OperationButton(pt1_, pt2_)
{}

void WriteButton::init()
{
	setfont(40, 0, "����");
	setcolor(BLACK);
	xyprintf(pt1.x, pt1.y, "����");
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
	setfont(40, 0, "����");
	setcolor(BLACK);
	xyprintf(pt1.x, pt1.y, "��ȡ");
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void ReadButton::operation()
{
	std::ifstream ifs(filePath);
	int type;
	std::string str;
	std::smatch s;
	Line* aLine;
	Circle* aCircle;
	Rectangle_* aRectangle;
	clearPainting(); // ���ͼ������
	clearShapes();   // �����������
	while (!ifs.eof())
	{
		try
		{
			std::getline(ifs, str); // type
			if (std::regex_match(str, s, typePattern))
				type = std::stoi(s[0]);
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

void ReadButton::readShape(std::ifstream& ifs, Shape& shape, std::smatch& s, std::string& str)
{
	std::getline(ifs, str); // type
	if (str.empty())
		return;
	if (std::regex_match(str, s, typePattern))
		shape.setType(std::stoi(s[0]));
	else
		throw std::runtime_error("Error type!");
	std::getline(ifs, str); // isFill
	if (std::regex_match(str, s, isFillPattern))
		shape.setIsFill(std::stoi(s[0]));
	else
		throw std::runtime_error("Error isFill!");
	std::getline(ifs, str); // color
	if (std::regex_match(str, s, colorPattern))
		shape.setColor(
			Color(
				std::stoi(s[1]),
				std::stoi(s[2]),
				std::stoi(s[3])));
	else
		throw std::runtime_error("Error color!");
	std::getline(ifs, str);
	if (std::regex_match(str, s, pointPattern))
	{
		shape.setPt1(std::stoi(s[1]), std::stoi(s[2]));
	}
	else
		throw std::runtime_error("Error point!");
	std::getline(ifs, str);
	if (std::regex_match(str, s, pointPattern))
		shape.setPt2(std::stoi(s[1]), std::stoi(s[2]));
	else
		throw std::runtime_error("Error point!");
}


void clearPainting()
{
	//���ͼ������
	color_t fillcolor = getfillcolor();
	setviewport(500, 20, 1440, 720);        //����ͼ���������ڻ�ͼ����
	clearviewport();                        //�����ͼ����
	setfillcolor(WHITE);                    //�������ɫΪ��ɫ
	bar(0, 0, 1440, 720);                   //����ͼ����һ����ɫ������ʹ�������ְ�ɫ
	setviewport(0, 0, 1440, 720);           //����ͼ��������Ϊ��������
	setfillcolor(fillcolor);
}

void clearBuffer()
{
	//��ջ�����
	if (!OperationButton::buffer.empty())
	{
		for (auto it = OperationButton::buffer.begin(); it != OperationButton::buffer.end(); it++)
			delete* it;
		OperationButton::buffer.clear();
	}
}
