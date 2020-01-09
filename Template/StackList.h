#pragma once
#include <Windows.h>
#include <string>
using namespace std;

struct Node
{
	string Data;
	Node* NextNode;
};

class StackList
{
public:
	StackList();
	~StackList();

	void Push(Node* node);
	Node* Pop();

	Node* Top() { return top; }
	int size();
	bool IsEmpty() { return list = nullptr; }

	static Node* CreateNode(string data);
	static void DestroyNode(Node* node);


private:
	Node* list = NULL;
	Node* top = NULL; //tail
	//list¿¡¼­ NextNode == tail

};

