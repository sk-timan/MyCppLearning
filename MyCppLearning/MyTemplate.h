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
	bool empty() const { return elems.empty() };

};

template <class T>
void Stack<T>::push(const T& elem)
{
	//׷�Ӵ���Ԫ�ظ���
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