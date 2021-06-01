/****************************************************************
*																*
* ��ͷ�ļ���������ɫ��    										*
* ��ɫ����ege��color_t��ͬ��ʹ����R,G,B���������ֱ�洢RGB����		*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4															*
*                                                               *
*****************************************************************/

#ifndef COLOR_H
#define COLOR_H

#include <iostream>
#include <array>

// ��ɫ��
// �ֶ��а�����ɫ��RGB����
// �����а���������ɫ���û�ͼ��ɫ�������ɫ
// ��������������������
// ������һ��ȫ����ɫ�����������������Ԥ���趨�õ���ɫ
class Color
{
public:
	int red;
	int green;
	int blue;
	// Ԥ�����ɫ����Ҫ������ɫ��ť�ĳ�ʼ��
	const static std::array<Color, 17> colorset; 

	Color();
	Color(int red_, int green_, int blue_);
	Color& operator=(const Color& right);
	~Color();
	// ��Color��ʵ�����û�ͼ����ɫ���������ɫ
	void setGraphColor(); 
	// ����������������ļ���д
	friend std::ostream& operator<<(std::ostream& os, Color& color);
	friend std::istream& operator>>(std::istream& is, Color& color);
	bool operator==(const Color& rhs) const;
	bool operator!=(const Color& rhs) const;
	int& operator[](int index);
	Color& operator++();
	Color operator++(int);
	Color& operator--();
	Color operator--(int);
};

#endif // COLOR_H