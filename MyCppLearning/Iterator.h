#pragma once
#include <windows.h>

typedef struct Node
{
	double item;
	Node* p_next;

	void fill_list(double* start, double* end);

}Node;

class Iterator
{
public:
	Iterator() : pt(nullptr) {};
	Iterator(Node* node) : pt(node) {};
	//Iterator(LPVOID listBegin);

	double operator*() { return pt->item; };

	Iterator& operator++();
	Iterator operator++(int);
	bool operator==(Iterator in);
	bool operator==(Iterator* in);
	//bool operator==(Iterator& in);
	bool operator!=(Iterator in);
	bool operator!=(int in);

public:
	Iterator find(Iterator head, const double& val);

	static void IteratorTest();
private:
	Node* pt;
};

template <typename Type>
class TIterator
{
public:
	Iterator() : pt(nullptr) {};
	Iterator(Type* node) : pt(node) {};

	Type operator*() const noexcept { return const_cast<Type>(operator*()); };

	TIterator<Type>& operator++() noexcept {
		return const_cast<Type> (operator++());
	};

private:
	Type* pt;
};
