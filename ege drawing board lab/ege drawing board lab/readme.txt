作者：武连增
程序功能：本程序是基于ege库制作的画板，该画板可以读取文件信息，并根据用户的指令完成画图任务，更多功能尚待开发。
注意事项：1.本程序运行时必须使用英文输入法，否则可能会运行异常！！！
         2.常用颜色的rgb对照表详见rgb table.txt；
         3.inputbox_getline函数出现了意料之外的错误，所以无法使用；
         4.填充功能中直线无填充功能（显然不可能有），其他图形均可填充；
         5.重画功能在清屏的同时也会清除之前保存的图形数据，主要用于清除保存的数据；
         6.绘制空心多边形时，不会自动连接首尾，如果需要封闭多边形，请将最后一个点与第一个点坐标设置相同；
         7.本画板初始的文件数据储存在init.txt内，第一次读取文件也可以画出该图形，如果想再次画出，请手动把initgraph.txt内的数据copy到file.txt内；
         8.fopen与fscanf函数无法通过安全性检查，若提示错误，请把项目属性——C/C++——常规——SDL检查的是改为否。
目的：当然是为了交C语言作业啦~（×）
——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————
更新日志：
lab04第一次提交更新：
1.增加了鼠标操作（有点简陋哈）！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
2.增加了读取文件函数；
3.增加了将结构体数组保存到文件的函数；
4.加入了画圆弧填充功能（扇形）；
5.加入了画圆填充功能（用扇形画的）；
6.加入了纠错功能；
7.加入了一个可读的初始的图画文件；
8.简化了画各种图形的函数，删除了一些冗杂的内容，结构更清晰了（然并卵，还是很冗杂）；
9.更改了画多边形时打印坐标的提示；
10.更改了重画功能，在清屏的同时也会清空结构体数组保存的数据，并且会有提示谨慎重画（谨慎重画这个功能在做鼠标操作的时候属实让我觉得我好nt）；
11.又修复了一些bug，可能还有，希望没有了。

lab04第二次提交更新：
12.和上一次的lab04提交后又多了一个在开始界面对错误输入的处理；
13.writeToFile函数形参类型由指针改为常量指针；
14.在对应的fopen后加了fclose(在lab4编写的某个版本中应该是有fclose的，不知道发生了甚么事fclose消失了)。
*****************************************************************************************************
头文件声明内容（结构体以及函数）：

datasave.h(与数据和存储有关)：
typedef struct Point;                 //Point结构体类型定义整型的x，y储存一个点的横纵坐标
typedef struct color;                 //color结构体类型定义整型的red，green，blue三个变量储存一个颜色RGB的值
typedef struct DATA;                  //DATA结构体类型包含了一个图形的各种参数
int inputdata(void);                  //本函数用于存储用户通过键盘输入的数据
void cancel();                        //撤销函数
void restore();                       //复原函数
void cancelpaint();                   //画出撤销后图样的函数
void restorepaint();                  //画出复原后图样的函数
DATA* readFromFile();                 //读取文件中的数据的函数
void writeToFile(const DATA*);        //将数据保存到文件中的函数
void dataclear();                     //清除保存的图形数据的函数
void savegraphcolor();                //保存图形颜色的函数

interaction.h（与和用户交互有关）：
void initialize();                    //初始化函数
int readFile(void);                   //读取文件函数
void kbmenu();                        //根据读取文件的结果显示键盘菜单
void kbpainting();                    //键盘作图函数
void mousepaintinit_graph();          //鼠标操作初始化图片部分函数
void mousepaintinit_text();           //鼠标操作初始化文本部分函数
void mousemenu();                     //显示鼠标操作菜单
void mousepainting();                 //鼠标作图函数

allpaint_support.h（与通用的作图有关）:
void clearword();                     //本函数功能为清除一部分文字
void clearpainting();                 //本函数用于清除图画部分
void repaint();                       //重画函数
void reset(int);                      //重置函数
void Setgraphcolor(int, int, int);    //设置图形的颜色（前景色+填充色）

kbpaint_support.h（与键盘作图有关）：
void inputcheck(int, int*, int, int); //对rgb颜色参数，x坐标和y坐标，半径，圆弧起始角，圆弧终止角，多边形顶点数进行纠错
void rgbcolor();                      //根据用户输入生成颜色
void paintline();                     //根据用户输入画直线
void paintcircle();                   //根据用户输入画圆
void paintfillcircle();               //根据用户输入画填充圆(实际上是画一个起始角为0，终止角为360的填充扇形)
void paintrectangle();                //根据用户输入画空心矩形
void paintbar();                      //根据用户输入画填充矩形
void paintarc();                      //根据用户输入画弧线
void paintpieslice();                 //根据用户输入画扇形
void paintdrawpoly();                 //根据用户输入画空心多边形
void paintfillpoly();                 //根据用户输入画填充多边形

mousepaint_support.h（与鼠标作图有关）：
void mousepaintline();                //用鼠标画直线函数
void mousepaintcircle();              //用鼠标画空心圆函数
void mousepaintfillcircle();          //用鼠标画填充函数
void mousepaintrectangle();           //用鼠标画空心矩形函数
void mousepaintbar();                 //用鼠标画填充矩形函数
——————————————————————————————————————————————————————————————————————————————————————————————————————
P.S.:1.可以在faq中教教怎么防止秃头吗？（桌子下的头发都扫不干净了ToT）
     2.代码有些乱= =（尤其是mousepainting函数里的大概30个分支，我麻了）