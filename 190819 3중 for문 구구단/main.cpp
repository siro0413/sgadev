#include "stdafx.h"
using namespace std;

int main()
{

	for (int i = 1; i < 9; i += 3)
	{
		for (int j = 1; j <= 9; ++j)
		{
			for (int k = i; k <= i + 2; k++)
				cout << "" << k << " * " << "" << j << " = " << k * j<<"\t";
			cout << endl;
		}
		cout << endl;

	}
}




