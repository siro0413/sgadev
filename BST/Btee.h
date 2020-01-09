#pragma once
#include <Windows.h>
#include <stdio.h>

//BST : ����Ʈ��
//���� ��Ģ : root(Parent)�� ���ؼ� ������ Left, ũ�� Right
//���� ��Ģ : (1) �ڽ��� �ϳ���, ���� ��ġ�� �ڽ��� ���´�. / (2) �ڽ��� ���̸� Right �׷쿡�� �ּҰ��� ������ġ�� ���´�.
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
		//���� ������ �� ���Ʒ� ���������� ã��
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
				//�ڽ��� 2�� ����
				if (node->Left != NULL && node->Right != NULL)
				{
					Node* minNode = SearchMinValue(node->Right);//�������� ���� �������� minNode������

					minNode = Remove(node, NULL, minNode->Data);
					node->Data = minNode->Data;

					return minNode;
				}
				//�ڽ��� 1�� ����
				else
				{
					Node* temp = NULL;		//
					if (node->Left != NULL)	//
						temp = node->Left;	//
					else					//
						temp = node->Right;	//

					if (parent->Left == node)//left �� right ���� ���� ��ġ�� �̵�
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

