#ifndef DRAWING_BOARD_H
#define DRAWING_BOARD_H
// ��ͷ�ļ��а���������

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
private:
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
	static std::vector<ButtonBase*> buttons;

public:
	DrawingBoard();
	void initialize();
	void chooseOperations();
	void exit();
};

#endif // DRAWING_BOARD_H