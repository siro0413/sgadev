#pragma once
template<typename T>
class PQueue
{
public:
	struct Node
	{
		T Data;
		int Priority;
		Node() {}
		Node(int priority, T data) { Data = data; Priority = priority; }
	};

	PQueue(int initSize)
		:capacity(initSize)
	{
		nodes = new Node[capacity];
		size = 0;
	}
	~PQueue()
	{
		delete[] nodes;
		nodes = nullptr;
	}

	int Parent(int index);
	int LeftChild(int index);

	void SwapNode(int index1, int index2);

	void Enqueue(Node data);

	Node Dequeue()
	{
		int parent = 0;
		int left = 0;
		int right = 0;

		Node result = nodes[0];
		//memcpy(&result, &nodes[0], sizeof(Node));
		size--;
		SwapNode(0, size);

		left = LeftChild(0);
		right = left + 1;

		//경쟁
		while (true)
		{
			int selected = 0; //L R 값이 더작은 인덱스가 저장될 변수
			if (left >= size)
				break;
			if (right >= size)
				selected = left;
			else
			{

				if (nodes[left].Priority > nodes[right].Priority)
					selected = right;
				else
					selected = left;
			}
			if (nodes[selected].Priority < nodes[parent].Priority)
				//selected 와 parent비교후 selected가 더크면 교체
			{
				SwapNode(parent, selected);
				parent = selected;
			}
			else
				break;

			left = LeftChild(parent);
			right = left + 1;

		}

		return result;
	}

	void Print();

	Node* Nodes() { return nodes;}
	auto Size() { return size; }
private:
	Node* nodes;

	int capacity;
	int size;
};

template<typename T>
inline int PQueue<T>::Parent(int index)
{
	return (int)((index - 1) / 2);
}

template<typename T>
inline int PQueue<T>::LeftChild(int index)
{
	return index * 2 + 1;
}

template<typename T>
inline void PQueue<T>::SwapNode(int index1, int index2)
{
	//Node* temp = new Node();
	//memcpy(temp, &nodes[index1], sizeof(Node));
	////temp = &nodes[index1]
	////memcpy == 주소까지 복사

	//memcpy(&nodes[index1], &nodes[index2], sizeof(Node));
	//memcpy(&nodes[index2], temp, sizeof(Node));

	//delete temp;

	swap(nodes[index1], nodes[index2]);
}

template<typename T>
inline void PQueue<T>::Enqueue(Node data)
{
	int curr = size;
	int parent = Parent(curr);

	if (size == capacity)
	{
		Node* temp = new Node[capacity * 2];
		memcpy(temp, nodes, sizeof(Node) * capacity);

		delete[] nodes;
		nodes = temp;

		capacity *= 2;
	}
	nodes[curr] = data;

	//경쟁
	while (curr > 0 && nodes[curr].Priority < nodes[parent].Priority)
	{
		SwapNode(curr, parent);

		curr = parent;
		parent = Parent(curr);
	}

	size++;
}

template<typename T>
inline void PQueue<T>::Print()
{
	for (UINT i = 0; i < size; i++)
		printf("%d ", nodes[i].Data);

	printf("\n");
}


