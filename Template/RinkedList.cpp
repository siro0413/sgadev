#include <iostream>
#include <stdio.h>
#include <Windows.h>
using namespace std; 

typedef int DataType;

struct Node
{
	DataType Data;
	Node* NextNode; //다음주소를 가르킬 변수

};

Node* Create(DataType data)
{
	Node* node = new Node();
	node->Data = data;
	node->NextNode = nullptr;

	return node;
}

void Destroy(Node* node)
{
	delete node;
	node = nullptr;
}

void Push(Node** head, Node* node)
{
	if ((*head) == nullptr)
	{
		*head = new Node();
		(*head)->Data = node->Data;
	}
	else
	{
		Node* tail = (*head);
		while (tail->NextNode != NULL)
			tail = tail->NextNode;

		tail->NextNode = node;
	}
}
Node* GetNode(Node* head, int location)
{
	Node* current = head;
	while (current != nullptr && (--location) >= 0)
		current = current->NextNode;

	return current;
}

void Insert(Node* current, Node* node)//current -> 뒤에붙일 노드 번호, node -> 꼽사리낄애
{
	node->NextNode = current->NextNode;
	current->NextNode = node;
}

void InsertHead(Node** current, Node* head)
{
	if (*current == NULL)
	{
		*current = head;
	}
	else
	{
		head->NextNode = *current;
		*current = head;
	}
}

void Remove(Node** head, Node* remove)
{
	if (*head == remove)
	{
		*head = remove->NextNode;
	}
	else
	{
		Node* current = *head;

		while (current != nullptr && current->NextNode != remove)
			current = current->NextNode;
		if (current != nullptr)
			current->NextNode = remove->NextNode;
	}

}

int GetNodeCount(Node* head)
{
	int count = 0;
	Node* current = head;

	while (current != NULL)
	{
		current = current->NextNode;
		count++;
	}

	return count;
}

int main()
{

	Node* list = nullptr;

	for (size_t i = 0; i < 5; i++)
	{
		Node* node = Create(i);

		Push(&list, node);
	}


	//Push 결과
	{
		printf("Push Test\n");
		printf("-------------------------------\n");
		for (size_t i = 0; i < GetNodeCount(list); i++)
			printf("List[%d] = %d\n", i, GetNode(list, i)->Data);
	}

	//Insert Head
	Node* newNode = NULL;
	{
		printf("\nInsert Head Test\n");
		printf("-------------------------------\n");

		newNode = Create(-1);
		InsertHead(&list, newNode);

		newNode = Create(-2);
		InsertHead(&list, newNode);

		int count = GetNodeCount(list);
		for (size_t i = 0; i < count; i++)
			printf("List[%d] = %d\n", i, GetNode(list, i)->Data);

	}
	//Insert Node
	{
		printf("\nInsert Node Test\n");
		printf("-------------------------------\n");
		Node* current = GetNode(list, 2);

		newNode = Create(1000);

		Insert(current, newNode);
		int count = GetNodeCount(list);
		for (size_t i = 0; i < count; i++)
			printf("List[%d] = %d\n", i, GetNode(list, i)->Data);
	}
	//Remove
	{
		printf("\nReMove Node Test\n");
		printf("-------------------------------\n");
		
		int count = GetNodeCount(list);
		for (size_t i = 0; i < count; i++)
		{
			Node* current = GetNode(list, 0);
			if (current != nullptr)
			{
				Remove(&list, current);
				Destroy(current);

			}
		}
		printf("ㄹㅇ? \n");
		printf("-------------------------------\n");
		for (size_t i = 0; i < GetNodeCount(list); i++)
			printf("List[%d] = %d\n", i, GetNode(list, i)->Data);

	}

	list = nullptr;
	Node* node1 = Create(1000);
	Node* node2 = Create(2000);
	Push(&list,node1);
	Push(&list,node2);
	printf("ㄹㅇ? \n");
	printf("-------------------------------\n");
	for (size_t i = 0; i < GetNodeCount(list); i++)
		printf("List[%d] = %d\n", i, GetNode(list, i)->Data);
	system("pause");
	return 0;
}