#ifndef OPERATION_BUTTON_H
#define OPERATION_BUTTON_H
// ��ͷ�ļ��а����˲�����ť�༰�����������ʵ����������ķǳ�Ա������
// ������ť�ࡢ�˳���ť�ࡢ������ť�ࡢ��ԭ��ť�ࡢ��ȡ��ť�ࡢд�밴ť��

#include "buttonBase.h"
#include "shape.h"

// ʹ��Ԥ����ָ���ж�C++�������汾�Ƿ���C++17���Ժ��������򱨴�����
#if _MSVC_LANG >= 201703L || __cplusplus >= 201703L // MSVC or clang and gcc
#include <filesystem> // C++17����
#else 
#error ������Ӧʹ��C++17���Ժ�汾�� //�����л��������汾
#endif // _MSVC_LANG >= 201703L || __cplusplus >= 201703L

// ������ť������ʵ�ָ��ֲ���
// �̳��˰�ť���࣬�и��ֲ���������
// �ֶ��а���buffer����Ϊ�������ݵĻ�����
// ���������������ȴ���buffer�У����û�б���ԭ�������buffer 
class OperationButton : public ButtonBase
{
public:
	static std::vector<Shape*> buffer;

	OperationButton(const Point& pt1_, const Point& pt2_);
	virtual void init() = 0;
	virtual void operation() = 0;
};

// ������ť
// �̳��˲�����ť��������
// �������������״���ݼ�shapes�б������״����
class ClearButton final : public OperationButton
{
public:
	ClearButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// �˳���ť
// �̳��˲�����ť��������
// �����˳�������� 
class ExitButton final : public OperationButton
{
public:
	ExitButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// ������ť
// �̳��˲�����ť��������
// ����ʵ����״�ĳ�����������shapes��buffer
class CancelButton final : public OperationButton
{
public:
	CancelButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// ��ԭ��ť
// �̳��˲�����ť��������
// ����ʵ����״�ĸ�ԭ��������shapes��buffer
class RestoreButton final : public OperationButton
{
public:
	RestoreButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// ��ȡ��ť
// �̳��˲�����ť��������
// ���ڶ�ȡ�������ļ��е�����
class ReadButton final : public OperationButton
{
public:
	ReadButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// д�밴ť
// �̳��˲�����ť��������
// ���ڰ���״����д���ļ�
class WriteButton final : public OperationButton
{
public:
	WriteButton(const Point& pt1_, const Point& pt2_);
	virtual void init();
	virtual void operation();
};

// �����ǳ�Ա����
void clearPainting(); // ��������
void clearBuffer(); // ������ջ������е���״

#endif // OPERATION_BUTTON_H