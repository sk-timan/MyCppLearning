#include "pch.h"

extern char ExCharTest[30] = "charTest";
int ExA = 1;
extern const char *c;
extern const char* GetCharC();
const int var = 100;
extern char ExCharTest[30];
static int a[4] = { 3,4,5,6 };

/**
 * ��̬ȫ�ֱ���������Ϊ������뵥Ԫ,�������뵥Ԫ�����⿪���ڴ汣����,
 * �Ҷ������޸Ĳ���Ӱ�챾���ڶ���ʱ��ֵ.
 */
static float bValue = 0.1f;
/**
*�� C++ �У���Ҫһ�����ݶ���Ϊ���������ĳ���������,
*ͬʱ�������ƻ���ķ�װ��,��Ҫ��˳�Ա����������ڲ���
*���ⲻ�ɼ�ʱ���ɽ��䶨��Ϊ��̬���ݡ�(static ʹ��Ŀ��֮һ)
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

//����ע��  ��CTRL+K,��CTRL+C
//ȡ��ע��  ��CTRL+K,��CTRL+U

//const char* GetCharC()
//{
//	/** 
//	 * ʹ��static�ں��������α���ʱ,������Ϊ��̬ȫ�ֺ���,
//	 * �������ý���Ҳ�����ͷ�.(staticʹ��Ŀ��֮һ)
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
