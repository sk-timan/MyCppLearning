#include "pch.h"
#include "MyTemplate.h"

const int* TempZTYPrt = NULL;
inline static int getint() { return 3; };

void TemplateFuncTest()
{
	int i = 39;
	int j = 20;
	cout << "&i = " << &i << endl;
	cout << "&j = " << &j << endl;
	TempZTYPrt = Max(i, j);
	cout << "Max(i, j): " << TempZTYPrt << endl;
	cout << "i,j = " << i << " " << j << endl;

	double f1 = 13.5;
	double f2 = 20.7;
	cout << "Max(f1, f2): " << Max(f1, f2) << endl;

	string s1 = "Hello";
	string s2 = "World";
	cout << "Max(s1, s2): " << Max(s1, s2) << endl;

	//cout << "Max(i,f1): " << Max(i, f1) << endl;

}

void TemplateClassTest()
{
	try
	{
		Stack<int>		intStack;	//int 类型栈
		Stack<string>	stringStack;//string 类型栈

		int a = 5;
		cout << "a Address: " << &a << endl;

		//操作 int 类型的栈
		intStack.push(++a);
		cout << intStack.top() << endl;

		//操作string类型的栈
		stringStack.push("hello");
		cout << stringStack.top() << endl;
		stringStack.pop();
		stringStack.pop();


	}
	catch (exception const& ex)
	{
		cerr << "Exception: " << ex.what() << endl;
		//return -1;
	}
}

