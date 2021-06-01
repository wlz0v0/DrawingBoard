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
// getline������ȡ������������ʽ�ж϶�ȡ��ʽ�Ƿ���ȷ
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
	setfont(40, 0, "����");
	setcolor(BLACK);
	xyprintf(pt1.x, pt1.y, "����");
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void ClearButton::operation()
{
	// ���ͼ������
	clearPainting();
	// �����������
	clearShapes();   
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
	// ��ջ�����
	clearBuffer();
	// �����״
	clearShapes(); 
	// �˳�����
	closegraph(); 
	// �˳�����
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
	// �Ƚ�shapesβ��Ԫ��ѹ��buffer
	// �ٰ�shapesβ��Ԫ�ص�����Ҳ�����ø�stackɶ�ģ���һ��vector
	OperationButton::buffer.push_back(Shape::shapes.back()); 
	Shape::shapes.pop_back(); 
	// ������shapes��ʣ���ͼ�����»���
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
	xyprintf(pt1.x, pt1.y, "->"); // ������
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void RestoreButton::operation()
{
	if (OperationButton::buffer.empty())
		return;
	// bufferβ��Ԫ��ѹ��shapes
	// bufferβ��Ԫ�ص�����Ҳ�����ø�stackɶ�ģ���һ��vector
	Shape::shapes.push_back(buffer.back());
	OperationButton::buffer.pop_back();
	// ������shapes��ʣ���ͼ�����»���
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

// 
// ��ȡ���̣�
// ����readShape��������ȡ����
// ����ʹ��getline������ȡһ������
// ��ʹ��������ʽ�ж����ݸ�ʽ�Ƿ���ȷ
//	 ����ȷ�����ж����ݵķ�Χ�Ƿ���ȷ
//	   ��ȷ��ͼ��ѹ��洢ͼ�ε�����shapes��
//     ����ȷ��throw������ͼ�β�������һ��ͼ�εĶ�ȡ
//   ����ȷ��throw������ͼ�β�������һ��ͼ�εĶ�ȡ
void ReadButton::operation()
{
	std::ifstream ifs(filePath);
	int type;
	std::string str;
	std::smatch s;
	Line* aLine;
	Circle* aCircle;
	Rectangle_* aRectangle;

	// ����Ҫ���ļ��ж�ȡ���ݲ�������
	// ����Ҫ���ͼ�����ݲ������������
	// ����ô��Ҳ�����
	clearPainting(); 
	clearShapes();   
	while (!ifs.eof())
	{
		try
		{
			std::getline(ifs, str); // type
			if (std::regex_match(str, s, typePattern))
				type = std::stoi(s[0]);
			// ���������һ��ͼ��������ı�֮�󻹻ỻ�У�
			// �������һ�������strΪ�ղŻᵽ��eof��
			// �������ж����������¶�ȡ
			// ����ʱ�ļ��Ѷ�ȡ��ϣ����Զ�ȡ��ȫΪ��
			// �ʼ�������пգ��Ա��ڶ������һ�п���ʱֹͣ��ȡ
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
				// ������������ʱ��Ӧ�ý���default����bug
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

// ���������ڰ��ж�ȡ���ݣ�
// ���Ҷ����ݵ���ȷ�Խ��м�飬
// str���ڱ��水�ж�ȡ���ַ���
// s���ڱ��水��������ʽƥ�����ȡ��������
void ReadButton::readShape(std::ifstream& ifs, Shape& shape, std::smatch& s, std::string& str)
{
	// type
	std::getline(ifs, str); 
	// strΪ��˵��������eof
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
	* �˴�Ӧ���ж�ȡ��������ɫ�ķ�Χ��飨0~255��
	*/
	else
		throw std::runtime_error("Error color!");

	// point1
	std::getline(ifs, str);
	if (std::regex_match(str, s, pointPattern))
		shape.setPt1(std::stoi(s[1]), std::stoi(s[2]));
	/*
	* �˴�Ӧ���ж�ȡ�����ĵ�ķ�Χ���x(0~940), y(0~700)
	*/
	else
		throw std::runtime_error("Error point!");

	// point2
	std::getline(ifs, str);
	if (std::regex_match(str, s, pointPattern))
		shape.setPt2(std::stoi(s[1]), std::stoi(s[2]));
	/*
	* �˴�Ӧ���ж�ȡ�����ĵ�ķ�Χ���x(0~940), y(0~700)
	*/
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

// ��ջ�����
void clearBuffer()
{
	// ��Ϊ����ֱ������
	if (!OperationButton::buffer.empty())
	{
		for (auto it = OperationButton::buffer.begin(); it != OperationButton::buffer.end(); ++it)
			delete* it;
		OperationButton::buffer.clear();
	}
}
