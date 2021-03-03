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
	//explicit 关键词，修饰只有一个参数的构造函数，表示无法隐式自动转换(默认隐式)
	//CxString string2 = 10;  隐式转化为CxString string2(10);
	//CxString string6 = 'c'; 隐式转化为CxString string6('c');(等于'c'的ascii码)
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