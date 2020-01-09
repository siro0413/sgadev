#pragma once

template<typename T>
class Queue
{
public:
	Queue(int capacity);

	~Queue();
	void EnQueue(T data);
	T Dequeue();
	int Size();
	int CapaCity() { return capacity; }
	int Front() { return front; }
	int Rear() { return rear; }

	bool IsFull();
	bool IsEmpty();
private:
	T* datas;

	int capacity;

	int front = 0;
	int rear = 0;
};


template<typename T>
inline Queue<T>::Queue(int capacity)
	: capacity(capacity)
{
	datas = new T[capacity];
	memset(datas, NULL, sizeof(T) * capacity);
}

template<typename T>
inline Queue<T>::~Queue()
{
	delete[] datas;
	datas = nullptr;
}

template<typename T>
inline void Queue<T>::EnQueue(T data)
{
	int position = 0;
	if (rear == capacity - 1)
	{
		position = rear;
		rear = 0;
	}
	else
		position = rear++;
	datas[position] = data;
}

template<typename T>
inline T Queue<T>::Dequeue()
{
	int position = front;
	if (front == capacity - 1)
		front = 0;
	else front++;

	return datas[position];
}

template<typename T>
inline int Queue<T>::Size()
{
	if (front <= rear)
		return rear - front;
	else
		return rear + (capacity - front) + 1;

}

template<typename T>
inline bool Queue<T>::IsFull()
{
	if (front < rear)
		return (rear - front) == (capacity - 1);
	else
		return rear + 1 == front;
}

template<typename T>
inline bool Queue<T>::IsEmpty()
{
	return front == rear;
}
