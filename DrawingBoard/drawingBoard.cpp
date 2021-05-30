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
	//��ʼ�����������
	initgraph(1440, 720);                                          //���û����С
	setcaption("����˹С�𳵻��壨1440*720����Ч��СΪ920*680)");     //���û�������
	setbkcolor(WHITE);                                             //���ñ�����ɫ
	setcolor(BLACK);                                               //����������ɫ
	setfont(16, 0, "����");                                        //����������ʽ
	setfillcolor(WHITE);

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

	//��ʼ����ť
	for (auto it = buttons.begin(); it != buttons.end(); it++)
	{
		(*it)->init();
	}

	//��ӡ��ʾ���
	setfont(16, 0, "����");
	setcolor(RED);
	xyprintf(0, 270, "�˳�ʱ�벻Ҫ������Ͻǵġ������������ڲ����˳�����");
	xyprintf(0, 300, "������ʹ����껭ͼʱ��Ĭ����ɫ�����ɫ��Ϊ��ɫ��");
	xyprintf(0, 330, "��������߿��ڿ��Խ��в�����");
	xyprintf(0, 360, "���Ͻ�������ͷ������ǳ����ұ��Ǹ�ԭ��");
	xyprintf(0, 390, "��ͼʱ�������������Σ�");
	xyprintf(0, 420, "1.��ֱ��ʱ��ѡȡ���㣬������֮�仭ֱ�ߣ�");
	xyprintf(0, 450, "2.��Բʱ����һ��ѡȡԲ�ģ��ڶ������һ��֮��ľ���Ϊ�뾶��");
	xyprintf(0, 480, "3.������ʱ��ѡȡ���㣬����������ֱ�Ϊ���εĶԽ��ߵĵ㡣");
	setcolor(BLACK);
	xyprintf(380, 110, "ֱ��");
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
			// ����find_if������lambda���ʽ�жϰ�ť�Ƿ񱻵��
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
	//clearBuffer(); // ��ջ�����
	//clearShapes(); // �����״
	//closegraph();  // �˳�����
}
