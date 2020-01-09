#pragma once
#include <iostream>
using namespace std;
template<typename T>
class Tree
{
public:
	struct Node;

	static Node* CreateNode(T Data)
	{
		Node* node = new Node();
		node->data = Data;
		node->LeftChild = node->RightSibling = NULL;

		return node;
	};
	static void DestroyNode(Node* node);
	void AddChild(Node* parent, Node* child);

	void PrintNode(Node* node,int depth);
private:
	struct Node
	{
		T data;

		Node* LeftChild;
		Node* RightSibling;
	};
};


template<typename T>
inline void Tree<T>::DestroyNode(Node * node)
{
	delete node;
	node = NULL;
}

template<typename T>
inline void Tree<T>::AddChild(Node * parent, Node * child)
{
	if(parent->LeftChild == NULL)
	{
		parent->LeftChild = child;
	}
	else
	{
		Node* node = parent->LeftChild;

		while (node->RightSibling != NULL)
			node = node->RightSibling;

		node->RightSibling = child;
	}
}

template<typename T>
inline void Tree<T>::PrintNode(Node * node, int depth)
{
	for (size_t i = 0; i < depth; i++)
		printf("- ");
	cout << node->data << endl;

	if (node->LeftChild != NULL)
		PrintNode(node->LeftChild, depth + 1);

	if (node->RightSibling != NULL)
		PrintNode(node->RightSibling, depth);
}
