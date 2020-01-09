#include "StackList.h"

StackList::StackList()
{
}

StackList::~StackList()
{
	while (!IsEmpty()) 
		DestroyNode(Pop());
	list = nullptr;
	top = nullptr;
}

void StackList::Push(Node * node)
{
	if (list == NULL)
	{
		list = node;
	}
	else
	{
		Node * tail = list;
		while (tail->NextNode != NULL)
			tail = tail->NextNode;
		tail->NextNode = node;
	}

	top = node;
	 
}

Node * StackList::Pop()
{
	Node* temp = top;

	if (list == top)
	{
		list = nullptr;
		top = nullptr;
	}
	else
	{
		Node* tail = list;
		while (tail != NULL && tail->NextNode != top)
			tail = tail->NextNode;

		top = tail;
		tail->NextNode = NULL;
	}
	return temp;
}

int StackList::size()
{
	int count = 0;
	Node* current = list;

	while (current != nullptr)
	{
		current = current->NextNode;
		count++;
	}
	return count;
}

Node * StackList::CreateNode(string data)
{
	Node* node = new Node();
	node->Data = data;
	node->NextNode = nullptr;

	return node;

}

void StackList::DestroyNode(Node * node)
{
	delete node;
	node = nullptr;
}
