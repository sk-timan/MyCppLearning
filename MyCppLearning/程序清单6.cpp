#include <iostream>

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
			//cout << ch + 1;          // int »¯ÎªASCIIÂë
		cin.get(ch);
	};
	cout << "\nPlease excuse the slight confusion.\n";

}

