#pragma once

#include <iostream>
#include "MyTestClass_2.h"

class MyTestClass_3;

enum MyEnum {First, Second, Third};
//enum Number{One, two, Third};		//��ͳö����������ȱ�ݣ�����ͬ���ض���

enum class MyEnumClass : unsigned char
{
	UseConfig,
	Always,
	OnlyMoveable,
	Never,
	First, 
	Second, 
	Third
};

const char* SwitchOnMyEnumClass(MyEnumClass EnumClassRef);

class MyTestClass_3
{
public:
	MyTestClass_3();

public:
	//��ľ�̬��Ա���������ں�����ֲ��������г�ʼ��
	//�Ǿ�̬��Ա(��������)������Ҫʵ������̬��Ա����Ҫ
	static int MyStaticValue; 
	//void Func_3();
	static void Func_3(); //��̬��Ա����ֻ�ܲ�����̬��Ա������������this
	
	static void T3StaticFun();
	void Test3Func();

	//��Ԫ�������������ԭʼ��ʵ��
	//�������������ڶ��壨�����������ģ���Ԫ����
	friend void Test3Func(int a, MyTestClass_3& T3Ref);
	int NormalInt;

private:
	static int MyPrivateStaticValue;
};

