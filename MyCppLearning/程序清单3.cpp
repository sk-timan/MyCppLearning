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

















