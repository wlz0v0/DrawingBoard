#ifndef COLOR_H
#define COLOR_H
// ��ͷ�ļ��а�������ɫ��

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
	const static std::array<Color, 17> colorset; // Ԥ�����ɫ

	Color();
	Color(int red_, int green_, int blue_);
	Color& operator=(const Color& right);
	~Color();
	void setGraphColor(); // ��Color��ʵ�����û�ͼ����ɫ
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