#pragma once

#include <iostream>
#include "MyTestClass_2.h"

class MyTestClass_3;

enum MyEnum {First, Second, Third};
//enum Number{One, two, Third};		//传统枚举无作用域缺陷，导致同名重定义

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
	//类的静态成员变量不能在函数或局部作用域中初始化
	//非静态成员(变量或函数)访问需要实例，静态成员则不需要
	static int MyStaticValue; 
	//void Func_3();
	static void Func_3(); //静态成员函数只能操作静态成员变量，不接受this
	
	static void T3StaticFun();
	void Test3Func();

	//友元函数声明必须带原始类实例
	//可以在类声明内定义（给定函数正文）友元函数
	friend void Test3Func(int a, MyTestClass_3& T3Ref);
	int NormalInt;

private:
	static int MyPrivateStaticValue;
};

