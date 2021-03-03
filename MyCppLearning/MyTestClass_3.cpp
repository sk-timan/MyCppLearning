#include "pch.h"

extern const int T3InlineTest();

MyTestClass_3 T3Ref;

MyTestClass_3::MyTestClass_3()
{
	NormalInt = 33;
	
}

void MyTestClass_3::Func_3()    //这里无法inline
{
	std::cout << "This is Func_3! It's static function. \n";
	std::cout << "My static value = " << MyStaticValue << std::endl;
	//Test3Func();   //static 成员函数无法使用非静态类成员函数

	T3StaticFun();

}

void MyTestClass_3::Test3Func()
{
	std::cout << "This is Test3 Member Func!!\n";
	MyTestClass_3::MyStaticValue = 12;
}


inline void MyTestClass_3::T3StaticFun()
{
	std::cout << "This is Test3 Static Member Function!!\n";
}


const char* SwitchOnMyEnumClass(MyEnumClass EnumClassRef)
{
	const char* a = nullptr;

	switch (EnumClassRef) {
	case MyEnumClass::Always:
		a = ENUM_TO_STRING(MyEnumClass::Always);
		break;
	case MyEnumClass::First:
		a = ENUM_TO_STRING(MyEnumClass::First);
		break;
	case MyEnumClass::Never:
		a = ENUM_TO_STRING(MyEnumClass::Never);
		break;
	case MyEnumClass::OnlyMoveable:
		a = ENUM_TO_STRING(MyEnumClass::OnlyMoveable);
		break;
	case MyEnumClass::Second:
		a = ENUM_TO_STRING(MyEnumClass::Second);
		break;
	case MyEnumClass::Third:
		a = ENUM_TO_STRING(MyEnumClass::Third);
		break;
	case MyEnumClass::UseConfig:
		a = ENUM_TO_STRING(MyEnumClass::UseConfig);
		break;
	}

	return a;
}

void Test3Func(int a, MyTestClass_3& T3Ref)
{
	T3Ref.NormalInt++;
	std::cout << "This is Test 3 friend Fun.\n"
		<< "The value = " << a * (a + MyTestClass_3::MyPrivateStaticValue) << std::endl;
	std::cout << T3Ref.NormalInt << std::endl;
}

void Class3Test()
{
	MyTestClass_3 T3;
	cout << "ClassT3 Address: " << &T3.MyStaticValue << endl;
}
int MyTestClass_3::MyStaticValue = 112;