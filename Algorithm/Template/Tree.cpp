#include <stdio.h>
#include <Windows.h>
#include "Tree.h"


void main()
{
	Tree<char> tree;
	Tree<char>::Node* Root = Tree<char>::CreateNode('A');

	Tree<char>::Node* NodeB = Tree<char>::CreateNode('B');
	Tree<char>::Node* NodeC = Tree<char>::CreateNode('C');
	Tree<char>::Node* NodeD = Tree<char>::CreateNode('D');
	Tree<char>::Node* NodeE = Tree<char>::CreateNode('E');
	Tree<char>::Node* NodeF = Tree<char>::CreateNode('F');
	Tree<char>::Node* NodeG = Tree<char>::CreateNode('G');
	Tree<char>::Node* NodeH = Tree<char>::CreateNode('H');
	Tree<char>::Node* NodeI = Tree<char>::CreateNode('I');
	Tree<char>::Node* NodeJ = Tree<char>::CreateNode('J');
	Tree<char>::Node* NodeK = Tree<char>::CreateNode('K');

	tree.AddChild(Root, NodeB);
	tree.AddChild(NodeB, NodeC);
	tree.AddChild(NodeB, NodeD);
	tree.AddChild(NodeD, NodeE);
	tree.AddChild(NodeD, NodeF);
	tree.AddChild(Root, NodeG);
	tree.AddChild(NodeG, NodeH);
	tree.AddChild(NodeG, NodeI);
	tree.AddChild(NodeI, NodeJ);
	tree.AddChild(NodeI, NodeK);
	

	tree.PrintNode(Root, 0);

	printf("\n\n");

	tree.PrintNode(NodeB, 0);

	system("pause");
}