#include <iostream>
#include <string>
#include <cstring>
#include <ctime>                    //describes clock() function, clock_t type
#include <array>
#include <cmath>
using namespace std;


//5.1 forloop.cpp - introducing the for loop

void ProgramList_5_1(void)
{
	int i;
	for (i = 0; i < 5; i++)
	{
		cout << "C++ knows loops.\n";
	};                                        //C style loop;����ɾ������
	
	cout << "C++ knows when to stop.\n";

	cout << "Enter the starting countdown value: ";
	int limit;
	cin >> limit;
	for (i = limit; i; i--)
		cout << "i = " << i << "\n";

	cout << "Done, now i = " << i << endl;

}


//5.3 express.cpp -- values of expressions

void ProgramList_5_3(void)
{
	int x;

	cout << (x = 100) << endl;
	cout << "The expression x < 3 has the value ";
	cout << (x < 3) << endl;
	cout << "The expression x > 3 has the value ";
	cout << (x > 3) << endl;

	cout.setf(ios_base::boolalpha);         //a newer C++ feature;Display "ture, false" instead of "1, 0"
	cout << "The expression x < 3 has the value ";
	cout << (x < 3) << endl;
	cout << "The expression x > 3 has the value ";
	cout << (x > 3) << endl;

}


//5.7 plus_one.cpp -- the increment operator

void ProgramList_5_7(void)
{
	int a = 20;
	int b = 20;

	cout << "a   = " << a << ":   b = " << b << "\n";
	cout << "a++ = " << a++ << ": ++b = " << ++b << "\n";   //a++��ζ����ʹ��a��ǰֵ��Ȼ���ٽ�a��1
	cout << "a   = " << a << ":   b = " << b << "\n";
 
}


//5.8 block.cpp -- use a block statement

void ProgramList_5_8(void)
{
	cout << "The Amazing Accounto will sum and average ";
	cout << "five numbers for you.\n";
	cout << "Please enter five values:\n";

	double number;
	double sum = 0.0;
	for (int i = 1; i <= 5; ++i)                //i++ͬЧ������Ϊ����ѭ���Ĳ���������ĩβ��һ��˳���  
	{                                          //block starts here
		cout << "Value " << i << ": ";         //���������ţ��༭��������������ѭ��ִֻ�е�һ�����
		cin >> number;
		sum += number;
	};                                         //block ends here

	cout << "Five exquisite choices indeed! ";
	cout << "They sum to " << sum << endl;
	cout << "and average to " << sum / 5 << ".\n";
	cout << "The Amazing Accounto bids you adieu!\n";

}


//5.9 forstr2.cpp -- reversing an array

void ProgramList_5_9(void)
{
	cout << "Enter a word: ";
	string word;
	cin >> word;

	char temp;
	int i, j;
	for (j = 0, i = word.size() - 1; j < i; --i, ++j)
	{
		temp = word[i];
		word[i] = word[j];
		word[j] = temp;
	};
	cout << word << " \nDone\n";

}


//5.11 compstr1.cpp -- comparing strings using arrays

void ProgramList_5_11(void)
{
	char word[5] = "?ate";
	for (char ch = 'a'; strcmp(word, "mate") != 0; ch++)             //strcmp()�ж����ַ����Ƿ���ͬ��С����Ϊ��(ASCII)������Ϊ��,����Ϊ0 
	{
		cout << word << endl;
		word[0] = ch;
	};
	cout << "After loop ends, word is " << word << endl;

	string word2 = "?ate";
	for (char ch = 'a'; word2 != "mate"; ch++)                      //string�����������!=(������һ��string��ʱ)
	{
		cout << word2 << endl;
		word2[0] = ch;
	};
	cout << "After loop ends, word is " << word << endl;

}


//5.13 while.cpp -- introducing the while loop

void ProgramList_5_13(void)
{
	const int ArSize = 20;
	char name[ArSize];
	cout << "Your first name, please: ";
	cin >> name;
	cout << "Here is your name, verticalized and ASCIIized:\n";
	
	int i = 0;
	while (name[i] != '\0')
	{
		cout << name[i] << ": " << int(name[i]) << endl;
		i++;                                             //ѭ��������޸�iֵ
	};

}


//5.14 waiting.cpp --using clock() in a time-delay loop

void ProgramList_5_14(void)
{
	cout << "Enter the delay time, in seconds: ";
	
	float secs;
	cin >> secs;
	clock_t delay = secs * CLOCKS_PER_SEC;          //convert to clock ticks

	cout << "starting\a\n";
	clock_t start = clock();                       //��clock_t ��Ϊclock()�������͵ı���
	while (clock() - start < delay);

	cout << "done\a\n";

}


//5.15 dowhile.cpp -- exit-condition loop

void ProgramList_5_15(void)
{
	int n;

	cout << "Enter numbers in the range 1-10 to find ";
	cout << "my favorite number\n";

	do
	{
		cin >> n;
	} while (n != 7);

	cout << "Yes, 7 is my favorite.\n";

}



//5.16 textin1.cpp -- reading chars with a while loop

void ProgramList_5_16(void)
{
	char ch;
	int count = 0;
	cout << "Enter characters; enter # to quit:\n";
	cin >> ch;           //���͸�cin�ı�����
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin >> ch;        //cin���Կո�ͻ��з������û�б�����
	}

	cout << endl << count << " characters read\n";

	cout << "Enter characters; enter # to quit:\n";
	count = 0;
	cin.get(ch);
	while (ch != '#')
	{
		cout << ch;
		++count;
		cin.get(ch);            //cin.get()���ո�ͻ��з��������
	};
	cout << endl << count << " characters read\n";

}


//5.18 textin3.cpp -- reading chars to end of file

void ProgramList_5_18(void)
{
	char ch;
	int count = 0;
	cin.get(ch);

	while (cin.fail() == false)               //test for EOF�����eofbit��failbit������Ϊ1����fail()��Ա��������ture 
	{
		cout << ch;
		++count;
		cin.get(ch);							//�谴��ctrl+z��ģ���ļ�β
	};                                        

	cout << endl << count << " characters read\n";

}


//5.19 textin4.cpp -- reading chars with cin.get()

void ProgramList_5_19(void)
{
	int ch;
	int count = 0;

	while ((ch = cin.get()) != EOF)     //���ַ�������Ϊintֵ���أ�EOFֵ������Ϊ-1��û�пɷ��ص��ַ�ʱ��cin.get()������EOF
	{
		cout.put(char(ch));
		++count;
	};
	cout << endl << count << " characters read\n";
}


//5.20 nested.cpp -- nested loops and 2-D array

void ProgramList_5_20(void)
{
	const int Cities = 5;
	const int Years = 4;
	const char* cities[Cities] =            //ָ������洢5���ַ����ĵ�ַ��ʹ��ָ�������Ϊ����
	{
		"Gribble City",
		"Gribbletown",
		"New Gribble",
		"San Gribble",
		"Gribble Vista"
	};

	int maxtemps[Years][Cities] =
	{
		{96, 100, 87, 101, 105},
		{96, 98, 91, 107, 104},
		{97, 101, 93, 108, 107},
		{98, 103, 95, 109, 108}
	};

	cout << "Maximum temperatures for 2008 - 2011\n\n";
	for (int city = 0; city < Cities; ++city)
	{
		cout << cities[city] << ":\t";
		for (int year = 0; year < Years; year++)
			cout << maxtemps[year][city] << "\t";
		cout << endl;
	};

}


//5.21

void ProgramList_5_21(void)
{
	int x = (1, 024);   //ȡ��ֵ��ת��Ϊ�˽��ƣ�0��ͷ��
	int y;
	y = 1, 024;          //y=1,   024����Ϊ�������ֵ�ı��ʽ��

	cout << "x = " << x << "\n";
	cout << "y = " << y << endl;

}


/*��ϰ��*/
/*--------------------------------------------*/
//5.9.1

void Exam_5_1(void)
{
	int i, j;
	cout << "Please Enter the first number: ";
	cin >> i;

	cout << "\n";
	cout << "Go ahead, Enter the second number: ";
	cin >> j;

	int count = 0;
	for (; i <= j; i++)
		count += i;

	cout << "The count number = " << count << endl;

}


//5.9.2

void Exam_5_2(void)
{
	const int ArSize = 101;
	array<long double, ArSize> factorials;
	factorials.at(0) = factorials[1] = 1.0L;
	for (int i = 2; i < ArSize; i++)
		factorials[i] = i * factorials[i - 1];

	for (int i = 0; i < ArSize; i++)
		cout << i << "! = " << factorials[i] << endl;

}


//5.9.3

void Exam_5_3(void)
{
	int number = 1;
	int count = 0;

	while (number/*cin >> number*/)         //cin����iostream������޷���ֵ�������ȡ�ɹ���Ϊtrue
	{
		cout << "Enter the number: ";
		cin >> number;
		count += number;
		cout << "All numbers account to: " << count << endl;
	};

	cout << "Ending Program..." << endl;

}


//5.9.4

void Exam_5_4(void)
{
	int years = 0;
	double money1 = 0, money2 = 0;
	
	while (money1 >= money2)
	{
		years++;
		money1 = 0.10 * 100 * years + 100;
		money2 = pow(1.05, years) * 100;

	};
		
	cout << "When " << years << " years later, Cleo's money is more than Daphne's.\n";
	cout << "Daphne's money: " << money1 << "\n";
	cout << "Cleo's money: " << money2 << endl;
	
}


//5.9.5

void Exam_5_5(void)
{
	string month[12];
	int amount[12];
	for (int i = 0; i < 12; i++)
	{
		month[i] = to_string(i+1) + " Month";
		cout << "Enter the " << i + 1 << " month's sales amount: ";

		cin >> amount[i];
	};
	
	int Total = 0;
	for (int i = 0; i < 12; i++)
	{
		cout << month[i] <<":\t " << amount[i] << "\n";
		Total += amount[i];
	};
	
	cout << "Totol sales amount: " << Total << endl;

}


//5.9.6

void Exam_5_6(void)
{
	int nummap[3][12];
	string month[] = { "1","2","3","4","5","6","7","8","9","10","11","12" };
	string year[] = { "First","Second","Third" };
	int Total = 0;
	int EveryYear[3];
	for (int i = 0; i < 3; i++)
	{
		int eachyear = 0;
		for (int j = 0; j < 12; j++)
		{
			cout << "Enter the " << i + 1 << " year " << j + 1 << " month's sales amount: ";
			cin >> nummap[i][j];

			Total += nummap[i][j];
			eachyear += nummap[i][j];
		};

		EveryYear[i] = eachyear;
	};

	for (int i = 0; i < 3; i++)
	{
		cout << year[i] << " :\n";
		for (int j = 0; j < 12; j++)
		{
			cout << month[j] << " month:\t " << nummap[i][j] << "\n";
		};
		cout << year[i] << " year Total: " << EveryYear[i] << "\n";
	
	};

	cout << "Total: " << Total << endl;

}


//5.9.7

struct car
{
	string producer;
	int prodate;

};
void Exam_5_7(void)
{
	cout << "How many cars do you wish to catalog? ";
	int carnum;
	cin >> carnum;

	car* mycars = new car[carnum];

	for (int i = 0; i < carnum; i++)
	{
		cout << "Car #" << i + 1 << "\n";
		cout << "Please enter the make: ";
		cin.get();
		getline(cin, mycars[i].producer);

		cout << "Please enter the date: ";
		cin >> mycars[i].prodate;
	};

	cout << "Here is your collection: \n";

	for (int i = 0; i < carnum; i++)
	{
		cout << mycars[i].prodate << " " << mycars[i].producer << "\n";

	};

	delete[] mycars;
}


//5.9.8

void Exam_5_8(void)
{
	char words[20]="";
	int number = 0;
	cout << "Enter words (to stop, type the word done):\n";

	while (strcmp(words, "done") != 0)
	{
		cin >> words;
		number += 1;
	};

	cout << "You entered a total of " << number - 1 << " words." << endl;

}


//5.9.9

void Exam_5_9(void)
{
	string words = "";
	int number = 0;
	cout << "Enter words (to stop, type the word done):\n";

	while (words != "done")
	{
		cin >> words;
		number += 1;
	};

	cout << "You entered a total of " << number - 1 << " words. " << endl;

}


//5.9.10

void Exam_5_10(void)
{
	int rows;
	cout << "Enter number of rows: \n";
	cin >> rows;

	for (int i = 0; i < rows; i++)
	{
		int j;
		for (j = 0; j < (rows - (i + 1)); j++)
			cout << ".";

		for (; j < rows; j++)
			cout << "*";

		cout << "\n";
	};

}


