/****************************************************************
*																*
* 本头文件包含了画板类    										*
* 画板类是本画板的控制类，负责界面的初始化以及获取用户鼠标点击的位置	*
* 并根据位置来判断调用的各个按钮的操作函数或者画布的操作函数			*
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

// 画板类，用于实现画板
// 字段包含画板中需要的各种按钮以及储存按钮的向量
class DrawingBoard // controller class
{
public:
	DrawingBoard();
	void initialize();
	void chooseOperations();
	void exit(); // 退出函数，delete掉new出的图形

private:
	// 按钮分为三类
	// 第一类为颜色按钮，可以设置颜色
	// 第二类为图形按钮，可以选择所画图形
	// 第三类为操作按钮，可以完成对画板的各种操作：
	// 	   目前有清屏，读取，保存，退出，撤销，复原操作
	// 
	// 还有一个画布
	// 画布用来在上面选点并画出设置好的图形
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

	static std::vector<ButtonBase*> buttons; // 存放按钮的数组，便于访问
};

#endif // DRAWING_BOARD_H