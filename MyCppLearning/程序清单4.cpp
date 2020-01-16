#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <array>

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
	strcpy_s(charr1, charr2);           //C-style���ƣ������߸��Ƹ�ǰ��
	str1 += " paste";
	strcat_s(charr1, " juice");        //C-style���
	int len1 = str1.size();
	int len2 = strlen(charr1);

	cout << "The string " << str1 << " contains "
		<< len1 << " characters.\n";
	cout << "The string " << charr1 << " contains "
		<< len2 << " characters.\n";

	cout << "Enter a Line: ";
	cin.getline(charr1, 20);
	cout << "Enter anoher Line: ";
	getline(cin, str1);                   //��һ�������ȡ��string��
	cout << charr1 << ", " << str1 << endl;

}


//4.11 structur.cpp -- a simple structure

struct inflatable                     //structure declaration     ������Ҫ��������ǰ
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


//4.15 pointer.cpp -- our first pointer variable

void ProgramList_4_15(void)
{
	int updates = 6;
	int* p_updates;
	p_updates = &updates;

	cout << "Value: updates = " << updates;
	cout << ", *p_updates = " << *p_updates << endl;
	cout << "Addresses: &updates = " << &updates;
	cout << ", p_updates = " << p_updates << endl;

	*p_updates = *p_updates + 1;
	cout << "Now updates = " << updates << endl;

}


//4.17 use_new.cpp -- using the new operator

void ProgramList_4_17(void)
{
	int nights = 1001;
	int* pt = new int;           //����new����ָ��
	*pt = 1001;

	cout << "nights value = ";
	cout << nights << ": location " << &nights << endl;
	cout << "int ";
	cout << "value = " << *pt << ": location = " << pt << endl;
	
	double* pd = new double;
	*pd = 10000001.0;

	cout << "double ";
	cout << "value = " << *pd << ": location = " << pd << endl;
	cout << "location of pointer pd: " << &pd << endl;
	cout << "size of pt = " << sizeof(pt);
	cout << ": size of *pt = " << sizeof(*pt) << endl;
	cout << "size of pd = " << sizeof(pd);
	cout << "size of *pd = " << sizeof(*pd) << endl;

}


//4.18 arraynew.cpp -- using the new operator for arrays

void ProgramList_4_18(void)
{
	double* p3 = new double[3];
	p3[0] = 0.2;
	p3[1] = 0.5;
	p3[2] = 0.8;

	cout << "p3[1] is " << p3[1] << ".\n";

	p3 = p3 + 1;                                //ָ��+1������ָ����һ��Ԫ�صĵ�ַ.

	cout << "Now p3[0] is " << p3[0] << " and ";
	cout << "p3[1] is " << p3[1] << ".\n";

	p3 = p3 - 1;
	delete[] p3;

}


//4.19 addpntrs.cpp -- pointer addition

void ProgramList_4_19(void)
{
	double wages[3] = { 1000.0, 2000.0, 3000.0 };
	short stacks[3] = { 3, 2, 1 };

	//Here are two ways to get the address of an array
	double* pw = wages;                 //name of an array = address; wages = &wages[0]   
	short* ps = &stacks[0];              //or use address operator

	cout << "pw = " << pw << ", *pw = " << *pw << endl;

	pw++;

	cout << "add 1 to the pw pointer:\n";
	cout << "pw = " << pw << ", *pw = " << *pw << "\n\n";
	cout << "ps = " << ps << ", *ps = " << *ps << endl;

	ps++;

	cout << "add 1 to the ps pointer:\n";
	cout << "ps = " << ps << ", *ps = " << *ps << "\n\n";
	cout << "access two elements with array notation\n";
	cout << "stacks[0] = " << stacks[0]
		<< ", stacks[1] = " << stacks[1] << endl;
	cout << "access two elements with pointer notation\n";
	cout << "*stacks = " << *stacks
		<< ", *(stacks + 1) = " << *(stacks + 1) << endl;               //������ʵΪ��һ��Ԫ�ص�ַ
	cout << sizeof(wages) << " = size of wages array\n";
	cout << sizeof(pw) << " = size of pw pointer\n";                   //��ַΪ16����int

}


//4.20 ptrstr.cpp -- using pointers to string

void ProgramList_4_20(void)
{
	char animal[20] = "bear";           //char ��СΪ 1 bytes
	const char* bird = "wren";    //bird holds address of string
	char* ps;

	cout << animal << " and ";          //cout �����������ַ�����Ԫ��ֱ���������ַ�
	cout << bird << "\n";
	cout << "Enter a kind of animal: ";
	cin >> animal;          // input < 20 is okay

	ps = animal;

	cout << ps << "!\n";
	cout << "before using strcpy():\n";
	cout << animal << " at " << (int*)animal << endl;
	cout << ps << " at " << (int*)ps << endl;

	ps = new char[strlen(animal) + 1];      //ָ��ָ���µ�ַ  +1��Ӧ����ֹ��
	
	cout << "Size of animal = " << sizeof(animal) << endl;
	cout << "Size of char = " << sizeof(char) << endl;
	strcpy_s(ps, strlen(animal) + 1, animal);             //��ps ֲ���������� + 1 �ٳ˸�1���ֽڵ��ַ���

	cout << "After using strcpy():\n";
	cout << animal << " at " << (int*)animal << endl;       //(int*)Ϊָ������ǿ��ת������char*����ָ����ת��Ϊint����cout����ַ
	cout << animal << " at " << &animal << endl;
	cout << ps << " at " << (int*)ps << endl;

	char test = '6';
	char* ptest = &test;
	cout << "address of " << test << "(test) = " << (int*)&test << endl;
	cout << "value of " << test << "(test) = " << (int*)test << endl;  //�ַ���6��Ӧ��ֵΪASCII��
	cout << "address of ptest = " << &ptest << endl;                //ָ��ptest�Լ��ĵ�ַ��test��ͬ
	cout << "value of ptest = " << (int*)ptest << endl;             //ָ��ptest�洢��ֵΪָ���test�ĵ�ַ

	test = animal[0];
	ptest = animal;
	cout << "Now, address of " << test << "(test) = " << (int*)&test << endl;
	cout << "value of " << test << "(test) = " << (int*)test << endl;
	cout << "address of ptest = " << &ptest << endl;              //�ɴ˿�����������ֻ�Ǵ洢ֵ�����������ַû�б�
	cout << "value of ptest = " << (int*)ptest << endl;

	delete[]ps;       //�ͷ������ڴ�

}


//4.21 newstrct.cpp -- using new with a structure

void ProgramList_4_21(void)
{
	struct inflatable
	{
		char name[20];
		float volume;
		double price;
	};

	inflatable* ps = new inflatable;

	cout << "Enter a name for inflatable item: ";
	//cin >> (*ps).volume;                            
	cin.get(ps->name, 20).get();                  //��ʼ״̬�£�������Ϊ�ǿգ�cin.get()�������������������س���
	cout << "Enter volume in cubic feet: ";
	//cin.get((*ps).name, 20);
	cin >> (*ps).volume;                  //cin���س�ת��Ϊ���з�������������������У�����Ŀ����������ӿ��ַ�     
	cout << "Enter a name for inflatable item: ";
	cin.get();                         //��ȡ���з���������
	cin.get((*ps).name, 20);            //�����ϲ��裬��ʱcin.get()�������з�����Ϊ�����������������������س���
	cout << "Enter price: $";
	cin >> ps->price;                    //���������س���ת���з�������һֱ�س���һֱ����
	cout << "Name: " << (*ps).name << endl;
	cout << "Volume: " << ps->volume << " cubic feet\n";
	cout << "Price: $" << ps->price << endl;

	delete ps;

}


//4.22 delete.cpp -- using the delete operator

void ProgramList_4_22(void)
{
	char* getname(void);               //function prototype   ����һ��char��ָ��
	char* name;
	name = getname();

	cout << name << " at " << (int*)name << "\n";
	delete[]name;

	name = getname();
	cout << name << " at " << (int*)name << "\n";
	delete[]name;

}


char* getname(void)
{
	char temp[80];           //��������Ϊ�Զ����������ڵ��ú���ʱ�����ڴ棬�ڽ���ʱ������
							//������ص���temp��ַ���򽫺ܿ�õ�����Ӧ��

	cout << "Enter last name: ";
	cin >> temp;
	char* pn = new char[strlen(temp) + 1];       //new �����ַ�ṩ��name�����ظ�����
	strcpy_s(pn, strlen(temp) + 1, temp);

	return pn;
}


//4.23 mixtypes.cpp -- some type combinations

void ProgramList_4_23(void)
{
	struct antarctica_year_end
	{
		int year;
	};

	antarctica_year_end s01, s02, s03;
	s01.year = 1998;
	antarctica_year_end* pa = &s02;
	pa->year = 1999;
	antarctica_year_end trio[3];
	trio[0].year = 2003;
	cout << trio->year << endl;

	const antarctica_year_end* arp[3] = { &s01, &s02, &s03 };         //arpΪָ��ṹ�����͵�ָ������
	cout << arp[1]->year << endl;

	const antarctica_year_end** ppa = arp;    //ppaΪָ��&arp[0]��ָ��
	auto ppb = arp;                    //C++11 automatic type deduction
	cout << (*ppa)->year << endl;
	cout << (*(ppa + 1))->year << endl;

}


//4.24 choices.cpp -- array variations

void ProgramList_4_24(void)
{
	//C, original C++
	double a1[4] = { 1.2, 2.4, 3.6, 4.8 };

	//C++98 STL
	vector<double> a2(4);
	//no simple way to initialize in C98
	a2[0] = 1.0 / 3.0;
	a2[1] = 1.0 / 5.0;
	a2[2] = 1.0 / 7.0;
	a2[3] = 1.0 / 9.0;

	//C++11 --create and initialize array object
	array<double, 4> a3 = { 3.14, 2.72, 1.62, 1.14 };            //array�����鶼�洢��ջ��
	array<double, 4> a4;
	a4 = a3;                                       //array���Խ�һ��array������һ��array,���������Ԫ�ظ���

	cout << "a1[2]: " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;

	//a1[-2] = 20.2;                //*(a1 - 2)  �׳����Ϸ�
	a2.at(2) = 2.3;               //ʹ��array �� vector�ĳ�Ա����at()��ֵ
	//cout << "a1[-2]: " << a1[-2] << " at " << &a1[-2] << endl;
	cout << "a2[2]: " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2]: " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2]: " << a4[2] << " at " << &a4[2] << endl;
 
}


enum num { Yes = 1, No = 0, Maybe = 2 };


/*��ϰ��*/
/*--------------------------------------------*/
//4.13.1

void Exam_4_1(void)
{
	char firstname[20], lastname[20];
	char grade;
	int age;

	cout << "What is your first name? ";
	cin.getline(firstname, 20);
	//cout << firstname << endl;
	cout << "What is your last name? ";
	cin.getline(lastname, 20);
	cout << "What letter grade do you deserve? ";
	cin >> grade;
	cout << "What is your age? ";
	cin >> age;
	cout << "Name: " << lastname << ", " << firstname << endl;
	cout << "Grade: " << grade << "\n";
	cout << "Age: " << age << endl;

}


//4.13.2

void Exam_4_2(void)
{
	string name, dessert;

	cout << "Enter your name:\n";
	getline(cin, name);
	cout << "Enter your favorite dessert:\n";
	cin >> dessert;

	cout << "I have some delicious " << dessert;
	cout << " for you, " << name << ".\n";

}


//4.13.3

void Exam_4_3(void)
{
	char firstname[20], lastname[20], combine[20];

	cout << "Enter your first name: ";
	cin.getline(firstname, 20);
	cout << "Enter your last name: ";
	cin.getline(lastname, 20);

	strcpy_s(combine, lastname);
	strcat_s(combine, ", ");
	strcat_s(combine, firstname);
	cout << "Here's the information in a single string: " << combine << endl;

}


//4.13.4

void Exam_4_4(void)
{
	string firstname, lastname, combine;

	cout << "Enter your first name: ";
	getline(cin, firstname);
	cout << "Enter your last name: ";
	getline(cin, lastname);

	combine = lastname + ", " + firstname;
	cout << "Here is the information in a single string: " << combine << endl;

}


//4.13.5

struct CandyBar
{
	char brand[20];
	double weight;
	int caloryie;
};

void Exam_4_5(void)
{
	CandyBar snack =
	{
		"Mocha Munch",
		2.3,
		350
	};

	cout << "snack's brand: " << snack.brand << ".\n";
	cout << "snack's weight = " << snack.weight << " g.\n";
	cout << "snack's surger = " << snack.caloryie << " cal." << endl;

}


//4.13.6

void Exam_4_6(void)
{
	CandyBar mycandy[3] =
	{
		{"Doveo", 2.0, 300},
		{"Beturce", 5.5, 600},
		{"Lione", 4.3, 500}
	};

	cout << mycandy[1].brand << "'s calories = " << mycandy[1].caloryie << " cal.\n";

}


//4.13.7

struct Pizza
{
	char company[20];
	double diameter;
	double weight;
};

void Exam_4_7(void)
{
	Pizza newpizza;

	cout << "Enter Company's name: ";
	cin.getline(newpizza.company, 20);
	cout << "Enter pizza's diameter: ";
	cin >> newpizza.diameter;
	cout << "Enter pizza's weight: ";
	cin >> newpizza.weight;

	cout << newpizza.company << "'s pizza: " << newpizza.diameter << " cm; " << newpizza.weight
		<< " g." << endl;

}


//4.13.8

void Exam_4_8(void)
{
	Pizza* newpizza = new Pizza;

	cout << "Enter pizza's diameter: ";
	cin >> newpizza->diameter;
	cin.get();
	cout << "Enter pizza's company: ";
	cin.getline(newpizza->company, 20);
	cout << "Enter pizza's weight: ";
	cin >> newpizza->weight;

	cout << newpizza->company << "'s pizza: " << newpizza->diameter << " cm; " << newpizza->weight
		<< " g." << endl;

	delete newpizza;

}


//4.13.9

void Exam_4_9(void)
{
	CandyBar* mycandy = new CandyBar[3];
	mycandy[0] = { "Doveo", 2.0, 300 };
	mycandy[1] = { "Beturce", 5.5, 600 };
	mycandy[2] = { "Lione", 4.3, 500 };
	
	cout << mycandy[1].brand << "'s calories = " << mycandy[1].caloryie << " cal.\n";

	delete[]mycandy;

}


//4.13.10
void Exam_4_10(void)
{
	array<double, 3> score;
	double average;

	cout << "Enter first score: ";
	cin >> score[0];
	cout << "Enter second score: ";
	cin >> score[1];
	cout << "Enter third score: ";
	cin >> score[2];

	average = (score[0] + score[1] + score[2]) / 3;

	cout << "Your average score = " << average << endl;

}










