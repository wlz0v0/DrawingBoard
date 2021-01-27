/*本文件包含存储图形参数的结构体数组、存储数据函数、画出撤销后图样的函数、
*撤销函数、画出复原后图样的函数、复原函数、保存数据函数、从文件中读取数据函数、
* 清除结构体数组保存数据函数。
*/

#include <stdio.h>
#include <graphics.h>
#include "kbpaint_support.h"
#include "allpaint_support.h"
#include "datasave.h"

struct DATA data[40];                                  //定义一个结构体数组data存储所有图形的数据，DATA类型在datasave.h中声明
unsigned int cancelcount = 0;                          //cancelcount记录撤销的次数
unsigned int graphcount = 0;                           //graphcount记录画图的次数

//本函数用于存储用户通过键盘输入的数据，是键盘画图基础中的基础
int inputdata(void)
{
	int i, data;
	int point[4] = { 0 };//存放坐标每位数数据的数组
	for (i = 0; i < 4; i++)
	{
		int j;
		j = getch();  //获取用户输入的数
		if (j == 0x0d)//回车的按键码
		{
			break;
		}
		point[i] = j;
	}
	if (point[2] == 0 && point[1] == 0) //如果是一位数则调换位置使百位数变为个位数
	{
		point[2] = point[0];
		point[1] = '0';
		point[0] = '0';
	}
	else if (point[2] == 0)            //如果是两位数则调换位置使百位数变为十位数，十位数变为个位数
	{
		point[2] = point[1];
		point[1] = point[0];
		point[0] = '0';
	}
	data = 100 * (point[0] - 48) + 10 * (point[1] - 48) + (point[2] - 48);//根据用户输入换算点的数据
	return data;                      //返回换算后的数据
}

//画出撤销后图样的函数
void cancelpaint()
{
	int i;
	setviewport(500, 20, 1440, 720);        //设置视图区域
	for (i = 0; i < graphcount - cancelcount - 1; i++)
	{
		if (data[i].type == 1)              //画直线
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
		else if (data[i].type == 2)                   //画圆
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)                //画填充圆
			{
				pieslice(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].stangle,
					data[i].endangle,
					data[i].radius
				);
			}
			else                                      //画空心圆
			{
				circle(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].radius
				);
			}
		}
		else if (data[i].type == 3)         //画矩形
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			); 
			if (data[i].fillflag == 1)      //填充矩形
			{
				bar(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].coord[1].x,
					data[i].coord[1].y);
			}
			else                            //空心矩形
			{
				rectangle(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].coord[1].x,
					data[i].coord[1].y
				);
			}
		}
		else if (data[i].type == 4)               //画弧线
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)            //扇形
			{
				pieslice(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].stangle,
					data[i].endangle,
					data[i].radius
				);
			}
			else                                  //弧线
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
		else if (data[i].type == 5)      //画多边形
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)   //填充多边形
			{
				fillpoly(
				data[i].pointcount,
					data[i].polycoord
				);
			}
			else                         //空心多边形
			{
				drawpoly(
					data[i].pointcount,
					data[i].polycoord
				);
			}
		}
	}
	cancelcount++;                  //撤销次数+1
	setviewport(0, 0, 1440, 720);   //将视图区域恢复到初始区域
	setcolor(BLACK);                //将颜色恢复为黑色
	setfillcolor(WHITE);            //把填充颜色恢复为画板背景色
}

//画出复原后图样的函数
void restorepaint()
{
	int i;
	setviewport(500, 20, 1440, 720);                  //设置视图区域
	for (i = 0; i <= graphcount - cancelcount; i++)
	{
		if (data[i].type == 1)                        //画直线
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
		else if (data[i].type == 2)                   //画圆
		{
			Setgraphcolor(
				data[i].rgbcolor.red, 
				data[i].rgbcolor.green, 
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)                //画填充圆
			{
				pieslice(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].stangle,
					data[i].endangle,
					data[i].radius
				);
			}
			else                                      //画空心圆
			{
				circle(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].radius
				);
			}
		}
		else if (data[i].type == 3)                   //画矩形
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)                //填充矩形
			{
				bar(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].coord[1].x,
					data[i].coord[1].y
				);
			}
			else                                      //空心矩形
			{
				rectangle(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].coord[1].x,
					data[i].coord[1].y
				);
			}
		}
		else if (data[i].type == 4)                //画弧线
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)            //扇形
			{
				pieslice(
					data[i].coord[0].x,
					data[i].coord[0].y,
					data[i].stangle,
					data[i].endangle,
					data[i].radius
				);
			}
			else                                  //弧线
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
		else if (data[i].type == 5)                 //画多边形
		{
			Setgraphcolor(
				data[i].rgbcolor.red,
				data[i].rgbcolor.green,
				data[i].rgbcolor.blue
			);
			if (data[i].fillflag == 1)             //填充多边形
			{
				fillpoly(
					data[i].pointcount,
					data[i].polycoord
				);
			}
			else                                   //空心多边形
			{
				drawpoly(
					data[i].pointcount,
					data[i].polycoord
				);
			}
		}
	}
	cancelcount--;                  //撤销次数-1
	setviewport(0, 0, 1440, 720);   //将视图区域恢复到初始区域
	setcolor(BLACK);                //将颜色恢复为黑色
	setfillcolor(WHITE);            //把填充颜色恢复为画板背景色
}

//撤销函数
void cancel()
{
	clearpainting();                //清空绘画区域
	cancelpaint();                  //画出保存的图形
}

void restore()
{
	clearpainting();                //清空绘画区域
	restorepaint();                 //画出保存的图形
}

//从文件中读取数据的函数
DATA* readFromFile()
{
	FILE* fp;                        //文件指针变量fp，储存保存数据文件file.txt的地址
	int i;
	fp = fopen("file.txt", "rt");    //打开已存在的file.txt，只读
	fscanf(fp, "%d\n", &graphcount); //读取保存的图形个数
	fscanf(fp, "\n");                //图形个数与结构体数组数据之间用一行隔开
	for (i = 0; i < graphcount; i++) //读取file.txt储存的数据并保存到结构体数组中
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
		fscanf(fp, "\n");            //结构体数组每个图形的数据间用一行隔开
	}
	fclose(fp);
	return data;
}

/*将数据保存到文件中的函数
*dataArray参数为需要保存数据的结构体数组
*/
void writeToFile(const DATA* dataArray) 
{
	FILE* fp;                        //文件指针变量fp，储存保存数据文件file.txt的地址
	int i;
	fp = fopen("file.txt", "wt");    //打开已存在的file.txt，将内容清空，只写
	fprintf(fp, "%d\n", graphcount); //打印图形的个数
	fprintf(fp, "\n");               //图形个数与结构体数组数据之间用一行隔开
	for (i = 0; i < graphcount; i++) //把结构体数组的数据打印到file.txt中
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
		fprintf(fp, "\n");           //结构体数组每个图形的数据间用一行隔开
	}
	fclose(fp);
}

//本函数用于清除保存的图形数据
void dataclear()
{
	int i, j, k;
	graphcount = 0;                        //图形数量归零
	for (i = 0; i < 40; i++)
	{
		data[i].type = 0;                  //图形类型归零
		data[i].fillflag = 0;              //是否填充归零
		data[i].rgbcolor.red = 0;          //颜色红色部分归零
		data[i].rgbcolor.green = 0;        //颜色绿色部分归零
		data[i].rgbcolor.blue = 0;         //颜色蓝色部分归零
		data[i].fillrgbcolor.red = 0;      //填充颜色红色部分归零
		data[i].fillrgbcolor.green = 0;    //填充颜色绿色部分归零
		data[i].fillrgbcolor.blue = 0;     //填充颜色蓝色部分归零
		data[i].endangle = 0;              //圆弧终止角归零
		data[i].stangle = 0;               //圆弧起始角归零
		data[i].radius = 0;                //圆和圆弧半径归零
		data[i].pointcount = 0;            //多边形顶点数归零
		for (j = 0; j < 2; j++)            //存储的非多边形的坐标归零
		{
			data[i].coord[j].x = 0;
			data[i].coord[j].y = 0;
		}
		for (k = 0; k < 18; k++)           //存储的多边形坐标归零
		{
			data[i].polycoord[k] = 0;
		}
	}
}

//保存图形颜色的函数
void savegraphcolor()
{
	int color = getcolor();                                    //获取当前颜色
	int fillcolor = getfillcolor();                            //获取当前填充色
	data[graphcount].rgbcolor.red = EGEGET_R(color);           //保存r参数
	data[graphcount].rgbcolor.green = EGEGET_G(color);         //保存g参数
	data[graphcount].rgbcolor.blue = EGEGET_B(color);          //保存b参数
	data[graphcount].fillrgbcolor.red = EGEGET_R(fillcolor);   //保存填充色的r参数
	data[graphcount].fillrgbcolor.green = EGEGET_G(fillcolor); //保存填充色的g参数
	data[graphcount].fillrgbcolor.blue = EGEGET_B(fillcolor);  //保存填充色的b参数
}