#include <iostream>
#include "pch.h"

using namespace std;

extern int ExA;
static double bValue = 0.3;
extern const char *c = "I'm Char c";
extern float foo(float x, float y);
/*采用c方法编译*/
//extern "C" double foo(double x, double y);

extern const char* GetCharC();
static int getint() { return 444; };
int MyTestClass_3::MyStaticValue = 111;
int MyTestClass_3::MyPrivateStaticValue = 100;
extern const int T3InlineTest();
//MyDllClass DllClassRef;

void Func_ThreadTest();

//int &a = 2;  //左值引用，绑定到右值，失败
int b = 2;
//const int &c = b;

int num1(5);
int num2(10);
int *pnum(&num1);//将num1的地址传递给pnum


int getdata(int &&num)
{
	cout << num << endl;
	num += 10;
	return num;
}





int main(void)
{
	//MyTestClass_1 Test;
	//MyTestClass_2 Test2;
	//MyTestClass_3 Test3;

	//cout << bValue << " " << ExA << endl;
	//Test.Func_1();
	//cout << getint() << endl;
	//Test2.Func_2();
	//cout << Test2.GetB()<< endl;
	//cout << foo(1,2) + var << endl;
	//cout << ExCharTest << endl;
	//cout << bValue << endl;

	//cout << GetCharC() << endl;
	//cout << GetCharC() << endl;

	/*
	MyTestClass_3::MyStaticValue = 112;
	MyTestClass_3::Func_3();
	cout << Test3.MyStaticValue++ << endl;
	MyTestClass_3::Func_3();
	cout << Test3.MyStaticValue << endl;
	*/

//	Test3Func(2, Test3);
//	cout << Test3.NormalInt << endl;
//	Test3Func(2, Test2);

	//cout << T3InlineTest() << endl;

	/*
	fibonacci_init(1, 1);
	do {
		cout << fibonacci_index() << ": "
			<< fibonacci_current() << endl;
	} while (fibonacci_next());

	cout << fibonacci_index() + 1 <<
		" Fibonacci sequence values fit in an " <<
		"unsigned 64-bit integer." << endl;
	cout << "MyDllPrivateInt = " << DllClassRef.GetMyDllPrivateInt() << endl;
	cout << "MyDllInt = " << DllClassRef.DllInt << endl;
	cout << "MyDllStaticInt = " << MyDllClass::DllStaticInt << endl;
	*/
	

	/*
	double a = 7.4;
	int b = 99;

	std::cout << "a + b = " <<
		StaticMathLibrary::Arithmetic::Add(a, b) << std::endl;
	std::cout << "a - b = " <<
		StaticMathLibrary::Arithmetic::Subtract(a, b) << std::endl;
	std::cout << "a * b = " <<
		StaticMathLibrary::Arithmetic::Multiply(a, b) << std::endl;
	std::cout << "a / b = " <<
		StaticMathLibrary::Arithmetic::Divide(a, b) << std::endl;
	*/

	/*
	MyEnumClass EClassReference;
	EClassReference = MyEnumClass::First;
	MyEnum Eref = First;
	//Number Enumber = third;
	cout << "MyEnum First = " << Eref << endl;
	//cout << "MyEnum Third = " << Enumber << endl;
	cout << "MyEnumClass First = " << ENUM_TO_STRING(EClassReference) << endl;
	cout << SwitchOnMyEnumClass(EClassReference) << endl;
	*/

	/*
	int a = 5;
	cout << getdata(a + 1) << endl;
	int * &rnum = pnum;//rnum是pnum的别名
	rnum = &num2;//rnumhe pnum指向同一片内存  改变了rnum就相当于改变了pnum
	//int * &rnum = &num1;//这是不允许的  无法从“int *”转换为“int *&”
	cout << *pnum << endl;
	*/

	//TemplateFuncTest();
	Func_ThreadTest();

	return 0;
}

float foo(float x, float y)
{
	return 2 * x + y;
}

double foo(double x, double y)
{
	return x * y;
}
