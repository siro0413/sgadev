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
	bool Empty(); //다꺼냈는지 안꺼냈는지 확인용

private:
	int top = -1; //Front의 인덱스 번호

	T values[MAX_STACK_SIZE];

};

template<typename T>
inline Stack<T>::Stack()
{
	memset(values, 0, sizeof(T) * MAX_STACK_SIZE); //메모리 복사
	//values의 모든값을 0으로 설정
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

