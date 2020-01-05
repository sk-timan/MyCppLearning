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
	cin >> name;         //input "Alistair Dreeb",空格符将前面存储到name中，后面填入dessert中.
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
	cin.getline(name, ArSize);         //getline以换行符作为字符串结尾，并将换行符替换为空字符.
	cout << "Enter your favorite dessert:\n";
	cin.getline(dessert, ArSize);
	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";

	cin.get(name, ArSize).get();   //get 保留换行符，留到输入队列；   cin.get()读取下一个字符(即使换行符)
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
	//cin.get();                                  //加一个get即可解决
	cin.getline(address, 80);                  //前面cin 之后换行符保留，getline将认为此为空行，
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


//4.8 strtype2.cpp --assiging, adding, and appending

void ProgramList_4_8(void)
{
	string s1 = "penguin";
	string s2, s3;

	cout << "You can assign one string object to another: s2 = s1\n";

	s2 = s1;

	cout << "s1: " << s1 << ", s2: " << s2 << endl;
	cout << "You can assign a C-style string to a string object.\n";
	cout << "s2 = \"buzzard\"\n";

	s2 = "buzzard";

	cout << "s2: " << s2 << endl;
	cout << "You can concatenate string: s3 = s1 + s2\n";

	s3 = s1 + s2;

	cout << "s3: " << s3 << endl;
	cout << "You can append string.\n";

	s1 += s2;

	cout << "s1 += s2 yields s1 = " << s1 << endl;

	s2 += " for a day";

	cout << "s2 += \" for a day\" yields s2 = " << s2 << endl;

}


//4.9 strtype3.cpp -- more string class features

void ProgramList_4_9(void)
{
	char charr1[20];
	char charr2[20] = "jaguar";
	string str1;
	string str2 = "panther";

	str1 = str2;
	strcpy_s(charr1, charr2);           //C-style复制，将后者复制给前者
	str1 += " paste";
	strcat_s(charr1, " juice");        //C-style组合
	int len1 = str1.size();
	int len2 = strlen(charr1);

	cout << "The string " << str1 << " contains "
		<< len1 << " characters.\n";
	cout << "The string " << charr1 << " contains "
		<< len2 << " characters.\n";

	cout << "Enter a Line: ";
	cin.getline(charr1, 20);
	cout << "Enter anoher Line: ";
	getline(cin, str1);                   //将一行输入读取到string中
	cout << charr1 << ", " << str1 << endl;

}


//4.11 structur.cpp -- a simple structure

struct inflatable                     //structure declaration
{
	char name[20];
	double volume;
	double price;
};

void ProgramList_4_11(void)
{
	inflatable guest =
	{
		"Glorious Gloria",
		1.88,
		29.99
	};
	inflatable pal                       //init in C++11
	{
		"Audacious Arthur",
		3.12,
		32.99
	};

	cout << "Expand your guest list with " << guest.name;
	cout << " and " << pal.name << "!\n";
	cout << "You can have both for $";
	cout << guest.price + pal.price << "!\n";

	inflatable guests[2]                       //initialing an array of structs
	{
		{"Bambi", 0.5, 21.99},
		{"Godzilla", 2000, 565.99}
	};

	cout << "The guests " << guests[0].name << " and " << guests[1].name
		<< "\nhave a combined volume of "
		<< guests[0].volume + guests[1].volume << " cubic feet.\n";
}


//4.14 address.cpp -- using the & operator to find addresses

void ProgramList_4_14(void)
{
	int donuts = 6;
	double cups = 4.5;

	cout << "donuts value = " << donuts;
	cout << " and donuts address = " << &donuts << endl;
	cout << "cups value = " << cups;
	cout << " and cups address = " << &cups << endl;
}

















