#include <iostream>

using namespace std;

//8.1 inline.cpp -- using an inline function

inline double square(double x) { return x * x; }

void ProgramList_8_1(void)
{
	double a, b;
	double c = 13.0;

	a = square(5.0);
	b = square(4.5 + 7.5);			//can pass expressions
	cout << "a = " << a << ", b = " << b << "\n";
	cout << "c = " << c;
	cout << ", c squared = " << square(c++) << "\n";
	cout << "Now c = " << c << "\n";

}


//8.2 firstref.cpp -- defining and using a reference

void ProgramList_8_2(void)
{
	int rats = 101;
	int& rodents = rats;			//rodents is a reference    引用必须同时初始化
	cout << "rats = " << rats;
	cout << ", rodents = " << rodents << endl;
	rodents++;
	cout << "rat = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "rats address = " << &rats;
	cout << ", rodents address = " << &rodents << endl;

	int bunnies = 50;
	rodents = bunnies;
	cout << "bunnies = " << bunnies;
	cout << ", rats = " << rats;
	cout << ", rodents = " << rodents << endl;

	cout << "bunnies address = " << &bunnies;
	cout << ", rodents address = " << &rodents << endl;

}


//8.4 swaps.cpp -- swapping with reference and with pointers

void ProgramList_8_4(void)
{
	void swapr(int& a, int& b);			//a, b are aliases for ints
	void swapp(int* p, int* q);			//p, q are address of ints
	void swapv(int a, int b);			//a, b are new variables
	
	int wallet1 = 300;
	int wallet2 = 350;
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	cout << "Using reference to swap contents:\n";
	swapr(wallet1, wallet2);
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	cout << "Using pointers to swap contents again:\n";
	swapp(&wallet1, &wallet2);
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

	cout << "Tring to use passing by value:\n";
	swapv(wallet1, wallet2);
	cout << "wallet1 = $" << wallet1;
	cout << " wallet2 = $" << wallet2 << endl;

}

void swapr(int& a, int& b)
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}

void swapp(int* p, int* q)
{
	int temp;

	temp = *p;
	*p = *q;
	*q = temp;
}

void swapv(int a, int b)             //变量 a b 分别复制了 wallet1 wallet2 的值
{
	int temp;

	temp = a;
	a = b;
	b = temp;
}


//8.5 cubes.cpp -- regular and reference arguments

void ProgramList_8_5(void)
{
	double cube(double a);
	double refcube(double& ra);


}





