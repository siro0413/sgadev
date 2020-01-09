#pragma once


template<typename T>
class bTree
{
public:
	struct Node;

	bTree() {};
	~bTree();

	static Node* CreateNode(T data)
	{
		Node* node = new Node();
		node->Data = data;
		node->Left = node->Right = NULL;
		
		return node;
	};
	static void DestroyNode(Node* node);
	void PreOrder(Node* node);
	void InOrder(Node* node);
	void PostOrder(Node* node);
	void Root(Node* node) { root = node; }

	void Destroy(Node* node);//트리 전체파괴


private:
	struct Node
	{
		T Data;
		Node* Left;
		Node* Right;
	};


	Node* root;
};

template<typename T>
inline bTree<T>::~bTree()
{
	Destroy(root);
}

template<typename T>
inline void bTree<T>::DestroyNode(Node * node)
{
	delete node;
	node = NULL;
}

template<typename T>
inline void bTree<T>::PreOrder(Node * node)
{
	if (node == NULL)return;

	cout << " " << node->Data;	//Root
	PreOrder(node->Left);		//L
	PreOrder(node->Right);		//R


}

template<typename T>
inline void bTree<T>::InOrder(Node * node)
{
	if (node == NULL) return;

	InOrder(node->Left);
	cout << " " << node->Data;
	InOrder(node->Right);
}

template<typename T>
inline void bTree<T>::PostOrder(Node * node)
{
	if (node == NULL) return;

	InOrder(node->Left);
	InOrder(node->Right);
	cout << " " << node->Data;
}

template<typename T>
inline void bTree<T>::Destroy(Node * node)
{
	if (node == NULL)return;

	Destroy(node->Left);
	Destroy(node->Right);
	DestroyNode(node);
}
