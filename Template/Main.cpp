#include <stdio.h>
#include "StackList.h"

void main()
{
	StackList stack;
	stack.Push(StackList::CreateNode("abc"));
	stack.Push(StackList::CreateNode("def"));
	stack.Push(StackList::CreateNode("ghi"));
	stack.Push(StackList::CreateNode("jkl"));

	int count = stack.size();
	printf("Size : %d\n", count);
	for (size_t i = 0; i < count; i++)
	{
		if (stack.IsEmpty())
			break;
		Node* temp = stack.Pop();

		printf("Pop : %s\n", temp->Data.c_str());
		stack.DestroyNode(temp);

		if (!stack.IsEmpty())
			printf("Top : %s\n", stack.Top()->Data.c_str());
		else
			printf("Top : Null");
	}

	getchar();
}