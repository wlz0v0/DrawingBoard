/*���ļ��д洢��ʼ����������ȡ�ļ����������ݶ�ȡ�ļ��Ľ����ʾ���̲˵�
*������ͼ��������������ʼ��ͼƬ���ֺ�������������ʼ���ı����ֺ���
*���ݶ�ȡ�ļ��Ľ����ʾ���̲˵���������ͼ������
*/

#include <graphics.h>
#include "interaction.h"
#include "kbpaint_support.h"
#include "mousepaint_support.h"
#include "allpaint_support.h"
#include "datasave.h"

extern unsigned int cancelcount;               //���㳷�������ı�������datasave.cpp�д洢
extern DATA data[20];                          //�ṹ�����飬���ڴ洢����ͼ�ε����ݣ���datasave.cpp�д洢

//������Ϊ��ʼ������
void initialize()
{
	//��ʼ�����������
	initgraph(1440, 720);                                          //���û����С
	setcaption("����˹С�𳵻��壨1440*720����Ч��СΪ920*680)");     //���û�������
	setbkcolor(WHITE);                                             //���ñ�����ɫ
	setcolor(BLACK);                                               //����������ɫ
	setfont(60, 0, "����");                                        //����������ʽ
	xyprintf(350, 200, "������ʹ����껹�Ǽ��̣�");
	xyprintf(350, 270, "1.���");
	xyprintf(350, 340, "2.����");
	setfont(16, 0, "����");                                        //����������ʽ
	int mouseflag = getch();                                       //��ȡ�û���ѡ��
	cleardevice();

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

	if (mouseflag == '1')
	{
		mousemenu();       //��ʾ�������˵�
	}
	else if (mouseflag == '2')
	{
		kbmenu();          //��ʾ���̲����˵�
	}
	else                   //�����󲢴���
	{
		cleardevice();     //�������ӡ�����������������
		setfont(60, 0, "����");
		xyprintf(400, 200, "Error!!!!!!!!!");
		xyprintf(400, 350, "��������˳����塣");//�򵥴ֱ��Ľ����ʽXD
		getch();
	}
}

//���������ڶ�ȡ�ļ����ɹ�����1�����򷵻�0
int readFile(void)
{
	xyprintf(0, 10, "��ӭ����������˹С�𳵻��壬����ݲ˵�ѡ��������еĲ�����");
	xyprintf(0, 30, "1.��ȡ�ļ�");
	xyprintf(0, 50, "2.����ȡ�ļ�");
	xyprintf(0, 70, "����������ѡ��");
	//ѯ���û��Ƿ��ȡ֮ǰ����Ϣ�����ļ�

	int keyboardmsg = getch();
	if (keyboardmsg == '1')
	{
		return 1;
	}
	else return 0;
}

//������Ϊ��ͼ����
void kbpainting()
{
	cancelcount = 0;                           //��ʼ��ͼʱ��������Ϊ0
	int keyboardmsg1, keyboardmsg2, fillflag;  //fillflagΪ�ж��Ƿ����ı���������0Ϊ����䣬����1Ϊ���
	//ѡ����ɫ
	xyprintf(0, 280, "��ѡ������Ҫ����ɫ��");
	xyprintf(0, 300, "1.��ɫ");
	xyprintf(0, 320, "2.��ɫ");
	xyprintf(0, 340, "3.��ɫ");
	xyprintf(0, 360, "4.��ɫ");
	xyprintf(0, 380, "5.�Զ���");

	//������ɫ
	keyboardmsg1 = getch();
	switch (keyboardmsg1)
	{
	case '1':
		setcolor(EGERGB(255, 0, 0));       //��ɫ����Ϊ��ɫ
		setfillcolor(EGERGB(255, 0, 0));   //���ɫ����Ϊ��ɫ
		clearword();                       //�������������ʾ
		break;
	case '2':
		setcolor(EGERGB(0, 0, 255));       //��ɫ����Ϊ��ɫ
		setfillcolor(EGERGB(0, 0, 255));   //���ɫ����Ϊ��ɫ
		clearword();                       //�������������ʾ
		break;
	case '3':
		setcolor(EGERGB(0, 0, 0));         //��ɫ����Ϊ��ɫ   
		setfillcolor(EGERGB(0, 0, 0));     //���ɫ����Ϊ��ɫ
		clearword();                       //�������������ʾ
		break;
	case '4':
		setcolor(EGERGB(0, 255, 0));       //��ɫ����Ϊ��ɫ
		setfillcolor(EGERGB(0, 255, 0));   //���ɫ����Ϊ��ɫ
		clearword();                       //�������������ʾ
		break;
	case '5':
		rgbcolor();                        //�����û������Զ�����ɫ����
		clearword();                       //�������������ʾ
		break;
	}

	//ѯ���Ƿ����ͼ��
	xyprintf(0, 280, "�Ƿ���䣿��ֱ�߲�����䣩");
	xyprintf(0, 300, "1.��");
	xyprintf(0, 320, "2.��");
	fillflag = getch();                     //��ȡ�Ƿ����Ľ��
	clearword();

	//ѡ������Ҫ��ͼ��
	xyprintf(0, 280, "��ѡ������Ҫ��ͼ�Σ�");
	xyprintf(0, 300, "1.ֱ��");
	xyprintf(0, 320, "2.Բ��");
	xyprintf(0, 340, "3.����");
	xyprintf(0, 360, "4.����");
	xyprintf(0, 380, "5.�����");

	//��������Ҫ��ͼ��
	keyboardmsg2 = getch();
	switch (keyboardmsg2)
	{
	case '1':
		paintline();      //�����û������Զ���ֱ��
		clearword();      //�������������ʾ
		break;
	case '2':
		if (fillflag == '1')
		{
			paintfillcircle();     //�����û������Զ������Բ
		}
		else { paintcircle(); }    //�����û������Զ������Բ
		clearword();               //�������������ʾ
		break;
	case '3':
		if (fillflag == '1')
		{
			paintbar();            //�����û������Զ���������
		}
		else { paintrectangle(); } //�����û������Զ�����ľ���
		clearword();               //�������������ʾ
		break;
	case '4':
		if (fillflag == '1')
		{
			paintpieslice();       //�����û������Զ����������
		}
		else { paintarc(); }       //�����û������Զ��廡��
		clearword();               //�������������ʾ
		break;
	case '5':
		if (fillflag == '1')
		{
			paintfillpoly();       //�����û������Զ����������
		}
		else { paintdrawpoly(); }  //�����û������Զ�����Ķ����
		clearword();               //�������������ʾ
		break;
	}
}

//���ݶ�ȡ�ļ��Ľ����ʾ���̲����˵�
void kbmenu()
{
	//���´�ӡ�����û�ʹ��Ӣ�����뷨
	setcolor(RED);
	xyprintf(200, 30, "WARNING!");
	xyprintf(150, 50, "���������ʹ��Ӣ�����뷨��");
	xyprintf(150, 70, "����������쳣��");
	setcolor(BLACK);

	int readflag = readFile();
	if (readflag == 1)
	{
		xyprintf(0, 90, "��ȡ�ɹ���");
		readFromFile();
		restore();
	}
	else
	{
		xyprintf(0, 90, "�ļ�δ����ȡ");
	}

	//�û����ݲ˵���ʾ���в���
	xyprintf(0, 130, "��ӭ����������˹С�𳵻��壬����ݲ˵�ѡ��������еĲ�����");
	xyprintf(0, 150, "1.�����Ļ");
	xyprintf(0, 170, "2.����");
	xyprintf(0, 190, "3.�˳�");
	xyprintf(0, 210, "4.���� 5.�ָ�");
	xyprintf(0, 230, "6.����ͼ�����ļ� 7.�ػ�");
	xyprintf(0, 250, "����������ѡ��");

	while (true)
	{
		bool flag = false;      //�����˳�����
		int keyboardmsg = getch();

		switch (keyboardmsg)
		{
		case '1':
			clearpainting();    //ֻ���ͼ�����ݵĺ���
			break;
		case '2':
			kbpainting();        //���̻�ͼ����
			break;
		case '3':
			flag = true;        //�˳�����
			break;
		case '4':
			cancel();           //��������
			break;
		case '5':
			restore();          //��ԭ�������볷���������Ӧ��
			break;
		case '6':
			writeToFile(data);  //�����ݱ��浽�ļ��еĺ���
			break;
		case '7':
			repaint();          //�ػ�����
			break;
		}

		if (flag)	break;      //case 3��flagΪtrue������ѭ���˳�����
	}
}

//������Ϊ�����������ʼ����������Ҫ��ӡͼ��
void mousepaintinit_graph()
{
	int i;
	constexpr int colorset[17][3] = { //�����ά�����ŵ��Ǹ�����ɫ��RGBֵ�����ں����ӡ
		{255, 0, 0},      //��ɫ
		{255, 97, 0},     //��ɫ
		{255, 255, 0},    //��ɫ
		{0, 255, 0},      //��ɫ
		{0, 255, 255},    //��ɫ
		{135, 206, 235},  //����ɫ
		{0, 0, 255},      //��ɫ
		{128, 0, 255},    //��ɫ
		{0, 0, 0},        //��ɫ
		{242, 156, 177},  //��ɫ
		{255, 201, 14},   //��ɫ
		{239, 228, 176},  //ǳ��ɫ
		{181, 230, 29},   //���ɫ
		{153, 217, 234},  //������ɫ
		{112, 146, 190},  //����ɫ
		{200, 191, 231},  //ǳ��ɫ
		{185, 122, 87},   //��ɫ
	};

	//���´�ӡɫ��
	for (i = 0; i < 17; i++)
	{
		setfillcolor(EGERGB(colorset[i][0], colorset[i][1], colorset[i][2]));
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

//������Ϊ�����������ʼ����������Ҫ��ӡ�ı�
void mousepaintinit_text()
{
	//���´�ӡ���ֲ�����ѡ���
	xyprintf(10, 160, "��ȡ");
	rectangle(10, 160, 90, 200);
	xyprintf(100, 160, "�ػ�");
	rectangle(100, 160, 180, 200);
	xyprintf(190, 160, "����");
	rectangle(190, 160, 270, 200);
	xyprintf(280, 160, "����");
	rectangle(280, 160, 360, 200);
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

//��ʾ�������˵�
void mousemenu()
{
	mousepaintinit_graph();
	mousepaintinit_text();
	mousepainting();
}

/*�����ͼ����
*����֧�е�࣬���Լ������뿴��T_T��û��switch�Ǿ�������Ҳ����ô�࣬û��ൽ��ȥXD��
* ��200���еĺ���Ҳ��û˭��:( , ��Ҳ��֪����ô��)
* �������ˣ�
*/
void mousepainting()
{
	while (true)
	{
		bool flag = false;
		mouse_msg msg1 = getmouse();
		if (msg1.is_left() && msg1.is_down())//�ж��������Ƿ���
		{
			int x_flag = msg1.x;
			int y_flag = msg1.y;
			if ((x_flag <= 90 && x_flag >= 10) && (y_flag <= 200 && y_flag >= 160))      //��ȡģ��
			{
				readFromFile();
				restore();
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "��ȡ�ɹ���");
			}
			else if ((x_flag <= 180 && x_flag >= 100) && (y_flag <= 200 && y_flag >= 160))//�ػ�ģ��
			{
				setviewport(0, 230, 1440, 720);//������ͼ������Ϊ����repaint���������ӡ�������ܴ�ӡ��ָ����λ����
				repaint();                     //������������һЩ��������
				setcolor(RED);
				setviewport(0, 0, 1440, 720);
				xyprintf(0, 300, "������ʹ����껭ͼʱ��Ĭ����ɫ�����ɫ��Ϊ��ɫ��");//��ӡ��������ԭ����repaint���������������ݣ������ˣ��������repaint�������ٴ�ӡһ��
				xyprintf(0, 330, "��������߿��ڿ��Խ��в���������ɫ��ͼ�Σ���");
				xyprintf(0, 360, "���Ͻ�������ͷ������ǳ����ұ��Ǹ�ԭ��");
				xyprintf(0, 390, "��ͼʱ�������������Σ�");
				xyprintf(0, 420, "1.��ֱ��ʱ��ѡȡ���㣬������֮�仭ֱ�ߣ�");
				xyprintf(0, 450, "2.��Բʱ����һ��ѡȡԲ�ģ��ڶ������һ��֮��ľ���Ϊ�뾶��");
				xyprintf(0, 480, "3.������ʱ��ѡȡ���㣬����������ֱ�Ϊ���εĶԽ��ߵĵ㡣");
				setcolor(BLACK);
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "�ػ��ɹ���");
			}
			else if ((x_flag <= 270 && x_flag >= 190) && (y_flag <= 200 && y_flag >= 160))//����ģ��
			{
				writeToFile(data);
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "����ɹ���");
			}
			else if ((x_flag <= 360 && x_flag >= 280) && (y_flag <= 200 && y_flag >= 160))//����ģ��
			{
				clearpainting();
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "����ɹ���");
			}
			else if ((x_flag <= 450 && x_flag >= 370) && (y_flag <= 200 && y_flag >= 160))//�˳�ģ��
			{
				flag = true;
			}
			else if ((x_flag <= 80 && x_flag >= 20) && (y_flag <= 140 && y_flag >= 80))   //��ֱ��ģ��
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "ѡ��ֱ�߳ɹ���");
				mousepaintline();
			}
			else if ((x_flag <= 150 && x_flag >= 90) && (y_flag <= 140 && y_flag >= 80))   //�����ľ���ģ��
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "ѡ����ľ��γɹ���");
				mousepaintrectangle();
			}
			else if ((x_flag <= 220 && x_flag >= 160) && (y_flag <= 140 && y_flag >= 80))   //��������ģ��
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "ѡ�������γɹ���");
				mousepaintbar();
			}
			else if ((x_flag <= 290 && x_flag >= 230) && (y_flag <= 140 && y_flag >= 80))   //������Բģ��
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "ѡ�����Բ�ɹ���");
				mousepaintcircle();
			}
			else if ((x_flag <= 360 && x_flag >= 300) && (y_flag <= 140 && y_flag >= 80))   //�����Բģ��
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				xyprintf(0, 510, "ѡ�����Բ�ɹ���");
				mousepaintfillcircle();
			}
			else if ((x_flag <= 40 && x_flag >= 20) && (y_flag <= 40 && y_flag >= 20))       //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(255, 0, 0);
				xyprintf(0, 510, "ѡ���ɫ�ɹ���");
			}
			else if ((x_flag <= 65 && x_flag >= 45) && (y_flag <= 40 && y_flag >= 20))       //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(255, 97, 0);
				xyprintf(0, 510, "ѡ���ɫ�ɹ���");
			}
			else if ((x_flag <= 90 && x_flag >= 70) && (y_flag <= 40 && y_flag >= 20))       //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(255, 255, 0);
				xyprintf(0, 510, "ѡ���ɫ�ɹ���");
			}
			else if ((x_flag <= 115 && x_flag >= 95) && (y_flag <= 40 && y_flag >= 20))      //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(0, 255, 0);
				xyprintf(0, 510, "ѡ����ɫ�ɹ���");
			}
			else if ((x_flag <= 140 && x_flag >= 120) && (y_flag <= 40 && y_flag >= 20))      //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(0, 255, 255);
				xyprintf(0, 510, "ѡ����ɫ�ɹ���");
			}
			else if ((x_flag <= 165 && x_flag >= 145) && (y_flag <= 40 && y_flag >= 20))      //����ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(135, 206, 235);
				xyprintf(0, 510, "ѡ������ɫ�ɹ���");
			}
			else if ((x_flag <= 190 && x_flag >= 170) && (y_flag <= 40 && y_flag >= 20))      //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(0, 0, 255);
				xyprintf(0, 510, "ѡ����ɫ�ɹ���");
			}
			else if ((x_flag <= 215 && x_flag >= 195) && (y_flag <= 40 && y_flag >= 20))      //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(128, 0, 255);
				xyprintf(0, 510, "ѡ����ɫ�ɹ���");
			}
			else if ((x_flag <= 240 && x_flag >= 220) && (y_flag <= 40 && y_flag >= 20))      //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(0, 0, 0);
				xyprintf(0, 510, "ѡ���ɫ�ɹ���");
			}
			else if ((x_flag <= 40 && x_flag >= 20) && (y_flag <= 65 && y_flag >= 45))        //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(242, 156, 177);
				xyprintf(0, 510, "ѡ���ɫ�ɹ���");
			}
			else if ((x_flag <= 65 && x_flag >= 45) && (y_flag <= 65 && y_flag >= 45))        //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(255, 201, 14);
				xyprintf(0, 510, "ѡ���ɫ�ɹ���");
			}
			else if ((x_flag <= 90 && x_flag >= 70) && (y_flag <= 65 && y_flag >= 45))        //ǳ��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(239, 228, 176);
				xyprintf(0, 510, "ѡ��ǳ��ɫ�ɹ���");
			}
			else if ((x_flag <= 115 && x_flag >= 95) && (y_flag <= 65 && y_flag >= 45))       //���ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(181, 230, 29);
				xyprintf(0, 510, "ѡ�����ɫ�ɹ���");
			}
			else if ((x_flag <= 140 && x_flag >= 120) && (y_flag <= 65 && y_flag >= 45))      //������ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(153, 217, 234);
				xyprintf(0, 510, "ѡ������ɫ�ɹ���");
			}
			else if ((x_flag <= 165 && x_flag >= 145) && (y_flag <= 65 && y_flag >= 45))      //����ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(112, 146, 190);
				xyprintf(0, 510, "ѡ������ɫ�ɹ���");
			}
			else if ((x_flag <= 190 && x_flag >= 170) && (y_flag <= 65 && y_flag >= 45))      //ǳ��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(200, 191, 231);
				xyprintf(0, 510, "ѡ��ǳ��ɫ�ɹ���");
			}
			else if ((x_flag <= 215 && x_flag >= 195) && (y_flag <= 65 && y_flag >= 45))       //��ɫ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				Setgraphcolor(185, 122, 87);
				xyprintf(0, 510, "ѡ����ɫ�ɹ���");
			}
			else if ((x_flag <= 340 && x_flag >= 300) && (y_flag <= 65 && y_flag >= 25))       //����
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				cancel();
				xyprintf(0, 510, "�����ɹ���");
			}
			else if ((x_flag <= 390 && x_flag >= 350) && (y_flag <= 65 && y_flag >= 25))       //��ԭ
			{
				xyprintf(0, 510, "                            ");//���ǰһ�δ�ӡ������
				restore();
				xyprintf(0, 510, "��ԭ�ɹ���");
			}
		}
		if (flag) break;  //�˳�����
	}
}