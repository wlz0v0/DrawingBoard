/*���ļ��д洢�������껭ͼ������ͨ�õĺ���
* ��������������֡����ͼ�����֡��ػ������ú���
*/

#include <graphics.h>
#include "datasave.h"

extern unsigned int graphcount;

//����������Ϊ���һ��������
void clearword()
{
	int fillcolor;                          //fillcolor�������ڱ���֮ǰ���õ����ɫ
	setviewport(0, 280, 460, 720);          //����ͼ�����������°벿��������
	clearviewport();                        //�����ͼ����
	fillcolor = getfillcolor();             //����֮ǰ���õ����ɫ
	setfillcolor(WHITE);                    //�������ɫΪ��ɫ
	bar(0, 0, 460, 440);                    //����ͼ����һ����ɫ������ʹ�������ְ�ɫ
	setviewport(0, 0, 1440, 720);           //����ͼ��������Ϊ��������
	setfillcolor(fillcolor);                //�ָ����ɫΪ֮ǰ����ɫ
}

//�������������ͼ������
void clearpainting()
{
	setviewport(500, 20, 1440, 720);        //����ͼ���������ڻ�ͼ����
	clearviewport();                        //�����ͼ����
	setfillcolor(WHITE);                    //�������ɫΪ��ɫ
	bar(0, 0, 1440, 720);                   //����ͼ����һ����ɫ������ʹ�������ְ�ɫ
	setviewport(0, 0, 1440, 720);           //����ͼ��������Ϊ��������
}

//�ػ�����
void repaint()
{
	xyprintf(0, 280, "ȷ��Ҫ�ػ���֮ǰ�����ͼ��ȫ���ᱻ�����");
	xyprintf(0, 300, "1.ȷ��");
	xyprintf(0, 320, "2.�����루�������룩");
	int msg = getch();
	if (msg == '1')
	{
		clearpainting();    //�ػ�ʱ���ͼ������
		dataclear();        //�ػ�ʱ��������ͼ������
		clearword();        //�����ʾ����
	}
	if (msg == '2')
	{
		clearword();        //�����ʾ����
	}
}

/*�����������ڻ�ͼ�����û������ͼ������ɫ�����ɫ��˳���ͼ�θ���+1
* kbflag�������ж��Ǽ��̻�ͼ������껭ͼ����Ϊ��껭ͼ��������ɫ�������̻�ͼ��Ҫ����
* 1Ϊ���̻�ͼ��0Ϊ��껭ͼ
*/
void reset(int kbflag)
{
	if (kbflag == 1)
	{
		setviewport(0, 0, 1440, 720);//�ָ���ͼ����Ϊ��ʼ
		setcolor(BLACK);      //��������ɫ�ָ�Ϊ��ɫ
		setfillcolor(WHITE);  //�������ɫ�ָ�Ϊ���屳��ɫ
		graphcount++;         //ͼ�θ���+1 
	}
	else
	{
		setviewport(0, 0, 1440, 720);//�ָ���ͼ����Ϊ��ʼ
		graphcount++;         //ͼ�θ���+1 
	}
}

//��������������ͼ�ε���ɫ��ǰ��ɫ+���ɫ��
void Setgraphcolor(int r, int g, int b)
{
	setcolor(EGERGB(r, g, b));
	setfillcolor(EGERGB(r, g, b));
}