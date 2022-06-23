#include "pch.h"
#include "Iterator.h"
#include <vector>

#define NUM_ARR 6

Iterator& Iterator::operator++()
{
	pt = pt->p_next;
	return *this;
}

Iterator Iterator::operator++(int)
{
	Iterator tmp = *this;
	pt = pt->p_next;
	return tmp;
}

bool Iterator::operator==(Iterator in)
{
	if (in.pt == nullptr && pt == nullptr)
		return true;
	else if (in.pt != nullptr && pt == nullptr || in.pt == nullptr && pt != nullptr)
		return false;
	else
		return pt->item == in.pt->item;
}

bool Iterator::operator==(Iterator* in)
{
	return (this == in);
}

//bool Iterator::operator==(Iterator& in)
//{
//	return (this == &in);
//}

bool Iterator::operator!=(Iterator in)
{
	return !(*this == in);
}

bool Iterator::operator!=(int in)
{
	return this->pt->item != in;
}

Iterator Iterator::find(Iterator head, const double& val)
{
	Iterator start;
	for (start = head; start != 0; start++)
	{
		if (*start == val)
			return start;
	}
	return 0;
}

void Iterator::IteratorTest()
{
	double list[NUM_ARR] = { 1.0,1.9,1.2,1.3,1.4,1.5 };
	Node nodes;
	nodes.fill_list(list, &list[NUM_ARR - 1]);

	Iterator iter;
	for (iter = &nodes; iter != nullptr; iter++)
	{
		cout << *iter << endl;
	}

	cout << *iter.find(&nodes, list[1]) << endl;
}

void Node::fill_list(double* start, double* end)
{
	if (start != end)
	{
		this->item = *start;
		Node* nextNode = new Node();
		this->p_next = nextNode;

		nextNode->fill_list(start + 1, end);

	}
	else
	{
		this->item = *start;
		this->p_next = nullptr;
	}
}
