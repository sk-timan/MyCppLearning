#include <iostream>
#include <cmath>            //c��ͷ�ļ��� ͬ<math.h>
#include "pch.h"

using namespace std;

//2.1 myfirst.cpp -- displays a message

void ProgramList_2_1(void)
{
	cout << "Come up and C++ me some time." << endl;
	cout << "You won't regret it!" << endl;
}


//2.3 getinfo.cpp -- input and output

void ProgramList_2_3(void)
{
	int carrots;

	cout << "How many carrots do you have?" << endl;
	cin >> carrots;                                     //���룻��Ϣ��cin����carrots;
	cout << "Here are two more.";

	carrots = carrots + 2;

	cout << "Now you have " << carrots << " carrots." << endl;
}


//2.4 sqrt.cpp -- using the sqrt() function

void ProgramList_2_4(void)
{
	double area;

	cout << "Enter the floor area,in square feet,of your home: ";
	cin >> area;

	double side;

	side = sqrt(area);

	cout << "That's the equivalent of a square " << side
		<< " feet to the side." << endl;
	cout << "How fascinating!" << endl;
}


//2.5 ourfunc.cpp -- defining your own function

void ProgramList_2_5(void)
{
	//����ԭ�ͣ����ڿ⺯������ʹ��ǰ�����ṩ����ԭ�ͣ�ͨ������main()����ǰ��
	void simon(int);                 
	
	simon(3);

	cout << "Pick an integer: ";

	int count;

	cin >> count;
	simon(count);

	cout << "Done!" << endl;
}

void simon(int n)
{
	using namespace std;
	cout << "Simon says touch your toes " << n << " times." << endl;
}


//2.6 convert.cpp -- converts stone to pounds

void ProgramList_2_6(void)
{
	int stonetolb(int);
	int stone;

	cout << "Enter the weight in stone: ";
	cin >> stone;

	int pounds = stonetolb(stone);

	cout << stone << " stone = ";
	cout << pounds << " pounds." << endl;
}

int stonetolb(int sts)
{
	return 14 * sts;
}


/*��ϰ��*/
/*--------------------------------------------*/
//2.7.2

void Exam_2(void)
{
	float Long, Yard;

	cout << "1 Long ����220�룬"
		<< "�� n Long ���ڣ�" << endl;
	cout << "����n: ";
	cin >> Long;

	Yard = Long * 220;

	cout << Long << " Long ����" << Yard << "��." << endl;

}


//2.7.3

void Exam_3(void)
{
	void PringMice(void);
	void PringRun(void);

	PringMice();
	PringMice();
	PringRun();
	PringRun();
}


void PringMice(void)
{
	cout << "Three blind mice" << endl;
}

void PringRun(void)
{
	cout << "See how they run" << endl;
}


//2.7.4

void Exam_4(void)
{
	int age;

	cout << "Enter your age: ";
	cin >> age;
	cout << "�������Ϊ" << age << "��;" << endl;
	cout << "�����" << age << "�꣬�൱��" << age * 12 << "����." << endl;
}


//2.7.5

void Exam_5(void)
{
	int Celsius;
	double TransTemperature(int);

	cout << "Please enter a Celsius value: ";
	cin >> Celsius;
	cout << Celsius << " degrees Celsius is "
		<< TransTemperature(Celsius) << " degrees Fahrenheit." << endl;
}

double TransTemperature(int n)
{
	double a = 1.8 * n + 32.0;

	return a;
}


//2.7.7

void Exam_7(void)
{
	int hours, minutes;
	void CombineTime(int, int);

	cout << "Enter the number of hours: ";
	cin >> hours;
	cout << "Enter the number of minutes: ";
	cin >> minutes;

	CombineTime(hours, minutes);
}

void CombineTime(int a, int b)
{
	cout << "Time: " << a << ":" << b;
}













