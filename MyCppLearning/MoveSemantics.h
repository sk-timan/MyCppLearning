#pragma once

#include <iostream>

using namespace std;

// interface
class Useless
{
private:
	int n;		//number of element
	char* pc;	//pointer to data
	static int ct;	//number of object
	void ShowObject() const;

public:
	Useless();
	//explicit �ؼ��ʣ�����ֻ��һ�������Ĺ��캯������ʾ�޷���ʽ�Զ�ת��(Ĭ����ʽ)
	//CxString string2 = 10;  ��ʽת��ΪCxString string2(10);
	//CxString string6 = 'c'; ��ʽת��ΪCxString string6('c');(����'c'��ascii��)
	explicit Useless(int k);
	Useless(int k, char ch);
	Useless(const Useless& f);	//regular copy constructor
	Useless(Useless&& f);		//move constructor
	~Useless();
	Useless operator+(const Useless& f) const;
	//need operator=() in copy and move versions
	void ShowData() const;

};

void MoveSemanticsTest();