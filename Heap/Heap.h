#pragma once
template<typename T>
class Heap
{
public:
	struct Node
	{
		T Data;
		Node() {}
		Node(T data) { Data = data; }
	};
	Heap(int initSize)
		:capacity(initSize)
	{
		nodes = new Node[capacity];
		size = 0;
	}
	~Heap()
	{
		delete[] nodes;
		nodes = nullptr;
	}

	int Parent(int index);
	int LeftChild(int index);

	void SwapNode(int index1, int index2);

	void Insert(Node data);

	Node RemoveMin()
	{
		int parent = 0;
		int left = 0;
		int right = 0;

		Node result;
		memcpy(&result, &nodes[0], sizeof(Node));
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

				if (nodes[left].Data > nodes[right].Data)
					selected = right;
				else
					selected = left;
			}
			if (nodes[selected].Data < nodes[parent].Data)
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
private:
	Node* nodes;

	int capacity;
	int size;
};

template<typename T>
inline int Heap<T>::Parent(int index)
{
	return (int)((index - 1) / 2);
}

template<typename T>
inline int Heap<T>::LeftChild(int index)
{
	return index * 2 + 1;
}

template<typename T>
inline void Heap<T>::SwapNode(int index1, int index2)
{
	Node* temp = new Node();
	memcpy(temp, &nodes[index1], sizeof(Node));
	//temp = &nodes[index1]
	//memcpy == 주소까지 복사

	memcpy(&nodes[index1], &nodes[index2], sizeof(Node));
	memcpy(&nodes[index2], temp, sizeof(Node));

	delete temp;

}

template<typename T>
inline void Heap<T>::Insert(Node data)
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
	while (curr > 0 && nodes[curr].Data <nodes[parent].Data)
	{
		SwapNode(curr, parent);

		curr = parent;
		parent = Parent(curr);
	}

	size++;
}

template<typename T>
inline void Heap<T>::Print()
{
	for (UINT i = 0; i < size; i++)
		printf("%d ", nodes[i].Data);

	printf("\n");
}


