#include "pch.h"

extern char ExCharTest[30] = "charTest";
int ExA = 1;
extern const char *c;
extern const char* GetCharC();
const int var = 100;
extern char ExCharTest[30];
static int a[4] = { 3,4,5,6 };

/**
 * 静态全局变量作用域为本身编译单元,其他编译单元会另外开个内存保存它,
 * 且对它的修改并不影响本身在定义时的值.
 */
static float bValue = 0.1f;
/**
*在 C++ 中，需要一个数据对象为整个类而非某个对象服务,
*同时又力求不破坏类的封装性,即要求此成员隐藏在类的内部，
*对外不可见时，可将其定义为静态数据。(static 使用目的之一)
*/
static int getint() { return a[0]; };


static int getstaticarray()
{
	static int a[5] = { 7,8,9,10 };
	for (int i = 0; i < 4; i++)
	{
		a[i]++;
	}
	std::cout << a[0] << std::endl;
	return 0;
}

MyTestClass_1::MyTestClass_1()
{
	a = 10;
	b = 3;
	c = b;
}

void MyTestClass_1::Func_1()
{
	std::cout << "This is Func_1! \n";
	std::cout << GetCharC() << std::endl;
	std::cout << getint() << std::endl;
}

void MyTestClass_1::Vtest()
{
	//do nothing
}

int MyTestClass_1::Getb()
{
	return MyTestClass_1::b;
}

void MyTestClass_1::Func_V()
{
	std::cout << "Call Test_1 Fun_V!!!!!!!!\n";
}

//快速注释  先CTRL+K,后CTRL+C
//取消注释  先CTRL+K,后CTRL+U

//const char* GetCharC()
//{
//	/** 
//	 * 使用static在函数中修饰变量时,将其作为静态全局函数,
//	 * 函数调用结束也不会释放.(static使用目的之一)
//	 */
//	static int a[4] = { 0,1,2,3 };
//	//int a[4] = { 0,1,2,3 };
//
//	for (int i = 0; i < 3; i++)
//	{
//		a[i]++;
//	}
//	std::cout << a[0] << std::endl;
//	getstaticarray();
//	return c;
//}

void printExaAddress()
{
	cout << &ExA << endl;
}
