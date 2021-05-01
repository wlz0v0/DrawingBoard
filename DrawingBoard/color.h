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

	Color();
	Color(int red_, int green_, int blue_);
	Color& operator=(const Color& right);
	~Color();
	void setGraphColor();
	friend std::ostream& operator<<(std::ostream& os, Color& color);
	friend std::istream& operator>>(std::istream& is, Color& color);
};

extern const std::array<Color, 17> colorset;

#endif // COLOR_H