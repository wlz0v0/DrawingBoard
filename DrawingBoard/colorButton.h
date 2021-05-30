#ifndef COLOR_BUTTON_H
#define COLOR_BUTTON_H
// ��ͷ�ļ��а�������ɫ��ť��

#include "buttonBase.h"
#include "color.h"

// ��ɫ��ť����������ͼ�ε���ɫ
// �̳��˰�ť���࣬������
// �ֶ��е���ɫ�����Ű�ťʵ����Ӧ����ɫ
class ColorButton final : public ButtonBase
{
public:
	ColorButton(const Point& pt1_, const Point& pt2_, const Color& color);
	virtual void init();
	virtual void operation();
private:
	Color buttonColor; // ��ɫ��ť����ɫ
};

#endif // COLOR_BUTTON_H