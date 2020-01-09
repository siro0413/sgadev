#include <stdio.h>
#include <Windows.h>
#include "CircularQueue.h"

int main()
{

	Queue<int> queue(10);
	queue.EnQueue(1);
	queue.EnQueue(2);
	queue.EnQueue(3);
	queue.EnQueue(4);

	printf("Capacity : %d, size : %d\n\n", queue.CapaCity(), queue.Size());

	for (size_t i = 0; i < 3; i++)
	{
		printf("Out : %d ", queue.Dequeue());
		printf("[F] : %d, [R] : %d\n", queue.Front(), queue.Rear());
	}
	printf("3°³²¨³¿ -- [C] : %d, [S] : %d\n\n", queue.CapaCity(), queue.Size());

	queue.EnQueue(91);
	queue.EnQueue(92);
	queue.EnQueue(93);
	queue.EnQueue(94);
	queue.EnQueue(95);

	printf("New EnQueue : [F] : %d, [R] : %d\n", queue.Front(), queue.Rear());

	int count = 100;
	while (!queue.IsFull())
	{
		queue.EnQueue(count++);
	}
	printf("----------------------<Full>----------------------\n");
	printf("[F] : %d, [R] : %d\n", queue.Front(), queue.Rear());

	while (!queue.IsEmpty())
	{
		printf("Out : %d j\t", queue.Dequeue());
		printf("[F] : %d \t[R] : %d\n", queue.Front(), queue.Rear());
	}
	system("pause");
	return 0;
}