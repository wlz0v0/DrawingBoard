#ifndef SHAPE_H
#define SHAPE_H
// ��ͷ�ļ��а�����״������༰����������ڻ�ͼ�ķǳ�Ա������
// ֱ���ࡢԲ�ࡢ������

#include <vector>
#include "color.h"
#include "point.h"

enum TypeName
{
	typeLine = 1,
	typeCircle = 2,
	typeRectangle = 3
};

// ��״�������
// �ֶ�����״����ɫ���Ƿ���䣬���ͺ���״������
// �Լ�һ����̬����shapes���ڴ�����״������
// �����л�����״ʵ������
// ��������������������
class Shape
{
protected:
	Color color;
	bool isFill;
	int type;
	Point pt1, pt2;

public:
	static std::vector<Shape*> shapes;

	Shape(int type_);
	virtual ~Shape() = default;

	void setColor(const Color& color_);
	void setIsFill(bool isFill_);
	void setPt1(int x_, int y_);
	void setPt2(int x_, int y_);

	Color getColor();
	int getType();
	Point getPt1();
	Point getPt2();
	static size_t getShapeCount();

	virtual void drawShape() = 0; 

	friend std::ostream& operator<<(std::ostream& os, Shape& shape);
	friend std::istream& operator>>(std::istream& is, Shape& shape);
};

// ֱ����
// �̳�����״����
// ֱ������䣬�Ƿ����Ĭ��Ϊfalse
// ����Ϊȷ��ֱ�ߵ�����
class Line : public Shape
{
public:
	Line();
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Line& line);
	friend std::istream& operator>>(std::istream& is, Line& line);
};

// Բ��
// �̳�����״����
// Բ����䣬���Բ���������ʵ��
// ����Ϊ��һ��ΪԲ�ģ�����һ�㵽Բ�ĵľ���Ϊ�뾶
class Circle : public Shape
{
public:
	Circle();
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Circle& circle);
	friend std::istream& operator>>(std::istream& is, Circle& circle);
};

// ������
// �̳�����״����
// ���ο����
// ����Ϊ���ε����Ͻǵ�����½ǵ�
// ��������»�������Ϊege���д���һ��Rectangle��
// ege���ƺ�ֱ��using namespace ege;ʹ�������ռ���Щ����
class Rectangle_ : public Shape
{
public:
	Rectangle_();
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Rectangle_& rectangle);
	friend std::istream& operator>>(std::istream& is, Rectangle_& rectangle);
};

// �ǳ�Ա����
void drawAShape(Shape& shape, bool isFill_); // ���ö�̬����һ����״
void drawShapes(); // ��shapes�д�������ݻ�����
void clearShapes(); // ���shapes

#endif // SHAPE_H