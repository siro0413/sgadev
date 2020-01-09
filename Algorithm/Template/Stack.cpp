#include "stack.h"
#include <iostream>

using namespace std;
void main()
{
	Stack<int> stack;

	stack.Push(10);
	stack.Push(8);

	cout << "Out put(Pop) : " << stack.Pop() << endl;
	stack.Push(12);
	stack.Push(20);
	stack.Pop();
	stack.Push(4);
	cout << "Out put(Front) : " << stack.Front() << endl;
	cout << "Out put(Back) : " << stack.Back() << endl;
	cout << "--------------------------------------" << endl;

	while (!stack.Empty())
	{
		cout << "All Out Put : " << stack.Pop() << endl;

	}
	system("pause");
}