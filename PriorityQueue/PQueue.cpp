#include <stdio.h>
#include <Windows.h>
#include <string>
using namespace std;
#include "PQueue.h"


void Print(PQueue<string>::Node* nodes, int size)
{
	for (size_t i = 0; i < size; i++)
		printf("(%d) %s / ", nodes[i].Priority, nodes[i].Data.c_str());

	printf("\n");
}

void main()
{
	PQueue<string> queue(6);

	queue.Enqueue(PQueue<string>::Node(66, "VIP �� Ŭ����"));
	queue.Enqueue(PQueue<string>::Node(34, "���� �Ұ�"));
	queue.Enqueue(PQueue<string>::Node(12, "���� ���� �Ұ�"));
	queue.Enqueue(PQueue<string>::Node(45, "���� ���� ����"));
	queue.Enqueue(PQueue<string>::Node(35, "DB ������ ���"));
	queue.Enqueue(PQueue<string>::Node(97, "ȯ�� Ŭ����"));

	Print(queue.Nodes(), queue.Size());

	PQueue<string>::Node node = queue.Dequeue();
	printf(" >> �� �� : %d, ��� ���� : %s\n", node.Priority, node.Data.c_str());
	printf("\n\n");
	Print(queue.Nodes(), queue.Size());

	node = queue.Dequeue();
	printf(" >> �� �� : %d, ��� ���� : %s\n", node.Priority, node.Data.c_str());
	printf("\n\n");
	Print(queue.Nodes(), queue.Size());



	system("pause");
}