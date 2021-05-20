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
	typeRectangle = 3,
	typeTriangle = 4
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

	explicit Shape(int type_);
	Shape(const Color& color_, const Point& pt1_, const Point& pt2_,
		bool isFill, int type);
	virtual ~Shape() = default;

	void setType(int type_);
	void setColor(const Color& color_);
	void setIsFill(bool isFill_);
	void setPt1(int x_, int y_);
	void setPt2(int x_, int y_);

	Color getColor();
	int getType();
	Point getPt1();
	Point getPt2();
	static size_t getShapeCount();

	virtual void drawShape() = 0; // draw function

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
	Line(const Line& rhs);
	Line(const Point& pt1, const Point& pt2);
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
	Circle(const Circle& rhs);
	Circle(const Point& pt1, const Point& pt2, bool isFill);
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
	Rectangle_(const Rectangle_& rhs);
	Rectangle_(const Point& pt1, const Point& pt2, bool isFill);
	virtual void drawShape();
	friend std::ostream& operator<<(std::ostream& os, Rectangle_& rectangle);
	friend std::istream& operator>>(std::istream& is, Rectangle_& rectangle);
};

// �������������Ϊ����ҵ��ʵ���ϵĻ��岢û�л���������εĲ���
// ԭ�����ڻ���Ĳ������������֮��ֻ������һ��ֱ�߰�ť������Բ��ť���������ΰ�Ŧ
// û�и�������ͼ�����ռ䣬���Խ��ڳ�����дһ��Triangle�࣬����ʵ�ʻ�����û�л��Ĳ���
// 
class Triangle : public Shape
{
private:
	Point pt3;
public:
	Triangle();
	Triangle(const Triangle& rhs);
	Point getPt3();
	void setPt3(const Point& pt3_);
	virtual void drawShape();
};

// �ǳ�Ա����
void drawAShape(Shape& shape); // ���ö�̬����һ����״
void drawShapes(); // ��shapes�д�������ݻ�����
void clearShapes(); // ���shapes
void inputShape(std::istream& is, Shape& shape);

#endif // SHAPE_H