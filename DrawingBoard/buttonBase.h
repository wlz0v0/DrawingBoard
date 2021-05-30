#ifndef BUTTON_BASE_H
#define BUTTON_BASE_H
// ��ͷ�ļ������˰�ť�������

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
protected:
	Point pt1, pt2;
public:

	ButtonBase(const Point& pt1_, const Point& pt2_);
	virtual ~ButtonBase();
	
	bool isClicked(const mouse_msg& msg);
	virtual void init() = 0; // ��ťͼ����ʼ��
	virtual void operation() = 0; // ��ť��Ӧ����
};

#endif // BUTTON_BASE_H