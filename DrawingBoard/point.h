#ifndef POINT_H
#define POINT_H
// ��ͷ�ļ��а�������

#include <iostream>

// ����
// �ֶΰ���һ�����x�����y����
// ���������������������ͱȽ������
class Point
{
public:
	int x;
	int y;

	Point();
	Point(int x_, int y_);
	friend std::ostream& operator<<(std::ostream& os, Point& pt);
	friend std::istream& operator>>(std::istream& is, Point& pt);
	bool operator>(const Point& pt_);
};

#endif //POINT_H