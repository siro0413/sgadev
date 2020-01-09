#pragma once
#include <assert.h>
#include <Windows.h>

#define MAX_STACK_SIZE 5

template<typename T>
class Stack
{
public:
	Stack();
	void Push(T val);
	T Pop();
	T Front();
	T Back();
	bool Empty(); //�ٲ��´��� �Ȳ��´��� Ȯ�ο�

private:
	int top = -1; //Front�� �ε��� ��ȣ

	T values[MAX_STACK_SIZE];

};

template<typename T>
inline Stack<T>::Stack()
{
	memset(values, 0, sizeof(T) * MAX_STACK_SIZE); //�޸� ����
	//values�� ��簪�� 0���� ����
	//ZeroMemory(values,sizeof(T) * MAX_STACK_SIZE)
}

template<typename T>
inline void Stack<T>::Push(T val)
{
	assert(top + 1 < MAX_STACK_SIZE);

	values[++top] = val;
}

template<typename T>
inline T Stack<T>::Pop()
{
	bool b = Empty();
	assert(b == false);

	T val = values[top];
	top--;

	return val;
}

template<typename T>
inline T Stack<T>::Front()
{
	return values[top];
}

template<typename T>
inline T Stack<T>::Back()
{
	assert(top > -1);

	return values[0];
}

template<typename T>
inline bool Stack<T>::Empty()
{
	return top < 0 ? true : false;
}

