#include <iostream>
#include <Windows.h>
using namespace std;

#include "DisjointSet.h"

#define Group DisjointSet<string>

void main()
{

	Group::Set* set1 = Group::Create("마블스");
	Group::Set* set2 = Group::Create("캡틴아메리카");
	Group::Set* set3 = Group::Create("아이언맨");
	Group::Set* set4 = Group::Create("토르");
	Group::Set* set5 = Group::Create("베트맨");

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
