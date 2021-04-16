#ifndef SHAPE_BUTTON_H
#define SHAPE_BUTTON_H
// ��ͷ�ļ��а�������״��ť�༰�����ֱࣺ�߰�ť�ࡢԲ��ť�ࡢ���ΰ�ť��

#include "buttonBase.h"
#include "shape.h"

// ��״��ť�����ڻ���������״
// �̳��˰�ť���࣬���и�����״����
// �ֶ��к��Ƿ����
class ShapeButton : public ButtonBase
{
protected:
	bool isFill;
public:
	ShapeButton(const Point& pt1_, const Point& pt2_, bool isFill_);
	virtual void init() = 0;
	virtual void operation() = 0;
};

// ֱ��ͼ�ΰ�ť
// �̳�����״��ť�࣬������
// �ֶ���һ��ֱ��ָ�������ÿ����һ��ֱ�߶��ᱻnew��Ȼ����ӵ�Shape�ྲ̬vector shapes��
// ֱ������䣬isFillĬ��Ϊfalse
class LineButton final : public ShapeButton
{
private:
	Line* aLine;

public:
	LineButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// Բ��ͼ�ΰ�ť
// �̳�����״��ť�࣬������
// �ֶ���һ��Բ��ָ�������ÿ����һ��Բ���ᱻnew��Ȼ����ӵ�Shape�ྲ̬vector shapes��
// Բ�����Բ�Ϳ���Բ
class CircleButton final : public ShapeButton
{
private:
	Circle* aCircle;

public:
	CircleButton(const Point& pt1_, const Point& pt2_, bool isFill_);
	virtual void init();
	virtual void operation();
};

// ����ͼ�ΰ�ť
// �̳�����״��ť�࣬������
// �ֶ���һ������ָ�������ÿ����һ�����ζ��ᱻnew��Ȼ����ӵ�Shape�ྲ̬vector shapes��
// ������ʵ�ĺͿ���
class RectangleButton final : public ShapeButton
{
private:
	Rectangle_* aRectangle;

public:
	RectangleButton(const Point& pt1_, const Point& pt2_, bool isFill_);
	virtual void init();
	virtual void operation();
};

#endif // SHAPE_BUTTON_H