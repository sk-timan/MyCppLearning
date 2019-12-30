#include <iostream>
#include <cstring>
#include <string>

using namespace std;

//4.1 arrayone.cpp -- small arrays of integers

void ProgramList_4_1(void)
{
	int yams[3];
	yams[0] = 7;
	yams[1] = 8;
	yams[2] = 6;
	int yamcosts[3] = { 20,30,5 };

	cout << "Total yams = ";
	cout << yams[0] + yams[1] + yams[2] << endl;
	cout << "The package with " << yams[1] << " yams costs ";
	cout << yamcosts[1] << " cents per yam.\n";

	int total = yams[0] * yamcosts[0] + yams[1] * yamcosts[1];
	total = total + yams[2] * yamcosts[2];

	cout << "The total yam expense is " << total << " cents.\n";
	cout << "\nSize of yams array = " << sizeof yams;
	cout << " bytes.\n";
	cout << "Size of one element = " << sizeof yams[0];
	cout << " bytes.\n";
}


//4.2 strings.cpp -- storing strings in an array

void ProgramList_4_2(void)
{
	const int Size = 15;
	char name1[Size];
	char name2[Size] = "C++owboy";

	cout << "Howdy! I'm " << name2;
	cout << "! What's your name?\n";
	cin >> name1;
	cout << "Well, " << name1 << ", your name has ";
	cout << strlen(name1) << " letters ans is stored\n";
	cout << "in an array of " << sizeof name1 << " bytes.\n";
	cout << "Your initial is " << name1[0] << ".\n";

	name2[3] = '\0';

	cout << "Here are the first 3 characters of my name: ";
	cout << name2 << endl;
}


//4.3 instr1.cpp -- reading more than one string

void ProgramList_4_3(void)
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name:\n";
	cin >> name;         //input "Alistair Dreeb",�ո����ǰ��洢��name�У���������dessert��.
	cout << "Enter your favorite dessert:\n";
	cin >> dessert;
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";
}


//4.4 instr2.cpp -- reading more than one word with getline

void ProgramList_4_4(void)
{
	const int ArSize = 20;
	char name[ArSize];
	char dessert[ArSize];

	cout << "Enter your name:\n";
	cin.getline(name, ArSize);         //getline�Ի��з���Ϊ�ַ�����β���������з��滻Ϊ���ַ�.
	cout << "Enter your favorite dessert:\n";
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";

	cin.get(name, ArSize).get();   //get �������з�������������У�   cin.get()��ȡ��һ���ַ�(��ʹ���з�)
	cin.get(dessert, ArSize).get();
	cout << name << "\n" << dessert << endl;
}


//4.6 numstr.cpp -- following number input with line input

void ProgramList_4_6(void)
{
	int year;
	char address[80];

	cout << "What year was your house built?\n";
	cin >> year;
	cout << "What is its street address?\n";
	//cin.get();                                  //��һ��get���ɽ��
	cin.getline(address, 80);                  //ǰ��cin ֮���з�������getline����Ϊ��Ϊ���У�
	cout << "Year Built: " << year << endl;
	cout << "Address: " << address << endl;
	cout << "Done!\n";
}


//4.7 strtype1.cpp -- using the C++ string class

void ProgramList_4_7(void)
{
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	cout << "Enter a kind of feline: ";
	cin >> charr1;
	cout << "Enter another kind of feline: ";
	cin >> str1;
	cout << "Here are some feline:\n";
	cout << charr1 << " " << charr2 << " "
		<< str1 << " " << str2 << endl;
	cout << "The third letter  in " << charr2 << " is "
		<< charr2[2] << endl;
	cout << "The third letter in " << str2 << " is "
		<< str2[2] << endl;
}
















