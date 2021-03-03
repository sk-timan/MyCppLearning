#pragma once

#include <iostream>
//#include "MyTestClass_2.h"   //不允许类循环嵌套

#define HCOUT_1 std::cout << "_1.h Load!!"<< endl;

void printExaAddress();

//不要在头文件定义全局变量，否则链接会报重定义


class MyTestClass_1
{
public:

	MyTestClass_1();

public:

	int a;
	void Func_1();

protected:

	int Getb();
	void Func_V();
	int c;

private:

	int b;
	virtual void Vtest();

};




