#pragma once

#include <iostream>
//#include "MyTestClass_2.h"   //��������ѭ��Ƕ��

#define HCOUT_1 std::cout << "_1.h Load!!"<< endl;

void printExaAddress();

//��Ҫ��ͷ�ļ�����ȫ�ֱ������������ӻᱨ�ض���


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




