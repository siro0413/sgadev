#pragma once
#include <Windows.h>
#include <stdio.h>

//BST : 이진트리
//삽입 규칙 : root(Parent)와 비교해서 작으면 Left, 크면 Right
//삭제 규칙 : (1) 자식이 하나면, 삭제 위치에 자식을 놓는다. / (2) 자식이 둘이면 Right 그룹에서 최소값을 삭제위치에 놓는다.
template<typename T>
class Btree
{
public:
	struct Node;
	Btree() {}
	~Btree()
	{
		Destroy(root);
	}
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = node->Right = NULL;
		return node;
	}
	static void DestroyNode(Node* node);

	void Destroy(Node* node);

	void Insert(Node** parent, Node* child);

	Node* Search(Node* node, T data, int& depth)
	{
		if (node == NULL) return NULL;

		depth++;

		if (node->Data == data)
			return node;
		else if (node->Data > data)
			return Search(node->Left, data, depth);
		else if (node->Data < data)
			return Search(node->Right, data, depth);

		return NULL;
	}

	Node* SearchMinValue(Node* node)
	{
		//값을 넣으면 그 값아래 가장작은값 찾기
		if (node == NULL) return NULL;

		if (node->Left == NULL)
			return node;
		else
			return SearchMinValue(node->Left);
	}

	Node* Remove(Node* node, Node* parent, T data)
	{
		Node* remove = NULL;

		if (node == NULL) return NULL;

		if (node->Data > data)
			remove = Remove(node->Left, node, data);
		else if (node->Data < data)
			remove = Remove(node->Right, node, data);

		else
		{
			remove = node;
			if (node->Left == NULL && node->Right == NULL)
			{
				if (parent->Left == node)
					parent->Left = NULL;
				else if (parent->Right == node)
					parent->Right = NULL;
			}
			else
			{
				//자식이 2개 존재
				if (node->Left != NULL && node->Right != NULL)
				{
					Node* minNode = SearchMinValue(node->Right);//오른쪽의 제일 작은값을 minNode에저장

					minNode = Remove(node, NULL, minNode->Data);
					node->Data = minNode->Data;

					return minNode;
				}
				//자식이 1개 존재
				else
				{
					Node* temp = NULL;		//
					if (node->Left != NULL)	//
						temp = node->Left;	//
					else					//
						temp = node->Right;	//

					if (parent->Left == node)//left 와 right 비교후 각각 위치에 이동
						parent->Left = temp;
					else
						parent->Right = temp;
				}
			}

		}
		return remove;
	}

	void InOrder(Node* node, int depth);

private:
	struct Node
	{
		T Data;
		Node* Left;
		Node* Right;
	};

	Node* root;
};

template<typename T>
inline void Btree<T>::DestroyNode(Node * node)
{
	delete node;
	node = NULL;
}

template<typename T>
inline void Btree<T>::Destroy(Node * node)
{
	if (node == NULL) return;

	Destroy(node->Left);
	Destroy(node->Right);
	DestroyNode(node);
}

template<typename T>
inline void Btree<T>::Insert(Node ** parent, Node * child)
{
	if ((*parent)->Data < child->Data)
	{
		if ((*parent)->Right == NULL)
			(*parent)->Right = child;
		else
			Insert(&(*parent)->Right, child);

	}
	else if ((*parent)->Data > child->Data)
	{
		if ((*parent)->Left == NULL)
			(*parent)->Left = child;
		else
			Insert(&(*parent)->Left, child);
	}
}

template<typename T>
inline void Btree<T>::InOrder(Node * node, int depth)
{
	if (node == NULL) return;
	depth++;

	InOrder(node->Left, depth); // L
	printf("[%d]%d\n", depth, node->Data);
	InOrder(node->Right, depth);
}

