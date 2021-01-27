/*���ļ������洢ͼ�β����Ľṹ�����顢�洢���ݺ���������������ͼ���ĺ�����
*����������������ԭ��ͼ���ĺ�������ԭ�������������ݺ��������ļ��ж�ȡ���ݺ�����
* ����ṹ�����鱣�����ݺ�����
*/

#include <stdio.h>
#include <graphics.h>
#include "kbpaint_support.h"
#include "allpaint_support.h"
#include "datasave.h"

struct DATA data[40];                                  //����һ���ṹ������data�洢����ͼ�ε����ݣ�DATA������datasave.h������
unsigned int cancelcount = 0;                          //cancelcount��¼�����Ĵ���
unsigned int graphcount = 0;                           //graphcount��¼��ͼ�Ĵ���

//���������ڴ洢�û�ͨ��������������ݣ��Ǽ��̻�ͼ�����еĻ���
int inputdata(void)
{
	int i, data;
	int point[4] = { 0 };//�������ÿλ�����ݵ�����
	for (i = 0; i < 4; i++)
	{
		int j;
		j = getch();  //��ȡ�û��������
		if (j == 0x0d)//�س��İ�����
		{
			break;
		}
		point[i] = j;
	}
	if (point[2] == 0 && point[1] == 0) //�����һλ�������λ��ʹ��λ����Ϊ��λ��
	{
		point[2] = point[0];
		point[1] = '0';
		point[0] = '0';
	}
	else if (point[2] == 0)            //�������λ�������λ��ʹ��λ����Ϊʮλ����ʮλ����Ϊ��λ��
	{
		point[2] = point[1];
		point[1] = point[0];
		point[0] = '0';
	}
	data = 100 * (point[0] - 48) + 10 * (point[1] - 48) + (point[2] - 48);//�����û����뻻��������
	return data;                      //���ػ���������
}

//����������ͼ���ĺ���
void cancelpaint()
{
	int i;
	setviewport(500, 20, 1440, 720);        //������ͼ����
	for (i = 0; i < graphcount - cancelcount - 1; i++)
	{
		if (data[i].type == 1)              //��ֱ��
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green, 
				data[i].rgbcolor.blue
			);
			line(
				data[i].coord[0].x, 
				data[i].coord[0].y, 
				data[i].coord[1].x, 
				data[i].coord[1].y
			);
		}
		else if (data[i].type == 2)                   //��Բ
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)                //�����Բ
			{
				pieslice(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].stangle,
					data[i].endangle,
					data[i].radius
				);
			}
			else                                      //������Բ
			{
				circle(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].radius
				);
			}
		}
		else if (data[i].type == 3)         //������
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			); 
			if (data[i].fillflag == 1)      //������
			{
				bar(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].coord[1].x,
					data[i].coord[1].y);
			}
			else                            //���ľ���
			{
				rectangle(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].coord[1].x,
					data[i].coord[1].y
				);
			}
		}
		else if (data[i].type == 4)               //������
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)            //����
			{
				pieslice(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].stangle,
					data[i].endangle,
					data[i].radius
				);
			}
			else                                  //����
			{
				arc(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].stangle,
					data[i].endangle,
					data[i].radius
				);
			}
		}
		else if (data[i].type == 5)      //�������
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)   //�������
			{
				fillpoly(
				data[i].pointcount,
					data[i].polycoord
				);
			}
			else                         //���Ķ����
			{
				drawpoly(
					data[i].pointcount,
					data[i].polycoord
				);
			}
		}
	}
	cancelcount++;                  //��������+1
	setviewport(0, 0, 1440, 720);   //����ͼ����ָ�����ʼ����
	setcolor(BLACK);                //����ɫ�ָ�Ϊ��ɫ
	setfillcolor(WHITE);            //�������ɫ�ָ�Ϊ���屳��ɫ
}

//������ԭ��ͼ���ĺ���
void restorepaint()
{
	int i;
	setviewport(500, 20, 1440, 720);                  //������ͼ����
	for (i = 0; i <= graphcount - cancelcount; i++)
	{
		if (data[i].type == 1)                        //��ֱ��
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			line(
				data[i].coord[0].x,
				data[i].coord[0].y,
				data[i].coord[1].x,
				data[i].coord[1].y
			);
		}
		else if (data[i].type == 2)                   //��Բ
		{
			Setgraphcolor(
				data[i].rgbcolor.red, 
				data[i].rgbcolor.green, 
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)                //�����Բ
			{
				pieslice(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].stangle,
					data[i].endangle,
					data[i].radius
				);
			}
			else                                      //������Բ
			{
				circle(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].radius
				);
			}
		}
		else if (data[i].type == 3)                   //������
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)                //������
			{
				bar(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].coord[1].x,
					data[i].coord[1].y
				);
			}
			else                                      //���ľ���
			{
				rectangle(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].coord[1].x,
					data[i].coord[1].y
				);
			}
		}
		else if (data[i].type == 4)                //������
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)            //����
			{
				pieslice(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].stangle,
					data[i].endangle,
					data[i].radius
				);
			}
			else                                  //����
			{
				arc(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].stangle,
					data[i].endangle,
					data[i].radius
				);
			}
		}
		else if (data[i].type == 5)                 //�������
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)             //�������
			{
				fillpoly(
					data[i].pointcount,
					data[i].polycoord
				);
			}
			else                                   //���Ķ����
			{
				drawpoly(
					data[i].pointcount,
					data[i].polycoord
				);
			}
		}
	}
	cancelcount--;                  //��������-1
	setviewport(0, 0, 1440, 720);   //����ͼ����ָ�����ʼ����
	setcolor(BLACK);                //����ɫ�ָ�Ϊ��ɫ
	setfillcolor(WHITE);            //�������ɫ�ָ�Ϊ���屳��ɫ
}

//��������
void cancel()
{
	clearpainting();                //��ջ滭����
	cancelpaint();                  //���������ͼ��
}

void restore()
{
	clearpainting();                //��ջ滭����
	restorepaint();                 //���������ͼ��
}

//���ļ��ж�ȡ���ݵĺ���
DATA* readFromFile()
{
	FILE* fp;                        //�ļ�ָ�����fp�����汣�������ļ�file.txt�ĵ�ַ
	int i;
	fp = fopen("file.txt", "rt");    //���Ѵ��ڵ�file.txt��ֻ��
	fscanf(fp, "%d\n", &graphcount); //��ȡ�����ͼ�θ���
	fscanf(fp, "\n");                //ͼ�θ�����ṹ����������֮����һ�и���
	for (i = 0; i < graphcount; i++) //��ȡfile.txt��������ݲ����浽�ṹ��������
	{
		int j;
		fscanf(fp, "%d\n", &data[i].type);
		fscanf(fp, "%d\n", &data[i].fillflag);
		fscanf(fp, "%d %d %d\n", 
			&data[i].rgbcolor.red,
			&data[i].rgbcolor.green,
			&data[i].rgbcolor.blue
		);
		fscanf(fp, "%d %d %d\n", 
			&data[i].fillrgbcolor.red,
			&data[i].fillrgbcolor.green,
			&data[i].fillrgbcolor.blue
		);
		fscanf(fp, "%d %d %d %d\n", 
			&data[i].coord[0].x, 
			&data[i].coord[0].y, 
			&data[i].coord[1].x, 
			&data[i].coord[1].y
		);
		fscanf(fp, "%d %d %d %d\n",
			&data[i].radius, 
			&data[i].stangle, 
			&data[i].endangle,
			&data[i].pointcount
		);
		for (j = 0; j < 2 * data[i].pointcount; j++)
		{
			fscanf(fp, "%d\n", &data[i].polycoord[j]);
		}
		fscanf(fp, "\n");            //�ṹ������ÿ��ͼ�ε����ݼ���һ�и���
	}
	fclose(fp);
	return data;
}

/*�����ݱ��浽�ļ��еĺ���
*dataArray����Ϊ��Ҫ�������ݵĽṹ������
*/
void writeToFile(const DATA* dataArray) 
{
	FILE* fp;                        //�ļ�ָ�����fp�����汣�������ļ�file.txt�ĵ�ַ
	int i;
	fp = fopen("file.txt", "wt");    //���Ѵ��ڵ�file.txt����������գ�ֻд
	fprintf(fp, "%d\n", graphcount); //��ӡͼ�εĸ���
	fprintf(fp, "\n");               //ͼ�θ�����ṹ����������֮����һ�и���
	for (i = 0; i < graphcount; i++) //�ѽṹ����������ݴ�ӡ��file.txt��
	{
		int j;
		fprintf(fp, "%d\n", (dataArray + i)->type);
		fprintf(fp, "%d\n", (dataArray + i)->fillflag);
		fprintf(fp, "%d %d %d\n", 
			(dataArray + i)->rgbcolor.red, 
			(dataArray + i)->rgbcolor.green,
			(dataArray + i)->rgbcolor.blue
		);
		fprintf(fp, "%d %d %d\n", 
			(dataArray + i)->fillrgbcolor.red,
			(dataArray + i)->fillrgbcolor.green,
			(dataArray + i)->fillrgbcolor.blue
		);
		fprintf(fp, "%d %d %d %d\n", 
			(dataArray + i)->coord[0].x,
			(dataArray + i)->coord[0].y,
			(dataArray + i)->coord[1].x,
			(dataArray + i)->coord[1].y
		);
		fprintf(fp, "%d %d %d %d\n", 
			(dataArray + i)->radius, 
			(dataArray + i)->stangle, 
			(dataArray + i)->endangle,
			(dataArray + i)->pointcount
		);
		for (j = 0; j < 2 * data[i].pointcount; j++)
		{
			fprintf(fp, "%d\n", (dataArray + i)->polycoord[j]);
		}
		fprintf(fp, "\n");           //�ṹ������ÿ��ͼ�ε����ݼ���һ�и���
	}
	fclose(fp);
}

//������������������ͼ������
void dataclear()
{
	int i, j, k;
	graphcount = 0;                        //ͼ����������
	for (i = 0; i < 40; i++)
	{
		data[i].type = 0;                  //ͼ�����͹���
		data[i].fillflag = 0;              //�Ƿ�������
		data[i].rgbcolor.red = 0;          //��ɫ��ɫ���ֹ���
		data[i].rgbcolor.green = 0;        //��ɫ��ɫ���ֹ���
		data[i].rgbcolor.blue = 0;         //��ɫ��ɫ���ֹ���
		data[i].fillrgbcolor.red = 0;      //�����ɫ��ɫ���ֹ���
		data[i].fillrgbcolor.green = 0;    //�����ɫ��ɫ���ֹ���
		data[i].fillrgbcolor.blue = 0;     //�����ɫ��ɫ���ֹ���
		data[i].endangle = 0;              //Բ����ֹ�ǹ���
		data[i].stangle = 0;               //Բ����ʼ�ǹ���
		data[i].radius = 0;                //Բ��Բ���뾶����
		data[i].pointcount = 0;            //����ζ���������
		for (j = 0; j < 2; j++)            //�洢�ķǶ���ε��������
		{
			data[i].coord[j].x = 0;
			data[i].coord[j].y = 0;
		}
		for (k = 0; k < 18; k++)           //�洢�Ķ�����������
		{
			data[i].polycoord[k] = 0;
		}
	}
}

//����ͼ����ɫ�ĺ���
void savegraphcolor()
{
	int color = getcolor();                                    //��ȡ��ǰ��ɫ
	int fillcolor = getfillcolor();                            //��ȡ��ǰ���ɫ
	data[graphcount].rgbcolor.red = EGEGET_R(color);           //����r����
	data[graphcount].rgbcolor.green = EGEGET_G(color);         //����g����
	data[graphcount].rgbcolor.blue = EGEGET_B(color);          //����b����
	data[graphcount].fillrgbcolor.red = EGEGET_R(fillcolor);   //�������ɫ��r����
	data[graphcount].fillrgbcolor.green = EGEGET_G(fillcolor); //�������ɫ��g����
	data[graphcount].fillrgbcolor.blue = EGEGET_B(fillcolor);  //�������ɫ��b����
}