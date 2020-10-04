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
	bool empty() const { return elems.empty() };

};

template <class T>
void Stack<T>::push(const T& elem)
{
	//追加传入元素副本
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