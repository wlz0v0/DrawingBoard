/****************************************************************
*																*
* ��ͷ�ļ������˵���					    						*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4															*
*                                                               *
*****************************************************************/

#ifndef POINT_H
#define POINT_H

#include <iostream>

// ����
// �ֶΰ���һ�����x�����y����
// ���������������������ͱȽ������
class Point
{
public:
	Point();
	Point(int x_, int y_);
	Point(const Point& rhs);
	friend std::ostream& operator<<(std::ostream& os, Point& pt);
	friend std::istream& operator>>(std::istream& is, Point& pt);
	bool operator>(const Point& pt_) const;
	Point operator+(const Point& rhs);
	bool operator==(const Point& rhs) const;
	bool operator!=(const Point& rhs) const;
	int& operator[](size_t index);

public:
	int x;
	int y;
};

#endif //POINT_H