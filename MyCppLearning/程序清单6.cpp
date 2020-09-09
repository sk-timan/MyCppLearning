#include <iostream>
#include <climits>
#include <cctype>				//prototypes for character functions
#include <fstream>				//for file I/O
#include <cstdlib>              //surppot for exit()
#include "pch.h"


using namespace std;


//6.2 ifelse.cpp -- using the if else statement

void ProgramList_6_2(void)
{
	char ch;
	cout << "Type and I shall repeat.\n";
	cin.get(ch);
	while (ch != '.')
	{
		if (ch == '\n')
			cout << ch;        //done if new line
		else
			cout << ++ch;           //done otherwise
			//cout << ch + 1;          // int 化为ASCII码
		cin.get(ch);
	};
	cout << "\nPlease excuse the slight confusion.\n";

}


//6.3 ifelseif.cpp -- using if else if else

void ProgramList_6_3(void)
{
	const int Fave = 27;
	int n;

	cout << "Enter a number in the range 1-100 to find ";
	cout << "my favorite number: ";

	do
	{
		cin >> n;
		if (n < Fave)
			cout << "Too low -- guess again: ";
		else if (n > Fave)
			cout << "Too high -- guess again: ";
		else
			cout << Fave << " is right!\n";
	} while (n != Fave);

}


//6.4 or.cpp -- using the logical OR operator

void ProgramList_6_4(void)
{
	cout << "This program may reformat your hard disk\n"
		"and destory all your data.\n"
		"Do you wish to continue? <y/n> ";

	char ch;
	cin >> ch;
	if (ch == 'y' || ch == 'Y')            //y or Y
		cout << "You were warned!\a\a\n";
	else if (ch == 'n' || ch == 'N')          //n or N
		cout << "A wise choice ... bye\n";
	else
		cout << "That wasn't a y or n! Apparently you "
		"can't follow\ninstructions, so "
		"I'll trash you disk anyway.\a\a\a\n";

}


//6.5 and.cpp -- using the logical AND operator

void ProgramList_6_5(void)
{
	const int ArSize = 6;
	float naaq[ArSize];
	cout << "Enter the NAAQs (New Age Awareness Quotients) "
		<< "of\nyour neighbors. Program terminates "
		<< "when you make\n" << ArSize << " entries "
		<< "or enter a negative value.\n";

	int i = 0;
	float temp;
	cout << "First value: ";
	cin >> temp;
	while (i < ArSize && temp >= 0)
	{
		naaq[i] = temp;
		++i;
		if (i < ArSize)
		{
			cout << "Next value: ";
			cin >> temp;
		}
	}

	if (i == 0)
		cout << "No data--bye\n";
	else
	{
		cout << "Enter your NAAQ: ";
		float you;
		cin >> you;
		int count = 0;
		for (int j = 0; j < i; j++)
		{
			if (naaq[j] > you)
				++count;
		};
		cout << count;
		cout << " of your neighbers have greater awareness of\n"
			<< "the New Age than you do.\n";
	}

}


//6.7 not.cpp -- using the not operator

void ProgramList_6_7(void)
{
	bool is_int(double);
	double num;

	cout << "Yo, dute! Enter an integer value: ";
	cin >> num;
	while (!is_int(num))        //continue while num is not int-able
	{
		cout << "Out of range -- please try again: ";
		cin >> num;
	}
	int val = int(num);    //type cast
	cout << "You've entered the integer " << val << "\nBye\n";

}

bool is_int(double x)
{
	if (x <= INT_MAX && x >= INT_MIN)                 //use climits values
		return true;
	else
		return false;
}


//6.8 cctypes.cpp -- using the ctype.h library

void ProgramList_6_8(void)
{
	cout << "Enter text for analysis, and type @"
		" to terminate input.\n";
	char ch;
	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;

	cin.get(ch);				//get fitst character
	while (ch != '@')
	{
		if (isalpha(ch))             // is it an alphabetic character?
			chars++;
		else if (isspace(ch))         // is it a whitespace character?
			whitespace++;
		else if (isdigit(ch))         //is it a digit?
			digits++;
		else if (ispunct(ch))         // is it punctuation?
			punct++;
		else
			others++;

		cin.get(ch);                    //get next character
	}

	cout << chars << " letters, "
		<< whitespace << " whitespace, "
		<< digits << " digits, "
		<< punct << " punctuations, "
		<< others << " others.\n";

}


//6.9 condit.cpp -- using the conditional operator

void ProgramList_6_9(void)
{
	int a, b;
	cout << "Enter two integers: ";
	cin >> a >> b;
	cout << "The larger of " << a << " and " << b;
	int c = a > b ? a : b;         //c=a if a > b, else c = b;
	cout << " is " << c << endl;

}


//6.10 switch.cpp -- using the switch statement

void ProgramList_6_10(void)
{
	void showmenu();
	void report();
	void comfort();

	showmenu();
	int choice;
	cin >> choice;
	while (choice != 5)
	{
		switch (choice)
		{
			case 1:	cout << "\a\n";
				break;
			case 2: report();
				break;
			case 3:	cout << "The boss was in all day.\n";
				break;
			case 4:comfort();
				break;
			default:cout << "That's not a choice.\n";
		}
		showmenu();
		cin >> choice;
	}
	cout << "Bye!\n";

}

void showmenu()
{
	cout << "Plese enter 1, 2, 3, 4 or 5:\n"
		"1) alram			2) report\n"
		"3) alibi			4) comfort\n"
		"5) quit\n";
}

void report()
{
	cout << "It's been an excellent week for buisness.\n"
		"Sales are up 120%. Expenses are down 35%.\n";
}

void comfort()
{
	cout << "Your Employees think you are the finest CEO\n"
		"in the industry. The board of directors think\n"
		"you are the finest CEO in the industry.\n";
}


//6.11 enum.cpp -- using enum

void ProgramList_6_11(void)
{
	//create named constants for 0 - 6
	enum {red, orange, yellow, green, blue, violet, indigo};

	cout << "Enter color code (0-6): ";
	int code;
	cin >> code;
	while (code >= red && code <= indigo)      //while循环将枚举量提升为int型
	{
		switch (code)        //switch 同理
		{
			case red: cout << "Her lips were red.\n"; break;
			case orange: cout << "Her hair was orange.\n"; break;
			case yellow: cout << "Her shoes were yellow.\n"; break;
			case green: cout << "Her nails were green.\n"; break;
			case blue: cout << "Her sweatsuit was blue.\n"; break;
			case violet: cout << "Her eyes were violet.\n"; break;
			case indigo: cout << "Her mood was indigo.\n"; break;
		}
		cout << "Enter color code (0-6): ";
		cin >> code;
	}
	cout << "Bye!\n";

}


//6.12 jump.cpp -- using continue and break

void ProgramList_6_12(void)
{
	const int ArSize = 80;
	char line[ArSize];
	int spaces = 0;

	cout << "Enter a line of text:\n";
	cin.get(line, ArSize);
	cout << "Complete line:\n" << line << endl;
	cout << "Line through first period:\n";
	for (int i = 0; line[i] != '\0'; i++)
	{
		cout << line[i];            //display character
		if (line[i] == '.')          //quit if it's a period
			break;
		if (line[i] != ' ')			//skip rest of loop
			continue;
		spaces++;            //for 循环中continue使程序直接跳到更新表达式处，然后跳到测试表达式处；而while中则直接跳到测试表达式处
		cout << "spaces++\n";
	}
	cout << "\n" << spaces << " spaces\n";
	cout << "Done.\n";
	
}


//6.13 cinfish.cpp -- non-nummeric input terminates loop

void ProgramList_6_13(void)
{
	const int Max = 5;
	double fish[Max];
	cout << "Enter the weights of your fish.\n";
	cout << "You may enter up to " << Max
		<< " fish <q to terminate>.\n";
	cout << "fish #1: ";
	int i = 0;
	while (i < Max && cin >> fish[i])              //cin位于测试条件中，则将被转化为bool型，输入成功为true
	{
		if (++i < Max)
			cout << "fish #" << i + 1 << ": ";
	}

	double total = 0.0;
	for (int j = 0; j < i; j++)
		total += fish[j];

	if (i == 0)
		cout << "No fish\n";
	else
		cout << total / i << " = average weight of "
		<< i << " fish\n";

	cout << "Done.\n";

}


//6.14 cingolf.cpp -- non-numeric input skipped

void ProgramList_6_14(void)
{
	const int Max = 5;
	int golf[Max];
	cout << "Please enter your golf scores.\n";
	cout << "You must enter " << Max << " rounds.\n";
	int i;
	for (i = 0; i < Max; i++)
	{
		cout << "rounds #" << i + 1 << ": ";
		while (!(cin >> golf[i]))
		{
			cin.clear();					//reset input 少了这步将拒绝读取数据
			while (cin.get() != '\n')			//判断输入列表是否到了末尾
			{
				cout << "next\n";
				continue;					//get rid of bad input
				cout << "a\n";
			}
			cout << "Please enter a number: ";	
		}
	}

	double total = 0.0;
	for (i = 0; i < Max; i++)
		total += golf[i];

	cout << total / Max << " = average score "
		<< Max << " rounds\n";

}


//6.15 outfile.cpp -- writing to a file

void ProgramList_6_15(void)
{
	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;             //create object for output
	outFile.open("carinfo.txt");  //associate with a file

	cout << "Enter the make and model of automobile: ";
	cin.getline(automobile, 50);
	cout << "Enter the model year: ";
	cin >> year;
	cout << "Enter the original asking price: ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	//display information on screen with cout

	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "Make and model: " << automobile << endl;
	cout << "Year: " << year << endl;
	cout << "Was asking $" << a_price << endl;
	cout << "Now asking $" << d_price << endl;

	//now do exact same things using out file instead of cout

	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "Make and model: " << automobile << endl;
	outFile << "Year: " << year << endl;
	outFile << "Was asking $" << a_price << endl;
	outFile << "Now asking $" << d_price << endl;

	outFile.close();                               //done with file

}


//6.16 sumafile.cpp -- functions with an array argument

void ProgramList_6_16(void)
{
	const int SIZE = 60;
	char filename[SIZE];
	ifstream inFile;             // object for handling file input
	cout << "Enter name of data file: ";
	cin.getline(filename, SIZE);
	inFile.open(filename);       //associate inFile with a file
	if (!inFile.is_open())       //failed to open file
	{
		cout << "Could not open the file " << filename << endl;
		cout << "Program terminating.\n";
		exit(EXIT_FAILURE);						//同操作系统通信的参数值EXIT_FAILURE，函数exit()终止程序
	}

	double value, sum = 0.0;
	int count = 0;					//number of items read
	
	inFile >> value;				//get first value
	while (inFile.good())            //while input good and not at EOF
	{
		count++;					//ont more item read
		sum += value;				//calculate running total
		inFile >> value;			//get next value
	}

	if (inFile.eof())
		cout << "End of file reached.\n";
	else if (inFile.fail())
		cout << "Input terminated by data mismatch.\n";
	else
		cout << "Input terminated by unknown reason.\n";

	if (count == 0)
		cout << "No data processed.\n";
	else
	{
		cout << "Items read: " << count << endl;
		cout << "Sum: " << sum << endl;
		cout << "Average: " << sum / count << endl;
	}

	inFile.close();

}


/*练习题*/
/*--------------------------------------------*/
//6.11.1

void Exam_6_1(void)
{
	char ch;
	cout << "Please Enter some words: ";
	while (cin.get(ch) && ch != '@')
	{
		if (islower(ch))
			ch -= 32;
		else if (isupper(ch))
			ch += 32;
		else if (isdigit(ch))
			continue;
		
		cout << ch;
	}

}


//6.11.2

void Exam_6_2(void)
{
	const int ArSize = 10;
	double dnts[ArSize];
	cout << "Please Enter donations(up to "<< ArSize<<", q to terminate ): \n";
	double count = 0.0;
	int i = 0;
	double num;
	while (i < ArSize && cin >> num)
	{
		dnts[i] = num;
		count += num;
		i++;
	}

	double Average;
	int Lnum = 0;
	Average = count / i;
	cout << "The Average = " << Average << ".\n";
	for (int j = 0; j < i; j++)
	{
		if (dnts[j] > Average)
			Lnum++;
	}
	cout << Lnum <<" numbers more than Average." << endl;

}


//6.11.3

void Exam_6_3(void)
{
	void carnivore();
	void pianist();
	void tree();
	void game();
	char ch = ' ';
	cout << "Please enter one of the following choices: \n"
		<< "c) carnivore\t\tp) pianist\n"
		<< "t) tree     \t\tg) game\n";

	
	while (ch != '\n' && cin.get(ch))
	{
		switch (ch)
		{
			case 'c':
				carnivore();
				break;
			case 'p':
				pianist();
				break;
			case 't':
				tree();
				break;
			case 'g':
				game();
				break;
			default :
				cout << "Please enter a c, p, t or g: ";
				cin.ignore(numeric_limits<streamsize>::max(),'\n');           //清空缓冲区
				continue;
		}
		ch = '\n';
		
	}

}

void carnivore(void)
{
	cout << "You choose carnivore.";
}

void pianist(void)
{
	cout << "You choose pianist.";
}

void tree(void)
{
	cout << "A maple is a tree.";
}

void game(void)
{
	cout << "Do u like Van♂ yoo~~ see?";
}


//6.11.4

const int strsize = 20;
struct bop {
	char fullname[strsize];   //real name
	char title[strsize];	  //job title
	char bopname[strsize];	  //secret BOP name
	int preference;			  //0 = fullname, 1 = title, 2 = bopname
};

void Exam_6_4(void)
{
	void ShowOptions();
	void DisplayByPreference(bop [], int);
	bop firstlist[5] =
	{
		{"Winp Macho","Engineer","ER",0},
		{"ZhanTianyuan","Directer","Guangdou",2},
		{"HuangLiangzhi","Programer","LaoHuang",1},
		{"WangLing","TechnicalArtist","LingLing",0},
		{"YinGuo'an","SpecialEffect","Anan",2}
	};
	cout << "Benevolent Order of Programmers Report\n";
	ShowOptions();
	cout << "Enter your choice: ";
	char ch;
	cin.get(ch);
	while (ch != 'q')
	{
		switch (ch)
		{
			case 'a': 
				for (int i = 0; i < 5; i++)
				{
					cout << firstlist[i].fullname << endl;
				};
				break;
			case 'b':
				for (int i = 0; i < 5; i++)
				{
					cout << firstlist[i].title << endl;
				};
				break;
			case 'c':
				for (int i = 0; i < 5; i++)
				{
					cout << firstlist[i].bopname << endl;
				};
				break;
			case 'd':
				DisplayByPreference(firstlist, 5);
				break;
			default :
				cout << "Please Enter a, b, c, d or q.\n";
		}
		cin.ignore(256, '\n');
		cout << "Enter your choice: ";
		cin.get(ch);
	}
	cout << "Bye!" << endl;

}

void ShowOptions(void)
{
	cout << "a. display by name  \tb. display by title\n"
		<< "c. display by bopname\td. display by preference\n"
		<< "q. quit\n";
}


void DisplayByPreference(bop list[],int Arsize)
{
	int i;
	for (i = 0; i < Arsize; i++)
	{
		switch (list[i].preference)
		{
			case 0:
				cout << list[i].fullname << endl;
				break;                                   //跳出switch,并执行cout
			case 1:
				cout << list[i].title << endl;
				continue;								//跳出循环，直达for循环中的测试条件
			case 2:
				cout << list[i].bopname << endl;
				continue;
		};

		cout << "Test\n";
	};
}


//6.11.5

void Exam_6_5(void)
{
	long int Money;
	double tvarps = 0.0;
	cout << "Please enter your income: ";
	while (cin >> Money && Money >=0)
	{
		if (Money >= 0 && Money <= 5000)
			tvarps = 0.0;
		else if (Money > 5000 && Money <= 15000)
			tvarps = (double(Money) - 5000) * 0.10;
		else if (Money > 15000 && Money <= 35000)
			tvarps = 10000 * 0.10 + (double(Money) - 15000) * 0.15;
		else
			tvarps = 10000 * 0.10 + 20000 * 0.15 + (double(Money) - 35000) * 0.20;

		cout << "tvarps = " << tvarps << endl;
		cout << "Please enter your income: ";
	}

}


//6.11.6

void Exam_6_6(void)
{
	struct Donate {
		string name;
		double amount;
	};
	int PeopleNum;
	cout << "Please enter number of donaters: ";
	cin >> PeopleNum;
	
	Donate* donatelist = new Donate[PeopleNum];
	cout << "Please Enter name and amount:\n";
	for (int i = 0; i < PeopleNum; i++)
	{
		cout << "#" << i << ":\n";
		cout << "Name: ";
		//cin >> donatelist[i].name;
		cout << "amount: ";
		cin >> donatelist[i].amount;
	}

	Donate* GrandPatrons = new Donate[PeopleNum];
	Donate* Patrons = new Donate[PeopleNum];
	int GPcount = 0;
	int Pcount = 0;
	for (int i = 0; i < PeopleNum; i++)
	{
		if (donatelist[i].amount >= 10000)
		{
			GrandPatrons[GPcount].name = donatelist[i].name;
			GrandPatrons[GPcount].amount = donatelist[i].amount;
			GPcount++;
		}
		else
		{
			Patrons[Pcount].name = donatelist[i].name;
			Patrons[Pcount].amount = donatelist[i].amount;
			Pcount++;
		}
	}
	
	cout << "GrandPatrons:\n";
	if (GPcount == 0)
		cout << "None\n";
	else
		for (int i = 0; i < GPcount; i++)
		{
			//cout << GrandPatrons[i].name << "\t";
			cout << GrandPatrons[i].amount << endl;
		}

	cout << "Patrons:\n";
	if (Pcount == 0)
		cout << "None\n";
	else
		for (int i = 0; i < Pcount; i++)
		{
			//cout << Patrons[i].name << "\t";
			cout << Patrons[i].amount << endl;
		}
	delete[] donatelist;
	delete[] GrandPatrons;
	delete[] Patrons;

}


//6.11.8

void Exam_6_8(void)
{
	const int Size = 60;
	char filename[Size];
	ifstream inFile;
	cout << "Emter name of data file: ";
	cin.getline(filename, Size);

	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "Open file Failed!!\n";
		exit(EXIT_FAILURE);
	}

	char ch;
	int count = 0;
	inFile >> ch;
	while (inFile.good())
	{
		count++;
		inFile >> ch;
	}
	if (inFile.eof())
		cout << "End of file reached.\n";
	else
		cout << "Input terminated for nuknown reason.\n";

	if (count == 0)
		cout << "No data processed.\n";
	else
		cout << "File contains " << count << " words.\n";

	inFile.close();

}


//6.11.9
void Exam_6_9(void)
{
	const int Size = 60;
	char filename[Size];
	ifstream inFile;
	cout << "Please enter the file name: ";
	cin.getline(filename,Size);
	inFile.open(filename);
	if (!inFile.is_open())
	{
		cout << "open file failed!!\n";
		exit(EXIT_FAILURE);
	}

	struct Donate {
		string name;
		int amount;
	};
	int PeopleNum;
	int i = 0;
	inFile >> PeopleNum;
	Donate* donatelist = new Donate[PeopleNum];

	while (inFile.good())
	{
		char line[81];
		inFile.get();
		inFile.getline(line, 81);
		donatelist[i].name = line;
		//cout << donatelist[i].name <<"\n";
		inFile >> donatelist[i].amount;
		cout << donatelist[i].amount << endl;
		i++;
	}

	cout << "Next\n";
	Donate* GrandPatrons = new Donate[PeopleNum];
	Donate* Patrons = new Donate[PeopleNum];
	int GPcount = 0;
	int Pcount = 0;
	for (int i = 0; i < PeopleNum; i++)
	{
		if (donatelist[i].amount >= 10000)
		{
			GrandPatrons[GPcount].name = donatelist[i].name;
			GrandPatrons[GPcount].amount = donatelist[i].amount;
			GPcount++;
		}
		else
		{
			Patrons[Pcount].name = donatelist[i].name;
			Patrons[Pcount].amount = donatelist[i].amount;
			Pcount++;
		}
	}

	cout << "GrandPatrons:\n";
	if (GPcount == 0)
		cout << "None\n";
	else
		for (int i = 0; i < GPcount; i++)
		{
			//cout << GrandPatrons[i].name << "\t";
			cout << GrandPatrons[i].amount << endl;
		}

	cout << "Patrons:\n";
	if (Pcount == 0)
		cout << "None\n";
	else
		for (int i = 0; i < Pcount; i++)
		{
			//cout << Patrons[i].name << "\t";
			cout << Patrons[i].amount << endl;
		}
	delete[] donatelist;
	delete[] GrandPatrons;
	delete[] Patrons;

}








