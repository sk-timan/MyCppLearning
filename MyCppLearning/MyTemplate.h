#pragma once

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
inline T const* Max(T const a, T const& b) //a Ϊ�����������ַ��ռ���ڴ�
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
*	ģ����
*
**/

template <class T>
class Stack
{
private:
	vector<T> elems;

public:
	void push(const T&);	//��ջ
	void pop();				//��ջ

	//�κβ����޸����ݳ�Ա�ĺ�����Ӧ������Ϊconst���ͣ�const�ؼ��ַ��ں������ŵĺ���
	T top() const;			//����ջ��Ԫ��
	bool empty() const { return elems.empty(); };	//���Ϊ���򷵻��档

};

template <class T>
void Stack<T>::push(const T& elem) //cosnt T& ֧����ֵ����(Ҳ����ʱ����),����T�Ĺ��캯��
{
	//׷�Ӵ���Ԫ�صĸ���
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
	//ɾ�����һ��Ԫ��
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
* ������ģ��,���ķ���T�������Ͷ���int�ͳ���������1��3��10
*/
template<int NumBytes>							
struct TSignedIntType{};
/**
* �����ػ�
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
	* �������
	*/
	template <int NumBytes>
	using TSignedIntType_T = typename TSignedIntType<NumBytes>::Type;

	template <typename T>
	using TUnderlyingIntegerType_T = TSignedIntType_T<sizeof(T)>;

	template <typename T>
	T LoadRelaxed(const volatile T* Element)
	{
		//*volatile �ؼ�����һ���������η�
		//*��������ؼ��������ı������������Է��ʸñ����Ĵ���Ͳ��ٽ����Ż����Ӷ������ṩ�������ַ���ȶ�����
		auto Result = *(volatile TUnderlyingIntegerType_T<T>*) Element;		//ǿ��ת��Ϊ�з���int
		//auto Result = *Element;
		cout << sizeof(T) << endl;
		cout << Result << endl;
		cout << &Result << endl;
		auto Result_T = (const T*)&Result;								//ǿ��ת����T
		cout << Result_T << endl;
		auto Result_XT = *(const T*)&Result;
		cout << Result_XT << endl;
		cout << &Result_XT << endl;

		return *(const T*)&Result;								//������Element��ֵ���˵�ַ

 	}

}

template <typename T>
struct alignas((Atomic_Private::TIsSupportedSize<sizeof(T)>::Value) ? alignof(Atomic_Private::TUnderlyingIntegerType_T<T>) : alignof(T)) TAtomicBase_Basic
{
protected:

	volatile T Element;
	/*
	**����㲻����������û�ֱ�ӹ���һ����Ķ��󣬶�ϣ���û�ֻ�ܹ������������࣬����Ϳ��Խ���Ĺ��캯��/������������Ϊprotected��
	* �����������Ĺ��캯��/������������Ϊpublic
	*/
	//TAtomicBase_Basic() = default;

	//�ؼ��֣�����ʱ���ܵó�����ֵ�ı��ʽȥ�Ż�
	constexpr TAtomicBase_Basic(T Value) : Element(Value) {};

public:

	inline T Load() const
	{
		return Atomic_Private::LoadRelaxed(&Element);
	}

	TAtomicBase_Basic() = default;

private:

	

};