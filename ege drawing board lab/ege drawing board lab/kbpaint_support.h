void inputcheck(int, int*, int, int);    //对rgb颜色参数，x坐标和y坐标，半径，圆弧起始角，圆弧终止角，多边形顶点数进行纠错
void rgbcolor();                         //根据用户输入生成颜色
void paintline();                        //根据用户输入画直线
void paintcircle();                      //根据用户输入画圆
void paintfillcircle();                  //根据用户输入画填充圆(实际上是画一个起始角为0，终止角为360的填充扇形)
void paintrectangle();                   //根据用户输入画空心矩形
void paintbar();                         //根据用户输入画填充矩形
void paintarc();                         //根据用户输入画弧线
void paintpieslice();                    //根据用户输入画扇形
void paintdrawpoly();                    //根据用户输入画空心多边形
void paintfillpoly();                    //根据用户输入画填充多边形