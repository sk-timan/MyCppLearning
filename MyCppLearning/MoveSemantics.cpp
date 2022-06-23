#include "pch.h"
#include "MoveSemantics.h"

int Useless::ct = 0;

Useless::Useless()
{
	++ct;
	n = 0;
	pc = nullptr;
	cout << "default constructor called; number of object: "
		<< ct << endl;
	ShowObject();
}

Useless::Useless(int k) : n(k)
{
	++ct;
	cout << "int constructor called; number of objects: "
		<< ct << endl;
	pc = new char[n];
	ShowObject();

}

Useless::Useless(int k, char ch) : n(k)
{
	++ct;
	cout << "int, char constructor called; number of object: "
		<< ct << endl;
	 pc = new char[n];
	for (int i = 0; i < n; i++)
	{
		pc[i] = ch;
	}
	ShowObject();

}

Useless::Useless(const Useless& f) : n(f.n)
{
	++ct;
	const Useless* fAddress = &f;
	cout << "copy const called; number of objects: "
		<< ct << endl;
	//pc = f.pc;		//steal address
	//f.pc = nullptr;	//give old object nothing in return
	//f.n = 0;
	
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
	
	ShowObject();
}


Useless::Useless(Useless&& f) : n(f.n)
{
	++ct;
	cout << "move constructor called; number of object: "
		<< ct << endl;
	Useless* fAddress = &f;
	pc = f.pc;		//steal address
	f.pc = nullptr;	//give old object nothing in return
	f.n = 0;
	ShowObject();
}

Useless::~Useless()
{
	cout << "destructor called; object left: "
		<< --ct << endl;
	cout << "delected object:\n";
	ShowObject();

	delete[] pc;
}

Useless Useless::operator+(const Useless& f) const
{
	cout << "Entering operator+()\n";
	Useless temp = Useless(n + f.n);
	for (int i = 0; i < n; i++)
		temp.pc[i] = pc[i];
	for (int i = n; i < temp.n; i++)
		temp.pc[i] = f.pc[i - n];
	cout << "temp object:\n";
	cout << "Leaving operator+()\n";
	Useless* tempadress = &temp;
	return temp;
}

void Useless::ShowObject() const
{
	cout << "Number of elements: " << n;
	cout << " Data address: " << (void*)pc << endl;
}

Useless& Useless::operator=(const Useless& f)
{
	std::cout << "copy assignment operator called:\n";
	if (this == &f)
		return *this;
	delete[] pc;
	n = f.n;
	pc = new char[n];
	for (int i = 0; i < n; i++)
		pc[i] = f.pc[i];
	return *this;
}

Useless& Useless::operator=(Useless&& f)
{
	std::cout << "move assignment operator called:\n";
	if (this == &f)
		return *this;
	delete[] pc;
	n = f.n;
	pc = f.pc;
	f.n = 0;
	f.pc = nullptr;
	return *this;
}

void Useless::ShowData() const
{
	if (n == 0)
		cout << "(object empty)";
	else
		for (int i = 0; i < n; i++)
			cout << pc[i];
	cout << endl;
}


// application
void MoveSemanticsTest()
{
	{
		/*
		Useless one(10, 'x');
		Useless two = one;		//calls copy constructor
		Useless three(20, 'o');
		Useless four(one + three);	//calls operator+(), move constructor
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();
		cout << " object three: ";
		three.ShowData();
		cout << " object four: ";
		four.ShowData();
		*/
		Useless one(10, 'x');
		Useless two = one + one;		// calls move constructor
		cout << "object one: ";
		one.ShowData();
		cout << "object two: ";
		two.ShowData();
		Useless three, four;
		cout << "three = one\n";
		three = one;					// automatic copy assignment
		cout << "now object three = ";
		three.ShowData();
		cout << "and object one = ";
		one.ShowData();
		cout << "four = one + two\n";
		four = one + two;			// automatic move assignment
		cout << "now object four = ";
		four.ShowData();
		cout << "four = move(one)\n";
		four = std::move(one);		// forced move assignment
		cout << "now object four = ";
		four.ShowData();
		cout << "and object one = ";
		one.ShowData();

	}
}

inline double f(double tf) { return 5.0 * (tf - 32.0) / 9.0; };

void RValueTest()
{
	using namespace std;
	double tc = 21.5;
	double&& rd1 = 7.07;
	double&& rd2 = 1.8 * tc + 32.0;
	double&& rd3 = f(rd2);
	double ta = 1.8 * tc + 32.0;
	/*
	double& ld1 = 7.07;
	double& ld2 = 1.8 * tc + 32.0;
	double& ld3 = f(rd2);
	*/
	tc += 1;
	cout << " tc value and address: " << tc << ", " << &tc << endl;
	cout << " rd1 value and address: " << rd1 << ", " << &rd1 << endl;
	cout << " rd2 value and address: " << rd2 << ", " << &rd2 << endl;
	cout << " rd3 value and address: " << rd3 << ", " << &rd3 << endl;
	cout << " ta value and address: " << ta << ", " << &ta << endl;
	//cin.get();

}




