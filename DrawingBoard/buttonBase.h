/****************************************************************
*																*
* ��ͷ�ļ������˰�ť�������										*
* ��ť������Ӧ�û��ĵ����ִ����Ӧ�Ĳ���							*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4                                                         *
*                                                               *
*****************************************************************/

#ifndef BUTTON_BASE_H
#define BUTTON_BASE_H


#include <graphics.h>
#include "point.h"

// ��ť�������
// �ֶ�������������Ű�ť�����Ͻǵĵ�����½ǵĵ㣬����ť�ķ�Χ
// �Ƿ񱻵��ͨ���ж����λ���Ƿ��ڰ�ť�ķ�Χ��
// �麯��init������ְ�ť�ĳ�ʼ��
// �麯��operation����ʵ�ָ��ְ�ť�Ĳ���
// ��ļ̳�������ButtonClass.cd��ͼ��
class ButtonBase
{
public:
	ButtonBase(const Point& pt1_, const Point& pt2_);
	virtual ~ButtonBase();
	
	bool isClicked(const mouse_msg& msg);
	// ��ťͼ����ʼ�����Ѱ�ťӦ���е����ӻ���������
	virtual void init() = 0; 
	// ��ť��Ӧ����
	virtual void operation() = 0;

protected:
	Point pt1, pt2;
};

#endif // BUTTON_BASE_H