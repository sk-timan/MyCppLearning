#include <iostream>
#include <string>
#include <array>
#include "pch.h"

using namespace std;

//7.1 calling.cpp -- defining, prototyping, and calling a function

void ProgramList_7_1(void)
{
	void simple();		//function prototype

	cout << "main() will call the simple() function:\n";
	simple();			//function call
	cout << "main() is finished with the simple() function.\n";

}

//function definition

void simple()
{
	cout << "I'm but a simple function.\n";
}


//7.3 twoarg.cpp -- a function with 2 arguments

void ProgramList_7_3(void)
{
	void n_chars(char, int);
	int time;
	char ch;

	cout << "Enter a character: ";
	cin >> ch;
	while (ch != 'q')
	{
		cout << "Enter an integer: ";
		cin >> time;
		n_chars(ch, time);		//function with two arguments
		cout << "\nEnter another character or press the"
			" q-key to quit: ";
		cin >> ch;
	}

	cout << "The value of times is " << time << ".\n";
	cout << "Bye\n";

}

void n_chars(char c, int n)		//displays c n time
{
	while (n-- > 0)                //until n reaches 0.
		cout << c;
}


//7.4 lotto.cpp -- probability of winning

//Note: some implementations require double instead of long double
void ProgramList_7_4(void)
{
	long double probability(unsigned numbers, unsigned picks);
	double total, choices;
	cout << "Enter the total number of choices on the game card and\n"
		"the number of picks allowed:\n";
	while (cin >> total >> choices && choices <= total)
	{
		cout << "You have one chance in ";
		cout << probability(total, choices);		//compute the odds
		cout << " of winning.\n";
		cout << "Next two numbers (q to quit): ";
	}
	cout << "bye\n";

}

long double probability(unsigned numbers, unsigned picks)
{
	long double result = 1.0;
	long double n;
	unsigned p;

	for (n = numbers, p = picks; p > 0; p--, n--)
	{
		result = result * n / p;
	}

	return result;
}


//7.5 arrfun1.cpp -- functions with an array argument

void ProgramList_7_5(void)
{
	const int ArSize = 8;
	int sum_arr(int arr[], int n);
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };

	int sum = sum_arr(cookies, ArSize);
	cout << "Total cookies eaten: " << sum << "\n";
	
}

int sum_arr(int arr[], int n)
{
	int total = 0;
	cout << arr << " = arr, ";
	cout << sizeof arr << " = size of arr\n";
	for (int i = 0; i < n; i++)
		total = total + arr[i];

	return total;
}


//7.6 arrfun2.cpp -- funtions with an array argument

void ProgramList_7_6(void)
{
	const int ArSize = 8;
	int sum_arr(int arr[], int n);
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	cout << cookies << " = array address,";
	cout << sizeof cookies << " = size of cookies\n";
	int sum = sum_arr(cookies, ArSize);
	cout << "Total cookies eaten: " << sum << endl;
	sum = sum_arr(cookies, 3);
	cout << "First three cookies eaters ate " << sum << " cookies.\n";
	sum = sum_arr(cookies + 4, 4);
	cout << "Last four eater ate " << sum << " cookies.\n";

}


//7.7 arrfun3.cpp -- array functions and const

void ProgramList_7_7(void)
{
	const int Max = 5;
	int fill_array(double ar[], int limit);
	void show_array(const double ar[], int n);			//don't change data
	void revalue(double r, double ar[], int n);
	
	double properties[Max];
	int size = fill_array(properties, Max);
	show_array(properties, size);
	if (size > 0)
	{
		cout << "Enter revaluation factor: ";
		double factor;
		while (!(cin >> factor))		//bad input
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; Please enter a number: ";
		}
		revalue(factor, properties, size);
		show_array(properties, size);
	}
	cout << "Done.\n";
	cin.get();
	cin.get();

}

int fill_array(double ar[], int limit)
{
	double temp;
	int i;
	for (i = 0; i < limit; i++)
	{
		cout << "Enter value #" << (i + 1) << ": ";
		cin >> temp;
		if (!cin)
		{
			cin.clear();
			while (cin.get() != '\n')
				continue;
			cout << "Bad input; input process terminated.\n";
			break;
		}

		else if (temp < 0)		//signal to terminate
			break;
		
		ar[i] = temp;
	}

	return i;
}


void show_array(const double ar[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Property #" << (i + 1) << ": $";
		cout << ar[i] << endl;
	}
}

void revalue(double r, double ar[], int n)
{
	for (int i = 0; i < n; i++)
		ar[i] *= r;
}


//7.8 arrfun4.cpp -- functions with an array range

void ProgramList_7_8(void)
{
	const int ArSize = 8;
	int sum_arr(const int* begin, const int* end);

	int cookies[ArSize] = { 1, 2, 4, 8, 16, 32, 64, 128 };
	int sum = sum_arr(cookies, cookies + ArSize);
	cout << "Total cookies eaten: " << sum << endl;
	sum = sum_arr(cookies, cookies + 3);
	cout << "First three eaters ate " << sum << " cookies.\n";
	sum = sum_arr(cookies + 4, cookies + 8);
	cout << "Last four eaters ate " << sum << " cookies.\n";

}

int sum_arr(const int* begin, const int* end)
{
	const int* pt;
	int total = 0;

	for (pt = begin; pt != end; pt++)
	{
		total = total + *pt;
	}

	return total;
}


//7.9 strgfun.cpp -- functions with a string argument

void ProgramList_7_9(void)
{
	unsigned int c_in_str(const char* str, char ch);
	char mmm[15] = "minimum";		//string in an array
	char chw[] = "ululate";
	char* wail = &chw[0];		//wail points to string
	unsigned int ms = c_in_str(mmm, 'm');
	unsigned int us = c_in_str(wail, 'u');
	cout << ms << " m characters in " << mmm << endl;
	cout << us << " u characters in " << wail << endl;

}

unsigned int c_in_str(const char* str, char ch)
{
	unsigned int count = 0;
	while (*str)				//quite when *str is '\0'
	{
		if (*str == ch)
			count++;
		str++;					//move pointer to next char
	}

	return count;
}


//7.13 strctptr.cpp -- functions with pointers to structure arguments

struct polar
{
	double distance;
	double angle;
};

struct rect
{
	double x;
	double y;
};

void ProgramList_7_13(void)
{
	void rect_to_polar(const rect * pxy, polar * pda);
	void show_polar(const polar * pda);

	rect rplace;
	polar pplace;
	cout << "Enter the x and y values: ";
	while (cin >> rplace.x >> rplace.y)
	{
		rect_to_polar(&rplace, &pplace);
		show_polar(&pplace);
		cout << "Next two numbers (q to quit): ";
	}
	cout << "Done.\n";

}

void show_polar(const polar* pda)
{
	const double Rad_to_deg = 57.29577951;

	cout << "distance = " << pda->distance;
	cout << ", angle = " << pda->angle * Rad_to_deg;
	cout << " degrees\n";
}

void rect_to_polar(const rect* pxy, polar* pda)
{
	pda->distance =
		sqrt(pxy->x * pxy->x + pxy->y * pxy->y);
	pda->angle = atan2(pxy->y, pxy->x);
}


//7.14 topfive.cpp -- handling an array of string objects

void ProgramList_7_14(void)
{
	const int SIZE = 5;
	void display(const string sa[], int n);
	string list[SIZE];
	cout << "Enter your " << SIZE << " favorite astronomical sights:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << ": ";
		getline(cin, list[i]);
	}

	cout << "Your list:\n";
	display(list, SIZE);

}

void display(const string sa[], int n)
{
	for (int i = 0; i < n; i++)
		cout << i + 1 << ": " << sa[i] << endl;
}

//7.15 arrobj.cpp -- functions with array objects

const int Seasons = 4;
const array<string, Seasons> Snames = { "Spring", "Summer", "Fall", "Winter" };

void ProgramList_7_15(void)
{
	void fill(array<double, Seasons> * pa);
	void show(array<double, Seasons> da);

	array <double, Seasons> expenses;
	fill(&expenses);           //使用指针直接处理原始对象，避免了修改值时还需复制的繁琐
	show(expenses);

}

void fill(array<double, Seasons>* pa)
{
	for (int i = 0; i < Seasons; i++)
	{
		cout << "Enter " << Snames[i] << " expenses: ";
		cin >> (*pa)[i];

	}
}

void show(array<double, Seasons> da)
{
	double total = 0.0;
	cout << "\nEXPENSES\n";
	for (int i = 0; i < Seasons; i++)
	{
		cout << Snames[i] << ": $" << da[i] << endl;
		total += da[i];
	}
	cout << "Total Expenses: $" << total << endl;
}


//7.18 fun_ptr.cpp -- pointers to functions

void ProgramList_7_18(void)
{
	double betsy(int);
	double pam(int);

	void estimate(int lines, double (*pf)(int));

	int code;
	cout << "How many lines of code do you need?";
	cin >> code;
	cout << "Here's Betsy's estimate:\n";
	estimate(code, betsy);
	cout << "Here's Pam's estimate:\n";
	estimate(code, pam);

}

double betsy(int lns)
{
	return 0.05 * lns;
}

double pam(int lns)
{
	return 0.03 * lns + 0.0004 * lns * lns;
}

void estimate(int lines, double (*pf)(int))
{
	cout << lines << " lines will take ";
	cout << (*pf)(lines) << " hour(s)\n";   
}


//7.19 arfupt.cpp -- an array of function pointers

const double* f1(const double ar[], int n);
const double* f2(const double[], int);
const double* f3(const double*, int);

void ProgramList_7_19(void)
{
	double av[3] = { 1112.3, 1542.6, 2227.9 };
	const double* (*p1)(const double*, int) = f1;
	auto p2 = f2;                                  //函数名f2代表该函数的地址，f2()表示该函数的值

	cout << "Using pointer to functions:\n";
	cout << " Adress Value\n";
	cout << (*p1)(av, 3) << " : " << *(*p1)(av, 3) << endl;
	cout << p2(av, 3) << " : " << *p2(av, 3) << endl;

	const double* (*(pa[3]))(const double*, int) = { f1,f2,f3 };	//pa是一个包含三个指针的数组，每个指针都指向这样的函数，
																//即将const double*, int作为参数，const double* 作为返回值
	auto pb = pa;

	cout << "\nUsing an array of pointers to functions:\n";
	cout << " Adress Value\n";
	for (int i = 0; i < 3; i++)
		cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << endl;
	cout << "\nUsing a pointer toa pointer to a function:\n";
	cout << " Adress Value\n";
	for (int i = 0; i < 3; i++)
		cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << endl;

	cout << "\nUsing pointer to an array of pointers:\n";
	cout << " Adress Value\n";

	auto pc = &pa;
	cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << endl;
	const double* (*(*pd)[3])(const double*, int) = &pa;
	const double* pdb = (*pd)[1](av, 3);
	cout << pdb << ": " << *pdb << endl;

	cout << (*(*pd)[2])(av, 3) << "; " << *(*(*pd)[2])(av, 3) << endl;

}


const double* f1(const double* ar, int n)
{
	return ar;
}

const double* f2(const double ar[], int n)
{
	return ar + 1;
}

const double* f3(const double ar[], int n)
{
	return ar + 2;
}




