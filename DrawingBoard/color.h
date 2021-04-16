#ifndef COLOR_H
#define COLOR_H
// ��ͷ�ļ��а�������ɫ��

#include <iostream>

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
	void setGraphColor();
	friend std::ostream& operator<<(std::ostream& os, Color& color);
	friend std::istream& operator>>(std::istream& is, Color& color);
};

extern const Color colorset[17];

#endif // COLOR_H