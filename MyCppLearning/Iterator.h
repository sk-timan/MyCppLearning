#pragma once
#include <windows.h>
#include <vector>

#define NUM_ARR 6

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
class TNode
{
public:
	using value_type		= Type;
	using Next				= TNode<value_type>*;
	using pointer			= value_type*;
	using const_pointer		= const pointer;
	using reference			= value_type&;
	using const_reference	= const value_type&;

	const_reference operator*() const noexcept {
		return value;
	};

	reference operator++() noexcept {
		value++;
		return value;
	};

	value_type operator++(int) noexcept {
		value_type temp = value;
		++value;
		return temp;
	};


	bool operator==(const TNode& in) noexcept {
		return value == in.value;
	}
	
	//bool operator!=(Iterator in);
	//bool operator!=(int in);

	void fill_list(pointer start, pointer end)
	{
		if (start != end)
		{
			this->value = *start;
			Next nextNode = new TNode<Type>;
			this->p_next = nextNode;

			nextNode->fill_list(start + 1, end);
		}
		else
		{
			this->value = *start;
			this->p_next = nullptr;
		}
	}

public:
	value_type value;
	Next p_next;
};


template <class _Type>
class TIterator
{
public:
	using value_type	= typename _Type::value_type;
	using pointer		= typename _Type::pointer;
	using const_pointer = const pointer;
	using reference		= value_type&;
	using const_reference = const value_type&;

	TIterator() : pt(nullptr) {};
	TIterator(_Type* node) : pt(node) {};

	const_reference operator*() const noexcept {
		return **pt;
	};

	TIterator& operator++() noexcept {
		pt = pt->_Type::p_next;
		return *this;
	};

	TIterator operator++(int) noexcept {
		TIterator tmp = *this;
		pt = pt->_Type::p_next;
		return tmp;
	}

	bool operator == (const TIterator& in) noexcept {
		if (in.pt == nullptr && pt == nullptr)
			return true;
		else if (in.pt != nullptr && pt == nullptr || in.pt == nullptr && pt != nullptr)
			return false;
		else
			return pt->_Type::value == in.pt->_Type::value;
	}

	bool operator != (const TIterator& in) noexcept {
		return !(*this == in);
	}

private:
	_Type* pt;
};

static void TIteratorTestFunc()
{
	double list[NUM_ARR] = { 1.1,1.9,1.2,1.3,1.4,1.5 };
	TNode<double> Nodes_1;
	Nodes_1.fill_list(&list[0], &list[NUM_ARR - 1]);
	TIterator iterator(&Nodes_1);

	for (iterator; iterator != nullptr; iterator++)
	{
		cout << *iterator << endl;
	}

}