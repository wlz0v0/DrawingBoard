/*���ļ��������̲�����ͼ�ĺ������о������������û������Զ�����ɫ������
*�����û������Զ���ֱ�ߡ�Բ�����Σ�����䣩��Բ��������Σ�����䣩������
*/

#include <graphics.h>
#include "allpaint_support.h"
#include "datasave.h"

extern DATA data[20];                       //�ṹ�����飬���ڴ洢����ͼ�ε����ݣ���datasave.cpp�д洢
extern unsigned int graphcount;             //ͼ�θ�����������datasave.cpp�д洢

/*�������Ǿ���������rgb��ɫ������x�����y���꣬�뾶��Բ����ʼ�ǣ�Բ����ֹ�ǣ�����ζ��������о���
*����ʽ�����������ݳ�����Χʱ����ʾ���ݳ�����Χ���������û���������һ�� 
*type������0Ϊ��ɫ��1Ϊx���꣬2Ϊy���꣬3Ϊ�뾶��4ΪԲ����ʼ�ǣ�5ΪԲ����ֹ�ǣ�6Ϊ����ζ�����
*input���������������ݣ�������ɫ��ΧΪ0~255��x���귶ΧΪ0~920��y���귶ΧΪ0~680���뾶��ΧΪ0~340��
*          ��ʼ�Ƿ�ΧΪ0~360����ֹ�Ƿ�ΧΪ0~360������ζ�������ΧΪ3~9
*xyprintf_x������ʹ��xyprintf��ӡ��ʾ���ʱ��x����
*xyprintf_y������ʹ��xyprintf��ӡ��ʾ���ʱ��y����
*/
void inputcheck(int type, int *input, int xyprintf_x, int xyprintf_y)
{
	if (type == 0)//��ɫ
	{
		if (*input < 0 || *input > 255)
		{
			xyprintf(xyprintf_x, xyprintf_y, "���ݳ�����Χ���밴�س���������");      //��ӡ��ʾ
			getch();                                            //�ȴ��û����س�
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//�����ӡ����ʾ
			*input = inputdata();                               //������������
		}
	}
	else if (type == 1)//x����
	{
		if (*input < 0 || *input > 920)
		{
			xyprintf(xyprintf_x, xyprintf_y, "���ݳ�����Χ���밴�س���������");      //��ӡ��ʾ
			getch();                                            //�ȴ��û����س�
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//�����ӡ����ʾ
			*input = inputdata();                               //������������
		}
	}
	else if (type == 2)//y����
	{
		if (*input < 0 || *input > 680)
		{
			xyprintf(xyprintf_x, xyprintf_y, "���ݳ�����Χ���밴�س���������");      //��ӡ��ʾ
			getch();                                            //�ȴ��û����س�
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//�����ӡ����ʾ
			*input = inputdata();                               //������������
		}
	}
	else if (type == 3)//Բ��Բ���İ뾶
	{
		if (*input < 0 || *input > 340)
		{
			xyprintf(xyprintf_x, xyprintf_y, "���ݳ�����Χ���밴�س���������");      //��ӡ��ʾ
			getch();                                            //�ȴ��û����س�
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//�����ӡ����ʾ
			*input = inputdata();                               //������������
		}
	}
	else if (type == 4)//��ʼ�ǽǶ�
	{
		if (*input < 0 || *input > 360)
		{
			xyprintf(xyprintf_x, xyprintf_y, "���ݳ�����Χ���밴�س���������");      //��ӡ��ʾ
			getch();                                            //�ȴ��û����س�
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//�����ӡ����ʾ
			*input = inputdata();                               //������������
		}
	}
	else if (type == 5)//��ֹ�ǽǶ�
	{
		if (*input < 0 || *input > 360)
		{
			xyprintf(xyprintf_x, xyprintf_y, "���ݳ�����Χ���밴�س���������");      //��ӡ��ʾ
			getch();                                            //�ȴ��û����س�
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//�����ӡ����ʾ
			*input = inputdata();                               //������������
		}
	}
	else if (type == 6)//����ε���
	{
		if (*input < 3 || *input > 9)
		{
			xyprintf(xyprintf_x, xyprintf_y, "���ݳ�����Χ���밴�س���������");      //��ӡ��ʾ
			getch();                                            //�ȴ��û����س�
			xyprintf(xyprintf_x, xyprintf_y, "                                 ");//�����ӡ����ʾ
			*input = inputdata();                               //������������
		}
	}
}

//����������Ϊ�����û��Զ��������RGBֵ���е�ɫ
void rgbcolor()
{
	int red, green, blue;//redΪEGERGB��r������greenΪEGERGB��g������blueΪEGERGB��b����
	xyprintf(0, 420, "������RGB�Ĳ���:");//��ӡ��ʾ���
	xyprintf(0, 440, "R, G, B");
	xyprintf(0, 460, "��ע�⣬���������λ����ÿ����һ�������밴�س�");
	red = inputdata();                   //��ȡ�û������r����
	inputcheck(0, &red, 0, 480);          //��������Ƿ���ȷ
	xyprintf(0, 480, "red=%d", red);      //��ӡr������ֵ
	green = inputdata();                 //��ȡ�û������g����
	inputcheck(0, &green, 0, 500);        //��������Ƿ���ȷ
	xyprintf(0, 500, "green=%d", green);  //��ӡg������ֵ
	blue = inputdata();                  //��ȡ�û������b����
	inputcheck(0, &blue, 0, 520);         //��������Ƿ���ȷ
	xyprintf(0, 520, "blue=%d", blue);    //��ӡb������ֵ
	Setgraphcolor(red, green, blue);      //����ͼ����ɫ
}

//����������Ϊ�����û��Զ�����������껭ֱ��
void paintline()
{
	data[graphcount].type = 1;
	savegraphcolor();                                  //����ͼ����ɫ
	xyprintf(0, 420, "�밴˳������ֱ������:");           //��ӡ��ʾ���
	xyprintf(0, 440, "x1, y1, x2, y2");
	xyprintf(0, 460, "��ע�⣬���������λ����ÿ����һ�������밴�س�");
	data[graphcount].coord[0].x = inputdata();             //��ȡ�û������x1���� 
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);    //��������Ƿ���ȷ
	xyprintf(0, 480, "x1=%d", data[graphcount].coord[0].x); //��ӡ�û������x1����
	data[graphcount].coord[0].y = inputdata();             //��ȡ�û������y1����
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);    //��������Ƿ���ȷ
	xyprintf(0, 500, "y1=%d", data[graphcount].coord[0].y); //��ӡ�û������y1����
	data[graphcount].coord[1].x = inputdata();             //��ȡ�û������x2����
	inputcheck(1, &data[graphcount].coord[1].x, 0, 520);    //��������Ƿ���ȷ
	xyprintf(0, 520, "x2=%d", data[graphcount].coord[1].x); //��ӡ�û������x2����
	data[graphcount].coord[1].y = inputdata();             //��ȡ�û������y2����
	inputcheck(2, &data[graphcount].coord[1].y, 0, 540);    //��������Ƿ���ȷ
	xyprintf(0, 540, "y2=%d", data[graphcount].coord[1].y); //��ӡ�û������y2����
	setviewport(500, 20, 1440, 720);                        //����ͼ���������ڻ�ͼ����
	line(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].coord[1].x, data[graphcount].coord[1].y);
	reset(1); //���û�������
}

//����������Ϊ�����û��Զ�����������껭Բ
void paintcircle()
{
	data[graphcount].type = 2;
	data[graphcount].fillflag = 0;
	savegraphcolor();                                  //����ͼ����ɫ
	xyprintf(0, 420, "�밴˳������Բ�Ĳ���:");           //��ӡ��ʾ���
	xyprintf(0, 440, "x, y, r");
	xyprintf(0, 460, "��ע�⣬���������λ����ÿ����һ�������밴�س�");
	data[graphcount].coord[0].x = inputdata();
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);//��������Ƿ���ȷ
	xyprintf(0, 480, "x=%d", data[graphcount].coord[0].x);
	data[graphcount].coord[0].y = inputdata();
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);//��������Ƿ���ȷ
	xyprintf(0, 500, "y=%d", data[graphcount].coord[0].y);
	data[graphcount].radius = inputdata();
	inputcheck(3, &data[graphcount].radius, 0, 520);//��������Ƿ���ȷ
	xyprintf(0, 520, "r=%d", data[graphcount].radius);
	setviewport(500, 20, 1440, 720);//������ͼ����Ϊ��ͼ����
	circle(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].radius);
	reset(1); //���û�������
}

//����������Ϊ�����û��Զ�����������껭���Բ(ʵ�����ǻ�һ����ʼ��Ϊ0����ֹ��Ϊ360���������)
void paintfillcircle()
{
	data[graphcount].type = 2;
	data[graphcount].fillflag = 1;
	savegraphcolor();                                  //����ͼ����ɫ
	xyprintf(0, 420, "�밴˳������Բ�Ĳ���:");            //��ӡ��ʾ���
	xyprintf(0, 440, "x, y, r");
	xyprintf(0, 460, "��ע�⣬���������λ����ÿ����һ�������밴�س�");
	data[graphcount].coord[0].x = inputdata();
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);//��������Ƿ���ȷ
	xyprintf(0, 480, "x=%d", data[graphcount].coord[0].x);
	data[graphcount].coord[0].y = inputdata();
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);//��������Ƿ���ȷ
	xyprintf(0, 500, "y=%d", data[graphcount].coord[0].y);
	data[graphcount].radius = inputdata();
	inputcheck(3, &data[graphcount].radius, 0, 520);    //��������Ƿ���ȷ
	xyprintf(0, 560, "r=%d", data[graphcount].radius);
	data[graphcount].stangle = 0;
	data[graphcount].endangle = 360;
	setviewport(500, 20, 1440, 720);//������ͼ����Ϊ��ͼ����
	pieslice(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].stangle, data[graphcount].endangle, data[graphcount].radius);
	reset(1); //���û�������
}

//����������Ϊ�����û��Զ�����������껭���ľ���
void paintrectangle()
{
	data[graphcount].type = 3;
	data[graphcount].fillflag = 0;
	savegraphcolor();                                  //����ͼ����ɫ
	xyprintf(0, 420, "�밴˳�������������:");
	xyprintf(0, 440, "x1, y1, x2, y2");
	xyprintf(0, 460, "��ע�⣬���������λ����ÿ����һ�������밴�س�");
	data[graphcount].coord[0].x = inputdata();
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);//��������Ƿ���ȷ
	xyprintf(0, 480, "x1=%d", data[graphcount].coord[0].x);
	data[graphcount].coord[0].y = inputdata();
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);//��������Ƿ���ȷ
	xyprintf(0, 500, "y1=%d", data[graphcount].coord[0].y);
	data[graphcount].coord[1].x = inputdata();
	inputcheck(1, &data[graphcount].coord[1].x, 0, 520);//��������Ƿ���ȷ
	xyprintf(0, 520, "x2=%d", data[graphcount].coord[1].x);
	data[graphcount].coord[1].y = inputdata();
	inputcheck(2, &data[graphcount].coord[1].y, 0, 540);//��������Ƿ���ȷ
	xyprintf(0, 540, "y2=%d", data[graphcount].coord[1].y);
	setviewport(500, 20, 1440, 720);//������ͼ����Ϊ��ͼ����
	rectangle(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].coord[1].x, data[graphcount].coord[1].y);
	reset(1); //���û�������
}

//����������Ϊ�����û��Զ�����������껭������
void paintbar()
{
	data[graphcount].type = 3;
	data[graphcount].fillflag = 1;
	savegraphcolor();                                  //����ͼ����ɫ
	xyprintf(0, 420, "�밴˳�������������:");
	xyprintf(0, 440, "x1, y1, x2, y2");
	xyprintf(0, 460, "��ע�⣬���������λ����ÿ����һ�������밴�س�");
	data[graphcount].coord[0].x = inputdata();
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);//��������Ƿ���ȷ
	xyprintf(0, 480, "x1=%d", data[graphcount].coord[0].x);
	data[graphcount].coord[0].y = inputdata();
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);//��������Ƿ���ȷ
	xyprintf(0, 500, "y1=%d", data[graphcount].coord[0].y);
	data[graphcount].coord[1].x = inputdata();
	inputcheck(1, &data[graphcount].coord[1].x, 0, 520);//��������Ƿ���ȷ
	xyprintf(0, 520, "x2=%d", data[graphcount].coord[1].x);
	data[graphcount].coord[1].y = inputdata();
	inputcheck(2, &data[graphcount].coord[1].y, 0, 540);//��������Ƿ���ȷ
	xyprintf(0, 540, "y2=%d", data[graphcount].coord[1].y);
	setviewport(500, 20, 1440, 720);//������ͼ����Ϊ��ͼ����
	bar(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].coord[1].x, data[graphcount].coord[1].y);
	reset(1); //���û�������
}

//����������Ϊ�����û��Զ�����������껭Բ��
void paintarc()
{
	data[graphcount].type = 4;
	data[graphcount].fillflag = 0;
	savegraphcolor();                                  //����ͼ����ɫ
	xyprintf(0, 420, "�밴˳������Բ���Ĳ���:");
	xyprintf(0, 440, "x, y, ��ʼ�Ƕ�, ��ֹ�Ƕ�, r");
	xyprintf(0, 460, "��ע�⣬���������λ����ÿ����һ�������밴�س�");
	data[graphcount].coord[0].x = inputdata();
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);//��������Ƿ���ȷ
	xyprintf(0, 480, "x=%d", data[graphcount].coord[0].x);
	data[graphcount].coord[0].y = inputdata();
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);//��������Ƿ���ȷ
	xyprintf(0, 500, "y=%d", data[graphcount].coord[0].y);
	data[graphcount].stangle = inputdata();
	inputcheck(4, &data[graphcount].stangle, 0, 520);//��������Ƿ���ȷ
	xyprintf(0, 520, "��ʼ�Ƕ�=%d��", data[graphcount].stangle);
	data[graphcount].endangle = inputdata();
	inputcheck(5, &data[graphcount].endangle, 0, 540);//��������Ƿ���ȷ
	xyprintf(0, 540, "��ֹ�Ƕ�=%d��", data[graphcount].endangle);
	data[graphcount].radius = inputdata();
	inputcheck(3, &data[graphcount].radius, 0, 560);//��������Ƿ���ȷ
	xyprintf(0, 560, "r=%d", data[graphcount].radius);
	setviewport(500, 20, 1440, 720);//������ͼ����Ϊ��ͼ����
	arc(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].stangle, data[graphcount].endangle, data[graphcount].radius);
	reset(1); //���û�������
}

//����������Ϊ�����û��Զ�����������껭����
void paintpieslice()
{
	data[graphcount].type = 4;
	data[graphcount].fillflag = 1;
	savegraphcolor();                                  //����ͼ����ɫ
	xyprintf(0, 420, "�밴˳������Բ���Ĳ���:");
	xyprintf(0, 440, "x, y, ��ʼ�Ƕ�, ��ֹ�Ƕ�, r");
	xyprintf(0, 460, "��ע�⣬���������λ����ÿ����һ�������밴�س�");
	data[graphcount].coord[0].x = inputdata();
	inputcheck(1, &data[graphcount].coord[0].x, 0, 480);//��������Ƿ���ȷ
	xyprintf(0, 480, "x=%d", data[graphcount].coord[0].x);
	data[graphcount].coord[0].y = inputdata();
	inputcheck(2, &data[graphcount].coord[0].y, 0, 500);//��������Ƿ���ȷ
	xyprintf(0, 500, "y=%d", data[graphcount].coord[0].y);
	data[graphcount].stangle = inputdata();
	inputcheck(4, &data[graphcount].stangle, 0, 520);//��������Ƿ���ȷ
	xyprintf(0, 520, "��ʼ�Ƕ�=%d��", data[graphcount].stangle);
	data[graphcount].endangle = inputdata();
	inputcheck(5, &data[graphcount].endangle, 0, 540);//��������Ƿ���ȷ
	xyprintf(0, 540, "��ֹ�Ƕ�=%d��", data[graphcount].endangle);
	data[graphcount].radius = inputdata();
	inputcheck(3, &data[graphcount].radius, 0, 560);//��������Ƿ���ȷ
	xyprintf(0, 560, "r=%d", data[graphcount].radius);
	setviewport(500, 20, 1440, 720);//������ͼ����Ϊ��ͼ����
	pieslice(data[graphcount].coord[0].x, data[graphcount].coord[0].y, data[graphcount].stangle, data[graphcount].endangle, data[graphcount].radius);
	reset(1); //���û�������
}

//����������Ϊ�����û��Զ�����������껭���Ķ����
void paintdrawpoly()
{
	int i;
	data[graphcount].type = 5;
	data[graphcount].fillflag = 0;
	savegraphcolor();                                  //����ͼ����ɫ
	xyprintf(0, 420, "�밴˳������������εĲ���:");
	xyprintf(0, 440, "����ζ������(���Ÿ�)����������");
	xyprintf(0, 460, "��ע�⣬���������λ����ÿ����һ�������밴�س�");
	data[graphcount].pointcount = getch();//�������ζ�����
	data[graphcount].pointcount = data[graphcount].pointcount - 48;//�������ζ�����
	inputcheck(6, &data[graphcount].pointcount, 0, 480);//��������Ƿ���ȷ
	xyprintf(0, 480, "�������Ϊ%d", data[graphcount].pointcount);
	for (i = 0; i < data[graphcount].pointcount; i++)
	{
		data[graphcount].polycoord[2 * i] = inputdata();//�������ζ����x����
		if ((500 + i * 40) <= 700)//�жϴ�ӡ�����Ƿ񳬳����壬��������������ӡ��ʾ����
		{
			inputcheck(1, &data[graphcount].polycoord[2 * i], 0, 500 + i * 40);//��������Ƿ���ȷ
			xyprintf(0, 500 + i * 40, "��%d������x����Ϊ%d", i + 1, data[graphcount].polycoord[2 * i]);
		}
		else if ((500 + i * 40) > 700)//�������ڻ������û����������Ҳ��ӡ��ʾ����
		{
			inputcheck(1, &data[graphcount].polycoord[2 * i], 220, 300 + i * 40);//��������Ƿ���ȷ
			xyprintf(220, 300 + i * 40, "��%d������x����Ϊ%d", i + 1, data[graphcount].polycoord[2 * i]);
		}
		data[graphcount].polycoord[2 * i + 1] = inputdata();//�������ζ����y����
		if ((520 + i * 40) <= 700)//�жϴ�ӡ�����Ƿ񳬳����壬��������������ӡ��ʾ����
		{
			inputcheck(2, &data[graphcount].polycoord[2 * i], 0, 520 + i * 40);//��������Ƿ���ȷ
			xyprintf(0, 520 + i * 40, "��%d������y����Ϊ%d", i + 1, data[graphcount].polycoord[2 * i + 1]);
		}
		else if ((520 + i * 40) > 700)//�������ڻ������û����������Ҳ��ӡ��ʾ����
		{
			inputcheck(2, &data[graphcount].polycoord[2 * i], 220, 320 + i * 40);//��������Ƿ���ȷ
			xyprintf(220, 320 + i * 40, "��%d������y����Ϊ%d", i + 1, data[graphcount].polycoord[2 * i + 1]);
		}
	}
	setviewport(500, 20, 1440, 720);//������ͼ����Ϊ��ͼ����
	drawpoly(data[graphcount].pointcount, data[graphcount].polycoord);
	reset(1); //���û�������
}

//����������Ϊ�����û��Զ�����������껭�������
void paintfillpoly()
{
	int i;
	data[graphcount].type = 5;
	data[graphcount].fillflag = 1;
	savegraphcolor();                                  //����ͼ����ɫ
	xyprintf(0, 420, "�밴˳������������εĲ���:");
	xyprintf(0, 440, "����ζ����������������");
	xyprintf(0, 460, "��ע�⣬���������λ����ÿ����һ�������밴�س�");
	data[graphcount].pointcount = getch();//�������ζ�����
	data[graphcount].pointcount = data[graphcount].pointcount - 48;//�������ζ�����
	inputcheck(6, &data[graphcount].pointcount, 0, 480);//��������Ƿ���ȷ
	xyprintf(0, 480, "�������Ϊ%d", data[graphcount].pointcount);
	for (i = 0; i < data[graphcount].pointcount; i++)
	{
		data[graphcount].polycoord[2 * i] = inputdata();//�������ζ����x����
		if ((500 + i * 40) <= 700)//�жϴ�ӡ�����Ƿ񳬳����壬��������������ӡ��ʾ����
		{
			inputcheck(1, &data[graphcount].polycoord[2 * i], 0, 500 + i * 40);//��������Ƿ���ȷ
			xyprintf(0, 500 + i * 40, "��%d������x����Ϊ%d", i + 1, data[graphcount].polycoord[2 * i]);
		}
		else if ((500 + i * 40) > 700)//�������ڻ������û����������Ҳ��ӡ��ʾ����
		{
			inputcheck(1, &data[graphcount].polycoord[2 * i], 220, 300 + i * 40);//��������Ƿ���ȷ
			xyprintf(220, 300 + i * 40, "��%d������x����Ϊ%d", i + 1, data[graphcount].polycoord[2 * i]);
		}
		data[graphcount].polycoord[2 * i + 1] = inputdata();//�������ζ����y����
		if ((520 + i * 40) <= 700)//�жϴ�ӡ�����Ƿ񳬳����壬��������������ӡ��ʾ����
		{
			inputcheck(2, &data[graphcount].polycoord[2 * i], 0, 520 + i * 40);//��������Ƿ���ȷ
			xyprintf(0, 520 + i * 40, "��%d������y����Ϊ%d", i + 1, data[graphcount].polycoord[2 * i + 1]);
		}
		else if ((520 + i * 40) > 700)//�������ڻ������û����������Ҳ��ӡ��ʾ����
		{
			inputcheck(2, &data[graphcount].polycoord[2 * i], 220, 320 + i * 40);//��������Ƿ���ȷ
			xyprintf(220, 320 + i * 40, "��%d������y����Ϊ%d", i + 1, data[graphcount].polycoord[2 * i + 1]);
		}
	}
	setviewport(500, 20, 1440, 720);//������ͼ����Ϊ��ͼ����
	fillpoly(data[graphcount].pointcount, data[graphcount].polycoord);
	reset(1); //���û�������
}