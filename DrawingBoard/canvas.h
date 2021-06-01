/****************************************************************
*																*
* ��ͷ�ļ������˻�����    										*
* �������������¼���λ�ã����������ʱ����ǰѡ���ͼ��			*
* �����밴ť�й�ͬ�㣬������ȫ���а�ť�����ԣ����δ�̳а�ť����		*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *															*
* lab 4                                                         *
*                                                               *
*****************************************************************/

#ifndef CANVAS_H
#define CANVAS_H
#include <graphics.h>
#include "point.h"
#include "shape.h"

// 
// ö�ٳ��������ڼ�¼��ǰѡ��滭��ͼ��
// 
enum ShapeButtons
{
	lineButton = 1,
	rectangleButton = 2,
	fillRectangleButton = 3,
	circleButton = 4,
	fillCircleButton = 5
};

// 
// ��������Ҫ��ʼ������ͼ�ν����ʼ���ڻ����ʼ��ʱ���Ѿ���ʼ�������
// �����Ĳ�����Ҫ��ȡ�������λ�ã���Ϊ��Ҫ����õ�����������ɻ�ͼ
// �ʻ�ͼ���̳а�ť����
// 
class Canvas
{
public:
	Canvas();
	bool isClicked(const mouse_msg& msg) const;
	void operation(const mouse_msg& msg);

	// �ṩ����״��ť�Ľӿڣ�������������ͼ��
	static void setTypeDrawed(int typeDrawed_); 
	

private:
	// ��¼����ͼ�ε�����
	static int typeDrawed;  
	// ��¼������ѡȡ�ĵ�ĸ����������ż����ͼ
	int pointCount; 
	// ÿһ��ͼ�ζ��������㣬���ֻ�����������
	Point pt1, pt2;
	// ֱ�������ڹ�������ͼ�εĶ��󣬿��Բ����ظ����ں����ﴴ������
	// ����Ϊָ�����new������Ȼ��浽ͼ�������У����ڽ��г���ɾ�������ȡ����
	Line* aLine;
	Circle* aCircle;
	Rectangle_* aRectangle;
};

#endif // CANVAS_H