#include <iostream>
#include <pch.h>

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