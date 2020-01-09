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

	queue.Enqueue(PQueue<string>::Node(66, "VIP 고객 클레임"));
	queue.Enqueue(PQueue<string>::Node(34, "결제 불가"));
	queue.Enqueue(PQueue<string>::Node(12, "서버 접속 불가"));
	queue.Enqueue(PQueue<string>::Node(45, "개인 정보 노출"));
	queue.Enqueue(PQueue<string>::Node(35, "DB 데이터 장애"));
	queue.Enqueue(PQueue<string>::Node(97, "환불 클레임"));

	Print(queue.Nodes(), queue.Size());

	PQueue<string>::Node node = queue.Dequeue();
	printf(" >> 할 일 : %d, 장애 구분 : %s\n", node.Priority, node.Data.c_str());
	printf("\n\n");
	Print(queue.Nodes(), queue.Size());

	node = queue.Dequeue();
	printf(" >> 할 일 : %d, 장애 구분 : %s\n", node.Priority, node.Data.c_str());
	printf("\n\n");
	Print(queue.Nodes(), queue.Size());



	system("pause");
}