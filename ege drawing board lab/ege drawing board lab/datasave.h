typedef struct Point                                  //Point���Ͷ������͵�x��y����һ����ĺ�������
{
	int x;
	int y;
};

typedef struct color                                  //color���Ͷ������͵�red��green��blue������������һ����ɫRGB��ֵ
{
	int red;
	int green;
	int blue;
};

typedef struct DATA							    		//DATA�ṹ�������һ��ͼ�εĸ��ֲ���
{
	color rgbcolor, fillrgbcolor;                      //rgbcolor��ű߿���ɫ��fillrgbcolor��������ɫ
	Point coord[2];                                    //coord�����Ŷ�������꣨��������⣩
	unsigned int type;                                 //type���ͼ�����ͣ�ֱ��Ϊ1��ԲΪ2������Ϊ3������Ϊ4�������Ϊ5��
	int radius, stangle, endangle, pointcount;         //radius���Բ�İ뾶��stangle���Բ����ʼ�Ƕȣ�endangle���Բ����ֹ�Ƕȣ�pointcount��Ŷ���εĶ�����
	int polycoord[18];                                 //polycoord��Ŷ���ε�����
	unsigned int fillflag;                             //fillflag����Ƿ���䣬0Ϊ��1Ϊ��
};

int inputdata(void);                  //���������ڴ洢�û�ͨ���������������
void cancel();                        //��������
void restore();                       //��ԭ����
void cancelpaint();                   //����������ͼ���ĺ���
void restorepaint();                  //������ԭ��ͼ���ĺ���
DATA* readFromFile();                 //��ȡ�ļ��е����ݵĺ���
void writeToFile(const DATA*);        //�����ݱ��浽�ļ��еĺ���
void dataclear();                     //��������ͼ�����ݵĺ���
void savegraphcolor();                //����ͼ����ɫ�ĺ���