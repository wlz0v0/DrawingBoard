#ifndef OPERATION_BUTTON_H
#define OPERATION_BUTTON_H
// 本头文件中包含了操作按钮类及其子类和用于实现子类操作的非成员函数：
// 清屏按钮类、退出按钮类、撤销按钮类、复原按钮类、读取按钮类、写入按钮类

#include "buttonBase.h"
#include "shape.h"

// 使用预处理指令判断C++编译器版本是否在C++17及以后，若不是则报错并提醒
#if _MSVC_LANG >= 201703L || __cplusplus >= 201703L // MSVC or clang and gcc
#include <filesystem> // C++17特性
#else 
#error 编译器应使用C++17及以后版本！ //提醒切换编译器版本
#endif // _MSVC_LANG >= 201703L || __cplusplus >= 201703L

// 操作按钮，用于实现各种操作
// 继承了按钮基类，有各种操作的子类
// 字段中包含buffer，作为撤销内容的缓冲区
// 被撤销的内容首先存入buffer中，如果没有被复原，则清空buffer 
class OperationButton : public ButtonBase
{
public:
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
void clearBuffer(); // 用于清空缓冲区中的形状

#endif // OPERATION_BUTTON_H