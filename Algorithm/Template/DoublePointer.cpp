#include <iostream>
#include <stdio.h>
#include <Windows.h>
using namespace std;

struct Vector2
{
	Vector2(){}
	Vector2(float x, float y)
		:x(x), y(y) {}

	float x;
	float y;
};

void Set9999(Vector2** pos)
{
	*pos = new Vector2();
	**pos = { 99.9f,99.9f };

}


int main()
{
	Vector2* monster = new Vector2(10, 20);
	Set9999(&monster);

	printf("%0.2f, %0.2f\n", monster->x, monster->y);
	delete(monster);
	system("pause");
	return 0;
}