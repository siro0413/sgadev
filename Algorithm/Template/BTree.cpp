#include <iostream>
#include <Windows.h>
using namespace std;
#include "BTree.h"


int main()
{
	bTree<char> tree;
	bTree<char>::Node* A = tree.CreateNode('A');
	bTree<char>::Node* B = tree.CreateNode('B');
	bTree<char>::Node* C = tree.CreateNode('C');
	bTree<char>::Node* D = tree.CreateNode('D');
	bTree<char>::Node* E = tree.CreateNode('E');
	bTree<char>::Node* F = tree.CreateNode('F');
	bTree<char>::Node* G = tree.CreateNode('G');


	tree.Root(A);
	A->Left = B;

	B->Left = C;
	B->Right = D;

	A->Right = E;
	E->Left = F;
	E->Right = G;

	cout << "PreOrder" << endl;
	tree.PreOrder(A);
	cout << endl;
	cout << "InOrder" << endl;
	tree.InOrder(A);
	cout << endl;
	system("pause");
	return 0;
}