#include <graphics.h>
#include <vector>
#include <iterator>
#include <fstream>
#include "operationButton.h"

extern bool isExit;
std::vector<Shape*> OperationButton::buffer;
std::filesystem::path filePath("file.txt");

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
	Shape::shapes.clear(); // �����������
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
	isExit = true;
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
	OperationButton::buffer.push_back(*(Shape::shapes.end() - 1));
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
	Shape::shapes.push_back(*(buffer.end() - 1));
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
	xyprintf(pt1.x, pt1.y, "��ȡ");
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void WriteButton::operation()
{
	std::ifstream ifs(filePath);
	int type;
	Line* aLine;
	Circle* aCircle;
	Rectangle_* aRectangle;
	while (!ifs.eof())
	{
		ifs >> type;
		switch (type)
		{
		case typeLine:
			aLine = new Line;
			ifs >> *aLine;
			Shape::shapes.push_back(aLine);
			break;
		case typeCircle:
			aCircle = new Circle;
			ifs >> *aCircle;
			Shape::shapes.push_back(aCircle);
			break;
		case typeRectangle:
			aRectangle = new Rectangle_;
			ifs >> *aRectangle;
			Shape::shapes.push_back(aRectangle);
			break;
		}
	}
	drawShapes();
}

ReadButton::ReadButton(const Point& pt1_, const Point& pt2_) :
	OperationButton(pt1_, pt2_)
{}

void ReadButton::init()
{
	setfont(40, 0, "����");
	setcolor(BLACK);
	xyprintf(pt1.x, pt1.y, "����");
	rectangle(pt1.x, pt1.y, pt2.x, pt2.y);
}

void ReadButton::operation()
{
	std::ofstream ofs(filePath);
	for (auto it = Shape::shapes.begin(); it != Shape::shapes.end(); it++)
	{
		ofs << (*it)->getType() << std::endl
			<< **it << std::endl;
	}
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
