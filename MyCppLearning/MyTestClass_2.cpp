#include "pch.h"

static float bValue = 0.2f;
extern int ExA;
// c风格定义函数无法被重定义
extern "C" int foo(int x, int y);
extern const char *c;


MyTestClass_2::MyTestClass_2()
{
	a = 20;
	c = 1;
	B = 21;
}

void MyTestClass_2::Func_2()
{
	std::cout << "This is Func_2! The 2 b value = " << Getb() << "\n";
	Func_1();
	bValue++;            
	std::cout << bValue << std::endl;
	std::cout << "class_2 Static bValue Address: " << &bValue << endl;
}

float MyTestClass_2::GetB()
{
	return B * ExA + bValue;
}

void MyTestClass_2::Func_1()
{
	std::cout << "Call Test_2 Fun_V!!!!!!!!\n";
}

int MyTestClass_2::Getb()
{
	return c;
}

int foo(int x, int y)
{
	return x + 2 * y;
}


void Test3Func(int a, MyTestClass_2& T2Ref)
{
	std::cout << "This is Test 2 friend Fun.\n"
		<< "The value = " << a * (a + T2Ref.B) << std::endl;
}


const char* GetCharC()
{
	/**
	 * 使用static在函数中修饰变量时,将其作为静态全局函数,
	 * 函数调用结束也不会释放.
	 */
	static int a[4] = { 0,1,2,3 };
	//int a[4] = { 0,1,2,3 };

	for (int i = 0; i < 3; i++)
	{
		a[i]++;
	}
	std::cout << a[0] << std::endl;
	//getstaticarray();
	return c;
}

//不要内联全局函数
//inline const int T3InlineTest()
const int T3InlineTest()
{
	std::cout << "This is Test 3 Inline Func!!!!\n";
	return 23;
}