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
	//��ʼ�����������
	initgraph(1440, 720);                                          //���û����С
	setcaption("����˹С�𳵻��壨1440*720����Ч��СΪ920*680)");     //���û�������
	setbkcolor(WHITE);                                             //���ñ�����ɫ
	setcolor(BLACK);                                               //����������ɫ
	setfont(60, 0, "����");                                        //����������ʽ
	xyprintf(350, 200, "�Ƿ��ȡ�ļ���");
	xyprintf(350, 270, "1.��");
	xyprintf(350, 340, "2.��");
	int msg = getch();
	if (msg == '1')
		readFromFile();

	cleardevice();
	setfont(16, 0, "����");                                        //����������ʽ
	line(499, 20, 499, 720);                                       //��ӡһ�����߷ָ���ͼ����
	line(499, 19, 1440, 19);                                       //��ӡһ�����߷ָ���ͼ����
	//���´�ӡ���������                           
	int coordinate;
	for (coordinate = 0; coordinate <= 940; coordinate += 40)
	{
		setviewport(500, 0, 1440, 720);
		xyprintf(coordinate, 0, "%d", coordinate);              //��ӡ������
		setviewport(0, 20, 1440, 720);
		xyprintf(470, coordinate, "%d", coordinate);            //��ӡ������
	}
	setviewport(0, 0, 1440, 720);
}

void PaintBoard::initGraph()
{
	//���´�ӡɫ��
	for (int i = 0; i < 17; i++)
	{
		setGraphColor(colorset[i]);
		if (i < 9)//��һ��
		{
			bar(20 + 25 * i, 20, 40 + 25 * i, 40);            //��ӡ��������Ϊ��ѡȡ��ɫ��
		}
		else      //�ڶ���
		{
			bar(20 + 25 * (i - 9), 45, 40 + 25 * (i - 9), 65);//��ӡ��������Ϊ��ѡȡ��ɫ��
		}
	}
	setfillcolor(WHITE);//��ɫ
	setcolor(BLACK);
	rectangle(220, 45, 240, 65);//��ӡ����ɫ�߿���Ϊ��ɫ��ɫ�飬��ʵûɶ�ã�����Ҳû�ӿ�ѡȡ��ɫ�����˻��屳��Ҳ�ǰ׵ģ�ɶ��������
	setfont(40, 0, "����");
	setcolor(BLACK);
	xyprintf(300, 25, "<-");//������
	rectangle(300, 25, 340, 65);
	xyprintf(350, 25, "->");//�ָ���
	rectangle(350, 25, 390, 65);

	//���´�ӡ����ѡ��Ҫ����ͼ������
	rectangle(20, 80, 80, 140);
	setcolor(BLUE);
	line(25, 85, 75, 135);         //��ֱ��ѡ���
	rectangle(90, 80, 150, 140);   //������ѡ���
	setcolor(BLACK);
	setfillcolor(BLUE);
	bar(160, 80, 220, 140);        //��������ѡ���
	setcolor(BLACK);
	rectangle(230, 80, 290, 140);
	setcolor(BLUE);
	circle(260, 110, 25);          //��Բ��ѡ���
	setcolor(BLACK);
	rectangle(300, 80, 360, 140);
	setcolor(BLUE);
	setfillcolor(BLUE);
	pieslice(330, 110, 0, 360, 25);//�����Բ��ѡ���
	setcolor(BLACK);
	setfillcolor(WHITE);
}

void PaintBoard::initText()
{
	//���´�ӡ���ֲ�����ѡ���
	xyprintf(10, 160, "����");
	rectangle(10, 160, 90, 200);
	xyprintf(370, 160, "�˳�");
	rectangle(370, 160, 450, 200);

	//���´�ӡ��ʾ���
	setfont(16, 0, "����");
	setcolor(RED);
	xyprintf(0, 300, "������ʹ����껭ͼʱ��Ĭ����ɫ�����ɫ��Ϊ��ɫ��");
	xyprintf(0, 330, "��������߿��ڿ��Խ��в�����");
	xyprintf(0, 360, "���Ͻ�������ͷ������ǳ����ұ��Ǹ�ԭ��");
	xyprintf(0, 390, "��ͼʱ�������������Σ�");
	xyprintf(0, 420, "1.��ֱ��ʱ��ѡȡ���㣬������֮�仭ֱ�ߣ�");
	xyprintf(0, 450, "2.��Բʱ����һ��ѡȡԲ�ģ��ڶ������һ��֮��ľ���Ϊ�뾶��");
	xyprintf(0, 480, "3.������ʱ��ѡȡ���㣬����������ֱ�Ϊ���εĶԽ��ߵĵ㡣");
	setcolor(BLACK);
}

void PaintBoard::setGraphCount(size_t graphCount_)
{
	graphCount = graphCount_;
}

void PaintBoard::clearPaint()
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
			shape.setPt1(msg1.x - 500, msg1.y - 20); //���껻��
			if (shape.getPt1() > Point(0, 0))
				break;
			xyprintf(0, 510, "ѡ������ڿɻ������ڣ�");
		}
	}
	while (true)
	{
		msg2 = getmouse();
		if (msg2.is_left() && msg2.is_down())
		{
			shape.setPt2(msg2.x - 500, msg2.y - 20); //���껻��
			if (shape.getPt2() > Point(0, 0))
				break;
			xyprintf(0, 510, "ѡ������ڿɻ������ڣ�");
		}
	}
	shape.drawShape();
	graphCount++;
}

//��tempfile�ļ��б�������ݻ��ڻ�����,���ڳ����͸�ԭ
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

//�������ɹ�����1��ʧ�ܷ���0
int PaintBoard::cancel()
{
	if (graphCount == 0 || graphCount == cancelCount)
		return 0;
	clearPaint();
	cancelCount++;
	paintData(graphCount-cancelCount);
	return 1;
}

//��ԭ���ɹ�����1��ʧ�ܷ���0
int PaintBoard::restore()
{
	if (cancelCount == 0)
		return 0;
	clearPaint();
	cancelCount--;
	paintData(graphCount-cancelCount);
	return 1;
}

//��tempfile.txt����������д��file.txt
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

//��һ��ͼ�ε�����д��filename�ļ���,��׷�ӵķ�ʽ
void PaintBoard::writeToFile(Shape& shape, const std::filesystem::path& path)
{
	std::ofstream ofs(path, std::ios::app);
	ofs << shape.getType() << endl 
		<< shape << endl;
	ofs.close();
}

//��file.txt�ж�ȡ���ݲ�д��tempfile.txt
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

//����ͼ������ɫ
void PaintBoard::setGraphColor(const Color& color)
{
	setcolor(EGERGB(color.red, color.green, color.blue));
	setfillcolor(EGERGB(color.red, color.green, color.blue));
}

//ɾ������������ͼ�ε�����
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

//���path�ļ��е�����
void PaintBoard::clearFile(const std::filesystem::path& path)
{
	std::ofstream ofs(path);
	ofs.close();
}