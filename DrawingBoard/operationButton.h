/****************************************************************
*																*
* 本头文件包含了操作按钮基类，以及操作按钮的子类们    				*
* 操作按钮子类有清屏、退出、保存、读取、撤销、复原					*
* Github https://github.com/wlz0v0/DrawingBoard cpp branch      *
* lab 4															*
*                                                               *
*****************************************************************/

#ifndef OPERATION_BUTTON_H
#define OPERATION_BUTTON_H

#include "buttonBase.h"
#include "shape.h"
#include <regex>

// 使用预处理指令判断C++编译器版本是否在C++17及以后，若不是则报错并提醒
#if _MSVC_LANG >= 201703L || __cplusplus >= 201703L // MSVC or clang and gcc
#include <filesystem> // C++17特性
#else 
#error 编译器应使用C++17及以后版本！
#endif // _MSVC_LANG >= 201703L || __cplusplus >= 201703L

// 操作按钮抽象类，用于实现各种操作
// 继承了按钮基类，有各种操作的子类
// 字段中包含buffer，作为撤销内容的缓冲区
// 被撤销的内容首先存入buffer中，如果没有被复原，则清空buffer 
class OperationButton : public ButtonBase
{
public:
	// 缓冲数组，用于存储被撤销掉的图形
	// 当画图时，清空此数组
	static std::vector<Shape*> buffer; 

	OperationButton(const Point& pt1_, const Point& pt2_);
	virtual void init() = 0;
	virtual void operation() = 0;
};

// 清屏按钮
// 继承了操作按钮，无子类
// 用于清除所画形状内容及shapes中保存的形状数据
class ClearButton final : public OperationButton
{
public:
	ClearButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// 退出按钮
// 继承了操作按钮，无子类
// 用于退出画板程序 
class ExitButton final : public OperationButton
{
public:
	ExitButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// 撤销按钮
// 继承了操作按钮，无子类
// 用于实现形状的撤销，利用了shapes和buffer
class CancelButton final : public OperationButton
{
public:
	CancelButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// 复原按钮
// 继承了操作按钮，无子类
// 用于实现形状的复原，利用了shapes和buffer
class RestoreButton final : public OperationButton
{
public:
	RestoreButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// 读取按钮
// 继承了操作按钮，无子类
// 用于读取保存在文件中的数据
class ReadButton final : public OperationButton
{
public:
	ReadButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();

private:
	// 从文件中读取数据，不需要被类外调用
	void readShape(std::ifstream& ifs, Shape& shape, std::smatch& s, std::string& str);
};

// 写入按钮
// 继承了操作按钮，无子类
// 用于把形状数据写入文件
class WriteButton final : public OperationButton
{
public:
	WriteButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// 两个非成员函数
void clearPainting(); // 用于清屏
void clearBuffer(); // 用于清空缓冲区中的图形

#endif // OPERATION_BUTTON_H