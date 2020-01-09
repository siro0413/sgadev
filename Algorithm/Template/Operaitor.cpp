#include <iostream>
#include <string>

using namespace std;

#include "BTree.h"

void Expreesion(const char* postfix, bTree<char>::Node** node)
{
	char * str = const_cast<char*>(postfix);

	size_t length = strlen(str);

	char token = str[length - 1];
	str[length - 1] = '\0';

	switch (token)
	{
	case '+':case '-':case '*': case '/': case '%':
	{
		*node = bTree<char>::CreateNode(token);
		Expreesion(postfix, &(*node)->Right);
		Expreesion(postfix, &(*node)->Left);
	}
	break;

	default:
	{
		*node = bTree<char>::CreateNode(token);
	}
	break;
	}
}

float Calc(bTree<char>::Node* node)
{
	if (node == NULL) return 0;

	switch (node->Data)
	{
	case '+':case '-':case '*': case '/': case '%':
	{
		float left = Calc(node->Left);
		float right = Calc(node->Right);

		switch (node->Data)
		{
		case '+': return left + right;
		case '-': return left - right;
		case '*': return left * right;
		case '/': return left / right;
		case '%': return (int)left & (int)right;
		}
		break;
	}
	break;
	default:
	{
		char temp[4];
		memset(temp, 0, sizeof(temp));
		temp[0] = node->Data;
		return atof(temp);
	}
	break;
	}
	return 0.0f;
}


void main()
{

	bTree<char>::Node* root = NULL;

	string ex = "1 + 2 * 3 - 4";
	string postfix = "12+34-*";//1 + 2 * 3 - 4

	Expreesion(postfix.c_str(), &root); //트리로 만들어주는 함수

	//cout << ex << endl;
	cout << postfix << endl;
	bTree<char> tree;
	tree.Root(root);

	tree.PostOrder(root);
	cout << endl;
	tree.InOrder(root);
	cout << endl;
	tree.PreOrder(root);

	cout << endl;
	cout << "Cale : " << Calc(root) << endl;

	system("pause");
}