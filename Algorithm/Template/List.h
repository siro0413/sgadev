#pragma once

template<typename T>
class List
{
public:
	struct Node;

	~List();
	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Next = nullptr;
		return node;
	}
	static void DestroyNode(Node* node)
	{
		delete node;
		node = nullptr;
	}

	void EnList(Node* node);
	bool IsEnpty();

	Node* Dequeue()
	{
		Node* node = front;
		if (front->Next == nullptr)
			front = rear = nullptr;
		else
			front = front->Next;

		count--;
		return node;
	}

	int Count() { return count; }
private:
	struct Node
	{
		T Data;
		Node* Next;
	};

	Node* front = nullptr;
	Node* rear = nullptr;
	int count = 0;

};

template<typename T>
inline List<T>::~List()
{
	while (!IsEnpty())
		DestroyNode(Dequeue());
}

template<typename T>
inline void List<T>::EnList(Node * node)
{
	if (front == nullptr)
	{
		front = node;
		rear = node;

		count++;
		return;
	}
	//else���Ƚᵵ ����ȿ�� �� if�� return�� �ɾ����
	rear->Next = node;
	rear = node;
	count++;
}

template<typename T>
inline bool List<T>::IsEnpty()
{
	return front = nullptr;
}

