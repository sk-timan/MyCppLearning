#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
inline T const* Max(T const a, T const& b) //a 为副本将另起地址，占用内存
{
	cout << "&a = " << &a << endl;
	cout << "&b = " << &b << endl;
	return a < b ? &b : &a; 
}

template <typename T1, typename T2>
inline const T2& Max(const T1& a, const T2& b) //const int = int const
{
	cout << "address: " << &(a < b ? b : a) << endl;
	return a < b ? b : a;
}

void TemplateFuncTest();


/**
*	模板类
*
**/

template <class T>
class Stack
{
private:
	vector<T> elems;

public:
	void push(const T&);	//入栈
	void pop();				//出栈

	//任何不会修改数据成员的函数都应该声明为const类型，const关键字放在函数括号的后面
	T top() const;			//返回栈顶元素
	bool empty() const { return elems.empty(); };	//如果为空则返回真。

};

template <class T>
void Stack<T>::push(const T& elem) //cosnt T& 支持右值构造(也是临时变量),调用T的构造函数
{
	//追加传入元素的副本
	cout << "const T& Address: " << &elem << endl;
	elems.push_back(elem);
}

template <class T>
void Stack<T>::pop()
{
	if (elems.empty())
	{
		throw out_of_range("Stack<>::pop(): empty stack");
	}
	//删除最后一个元素
	elems.pop_back();

}

template <class T>
T Stack<T>::top() const
{
	if (elems.empty())
	{
		throw out_of_range("Stack<>::top(): empty stack");
	}
	return elems.back();
}

void TemplateClassTest();






/**
* 非类型模板,它的泛型T不是类型而是int型常量，例如1、3、10
*/
template<int NumBytes>							
struct TSignedIntType{};
/**
* 函数特化
*/
template <> struct TSignedIntType<1> { using Type = FPlatformTypes::int8; };
template <> struct TSignedIntType<2> { using Type = FPlatformTypes::int16; };
template <> struct TSignedIntType<4> { using Type = FPlatformTypes::int32; };
template <> struct TSignedIntType<8> { using Type = FPlatformTypes::int64; };


template <typename T>
struct TAtomicBase_Basic;

namespace Atomic_Private
{
	template <int Size>
	struct TIsSupportedSize
	{
		enum { Value = (Size == 1) || (Size == 2) || (Size == 4) || (Size == 8) };
	};

	/**
	* 构造别名
	*/
	template <int NumBytes>
	using TSignedIntType_T = typename TSignedIntType<NumBytes>::Type;

	template <typename T>
	using TUnderlyingIntegerType_T = TSignedIntType_T<sizeof(T)>;

	template <typename T>
	T LoadRelaxed(const volatile T* Element)
	{
		//*volatile 关键字是一种类型修饰符
		//*遇到这个关键字声明的变量，编译器对访问该变量的代码就不再进行优化，从而可以提供对特殊地址的稳定访问
		auto Result = *(volatile TUnderlyingIntegerType_T<T>*) Element;		//强制转换为有符号int
		//auto Result = *Element;
		cout << sizeof(T) << endl;
		cout << Result << endl;
		cout << &Result << endl;
		auto Result_T = (const T*)&Result;								//强制转换回T
		cout << Result_T << endl;
		auto Result_XT = *(const T*)&Result;
		cout << Result_XT << endl;
		cout << &Result_XT << endl;

		return *(const T*)&Result;								//复制了Element的值换了地址

 	}

}

template <typename T>
struct alignas((Atomic_Private::TIsSupportedSize<sizeof(T)>::Value) ? alignof(Atomic_Private::TUnderlyingIntegerType_T<T>) : alignof(T)) TAtomicBase_Basic
{
protected:

	volatile T Element;
	/*
	**如果你不想让外面的用户直接构造一个类的对象，而希望用户只能构造这个类的子类，那你就可以将类的构造函数/析构函数声明为protected，
	* 而将类的子类的构造函数/析构函数声明为public
	*/
	//TAtomicBase_Basic() = default;

	//关键字：编译时就能得出常量值的表达式去优化
	constexpr TAtomicBase_Basic(T Value) : Element(Value) {};

public:

	inline T Load() const
	{
		return Atomic_Private::LoadRelaxed(&Element);
	}

	TAtomicBase_Basic() = default;

private:

	

};