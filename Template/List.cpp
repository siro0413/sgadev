#include <stdio.h>
#include <Windows.h>
#include "List.h"

int main()
{
	List<int> list;
	list.EnList(List<int>::CreateNode(10));
	list.EnList(List<int>::CreateNode(20));
	list.EnList(List<int>::CreateNode(30));
	list.EnList(List<int>::CreateNode(40));

	printf("Size : %d\n", list.Count());
	while (!list.IsEnpty())
	{
		List<int>::Node* node = list.Dequeue();
		printf("Out : %d\n", node->Data);
		List<int>::DestroyNode(node);
	}

	system("pause");
	return 0;
}