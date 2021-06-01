/****************************************************************
*																*
* ��ͷ�ļ������˻�����    										*
* �������Ǳ�����Ŀ����࣬�������ĳ�ʼ���Լ���ȡ�û��������λ��	*
* ������λ�����жϵ��õĸ�����ť�Ĳ����������߻����Ĳ�������			*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4															*
*                                                               *
*****************************************************************/

#ifndef DRAWING_BOARD_H
#define DRAWING_BOARD_H

#include "point.h"
#include "color.h"
#include "colorButton.h"
#include "shapeButton.h"
#include "operationButton.h"
#include "canvas.h"

// �����࣬����ʵ�ֻ���
// �ֶΰ�����������Ҫ�ĸ��ְ�ť�Լ����水ť������
class DrawingBoard // controller class
{
public:
	DrawingBoard();
	void initialize();
	void chooseOperations();
	void exit(); // �˳�������delete��new����ͼ��

private:
	// ��ť��Ϊ����
	// ��һ��Ϊ��ɫ��ť������������ɫ
	// �ڶ���Ϊͼ�ΰ�ť������ѡ������ͼ��
	// ������Ϊ������ť��������ɶԻ���ĸ��ֲ�����
	// 	   Ŀǰ����������ȡ�����棬�˳�����������ԭ����
	// 
	// ����һ������
	// ��������������ѡ�㲢�������úõ�ͼ��
	ColorButton redButton;
	ColorButton orangeButton;
	ColorButton yellowButton;
	ColorButton greenButton;
	ColorButton cyanButton;
	ColorButton skyBlueButton;
	ColorButton blueButton;
	ColorButton violetButton;
	ColorButton blackButton;
	ColorButton pinkButton;
	ColorButton goldenButton;
	ColorButton lightYellowButton;
	ColorButton limeButton;
	ColorButton lightYellowGreenButton;
	ColorButton blueGreyButton;
	ColorButton lightVioletButton;
	ColorButton brownButton;

	LineButton lineButton;
	CircleButton circleButton;
	CircleButton fillCircleButton;
	RectangleButton rectangleButton;
	RectangleButton fillRectangleButton;

	ExitButton exitButton;
	ClearButton clearButton;
	CancelButton cancelButton;
	RestoreButton restoreButton;
	ReadButton readButton;
	WriteButton writeButton;

	Canvas canvas;

	static std::vector<ButtonBase*> buttons; // ��Ű�ť�����飬���ڷ���
};

#endif // DRAWING_BOARD_H