typedef struct Point                                  //Point类型定义整型的x，y储存一个点的横纵坐标
{
	int x;
	int y;
};

typedef struct color                                  //color类型定义整型的red，green，blue三个变量储存一个颜色RGB的值
{
	int red;
	int green;
	int blue;
};

typedef struct DATA							    		//DATA结构体包含了一个图形的各种参数
{
	color rgbcolor, fillrgbcolor;                      //rgbcolor存放边框颜色，fillrgbcolor存放填充颜色
	Point coord[2];                                    //coord数组存放顶点的坐标（除多边形外）
	unsigned int type;                                 //type存放图形类型（直线为1，圆为2，矩形为3，弧线为4，多边形为5）
	int radius, stangle, endangle, pointcount;         //radius存放圆的半径，stangle存放圆弧起始角度，endangle存放圆弧终止角度，pointcount存放多边形的顶点数
	int polycoord[18];                                 //polycoord存放多边形点坐标
	unsigned int fillflag;                             //fillflag存放是否填充，0为否，1为是
};

int inputdata(void);                  //本函数用于存储用户通过键盘输入的数据
void cancel();                        //撤销函数
void restore();                       //复原函数
void cancelpaint();                   //画出撤销后图样的函数
void restorepaint();                  //画出复原后图样的函数
DATA* readFromFile();                 //读取文件中的数据的函数
void writeToFile(const DATA*);        //将数据保存到文件中的函数
void dataclear();                     //清除保存的图形数据的函数
void savegraphcolor();                //保存图形颜色的函数