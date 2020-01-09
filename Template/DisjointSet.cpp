#include <iostream>
#include <Windows.h>
using namespace std;

#include "DisjointSet.h"

#define Group DisjointSet<string>

void main()
{

	Group::Set* set1 = Group::Create("����");
	Group::Set* set2 = Group::Create("ĸƾ�Ƹ޸�ī");
	Group::Set* set3 = Group::Create("���̾��");
	Group::Set* set4 = Group::Create("�丣");
	Group::Set* set5 = Group::Create("��Ʈ��");

	cout << (Group::FinedSet(set2) == Group::FinedSet(set4)) << endl;

	Group::UnionSet(set1, set3);

	cout << (Group::FinedSet(set1) == Group::FinedSet(set3)) << endl;

	Group::UnionSet(set2, set3);

	cout << (Group::FinedSet(set2) == Group::FinedSet(set3)) << endl;


	Group::DestroySet(set1);
	Group::DestroySet(set2);
	Group::DestroySet(set3);
	Group::DestroySet(set4);
	Group::DestroySet(set5);


	system("pause");

}
