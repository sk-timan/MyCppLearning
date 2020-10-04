#pragma once

#include <iostream>
#include "MyTestClass_1.h"

class MyTestClass_2 : public MyTestClass_1
{	
public:

	MyTestClass_2();

public:

	int a;
	void Func_2();
	void Func_1();
	float GetB();
	//友元函数具有内部链接(与MyTestClass_3重名无冲突)
	friend void Test3Func(int a, MyTestClass_2& T2Ref);

protected:

	int c;
	int Getb();

private:

	int B;
};

