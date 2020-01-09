#include <stdio.h>
#include "Btee.h"
#define Tree Btree<int>

void main()
{

	Tree tree;

	Tree::Node* root = Tree::CreateNode(123);

	tree.Insert(&root, Tree::CreateNode(22));
	tree.Insert(&root, Tree::CreateNode(999));
	tree.Insert(&root, Tree::CreateNode(424));
	tree.Insert(&root, Tree::CreateNode(17));
	tree.Insert(&root, Tree::CreateNode(3));
	tree.Insert(&root, Tree::CreateNode(98));
	tree.Insert(&root, Tree::CreateNode(34));
	tree.Insert(&root, Tree::CreateNode(759));
	tree.Insert(&root, Tree::CreateNode(320));
	tree.Insert(&root, Tree::CreateNode(1));
	
	tree.InOrder(root, 0);
	int depth = 0;
	Tree::Node* node = tree.Search(root, 98, depth);
	/*
			 123
		 22		  999
	  17    98   424  759 
    3    34     
  1
	*/
	printf("\n\n찾기 결과 : %d, %d 번만에 찾음 \n", node->Data, depth);
	node = tree.Remove(root, NULL, 22);
	printf("삭제할 노드 : %d\n", node->Data);
	tree.DestroyNode(node);

	printf("\n");
	tree.InOrder(root, 0);

	//삽입 테스트
	printf("\n");
	tree.Insert(&root, Tree::CreateNode(19));
	tree.InOrder(root, 0);
	system("pause");
}