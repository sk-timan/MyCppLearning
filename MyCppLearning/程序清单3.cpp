#include <iostream>
#include <climits>

#define ZERO 0

using namespace std;

//3.1 limits.cpp -- some integer limits

void ProgramList_3_1(void)
{
	int n_int = INT_MAX;
	short n_short = SHRT_MAX;
	long n_long = LONG_MAX;
	long long n_llong = LLONG_MAX;

	//sizeof operator yields size of type or of variable
	cout << "int is " << sizeof(int) << " bytes." << endl;      //对类型名使用括号（）；
	cout << "short is " << sizeof(n_short) << " bytes." << endl;  //对变量名可以不使用；
	cout << "long is " << sizeof n_long << " bytes." << endl;
	cout << "long long is " << sizeof n_llong << " bytes." << endl;
	cout << endl;

	cout << "Maximum values:" << endl;
	cout << "int: " << n_int << endl;
	cout << "short: " << n_short << endl;
	cout << "long: " << n_long << endl;
	cout << "long long: " << n_llong << endl << endl;

	cout << "Minimum int value = " << INT_MIN << endl;
	cout << "Bits per byte = " << CHAR_BIT << endl;
	cout << "Minimum long value = " << LONG_MIN << endl;
} 


//3.2 exceed.cpp -- exceeding some integer limits

void ProgramList_3_2(void)
{
	short sam = SHRT_MAX;
	unsigned short sue = sam;

	cout << "Sam has " << sam << " dollars and sue has " << sue
		<< " dollars deposited." << endl
		<< "Add $1 to each account." << endl << "Now ";

	sam++;         //溢出后，将重置为另一端值
	sue++;

	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited.\nPoor Sam!" << endl;

	sam = ZERO;
	sue = ZERO;

	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl;
	cout << "Take $1 from each account." << endl << "Now ";

	sam--;
	sue--;
	
	cout << "Sam has " << sam << " dollars and Sue has " << sue;
	cout << " dollars deposited." << endl << "Lucky Sue!" << endl;

}


//3.6 morechar.cpp -- the char type and int type contrasted

void ProgramList_3_6(void)
{
	char ch = 'M';           //‘M'表示字符M的数值编码

	//char ch = 53;
	//cout << "Inter a char: ";
	//cin >> ch;

	int i = ch;              //两者都表示变量77

	cout << "The ASCII code for " << ch << " is " << i << endl;      //cout 智能地把char和int的打印方式分开
	cout << "Add one to the character code:" << endl;

	ch++;
	i = ch;

	cout << "The ASCII code for " << ch << " is " << i << endl; 

	//using the cout.put() member function to display a char
	cout << "Displaying char ch using cout.put(ch): ";
	cout.put(ch);

	//using cout.put() to display a char constant
	cout.put('!');
	cout << endl << "Done" << endl;

	char alarm = '\a';                           //转义符，响铃
	cout << alarm << "Don't that again!\a\n";
	cout << "Ben \"Buggsie\" Hacker\nwas here!\n";       //转义符，双引号
}


//3.7 bondini.cpp -- using escape sequences

void ProgramList_3_7(void)
{
	cout << "\aOperation \"HyperHype\" is now activated!\n";
	cout << "Enter your agent code:________\b\b\b\b\b\b\b\b";       //转义符，退格

	long code;

	cin >> code;
	cout << "\aYou entered " << code << "...\n";
	cout << "\aCode verified! Proceed with Plan Z3!\n";

	//int k\u00F6rper;
	//cout << "Let them eat g\u00E2teau.\n";        //ISO通用字符名
}


//3.8 floatnum.cpp -- floating-point types

void ProgramList_3_8(void)
{
	cout.setf(ios_base::fixed, ios_base::floatfield);     //fixed point   精确显示后面的零

	float tub = 10.0 / 3.0;              //good to about 6 places
	double mint = 10.0 / 3.0;           //good to about 15 places
	const float million = 1.0e6;

	cout << "tub = " << tub;
	cout << ", a million tubs = " << million * tub;
	cout << ", \nand ten million tubs = ";
	cout << 10 * million * tub << endl;
	cout << "mint = " << mint << " and a million mints = ";
	cout << million * mint << endl;

	float a = 2.34e+7f;               //2.34*10^7
	float b = a + 1.0f;

	cout << "a = " << a << endl;
	cout << "b - a = " << b - a << endl;    //float 只能表示小数点前6位或前7位.

	cout << 9.0 / 5 << endl;              //同类型转化，运算符重载
}


//




















