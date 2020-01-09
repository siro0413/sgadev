#include <stdio.h>
#include <Windows.h>
#include <set>
using namespace std;

struct comp
{
	template<typename T>
	bool operator()(const T& left, const T& right)
	{
		if (left.first == right.first)
			return left.second < right.second;

		return left.first < right.first;
	}
};

void main()
{
	set<int> s1 = { 5,2,4,6,1,2 };
	for (int i : s1)
		printf(" %d ", i);

	printf("\n");

	set<pair<string, int>,comp> s2 =
	{
		{"B",4},{"E",2}, {"A",5},{"D",1},{"B",5}
	};

	for (auto& set : s2)
		printf("%s, %d\n", set.first.c_str(), set.second);

	system("pause");
}