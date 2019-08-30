#pragma once
#include "stdafx.h"
using namespace std;

int Baseball()
{

	//com && player
	int com[10] = { 0,1,2,3,4,5,6,7,8,9 };
	int player[3];
	int input;
	//Game
	int Strike = 0;
	int Ball = 0;
	bool bContine = true;

	//Random
	srand((unsigned)time(NULL));

	//computer number Shuffle
	for (int i = 0; i < 100; i++)
	{
		int src = rand() % 10;
		int dst = rand() % 10;

		int temp = com[src];
		com[src] = com[dst];
		com[dst] = temp;
	}


	while (bContine)
	{
		if ((GetAsyncKeyState(VK_ESCAPE) & 0x8000))
		{
			break;
		}
		system("cls");
		cout << "----------------------------" << endl;
		cout << endl << endl << endl;
		cout << "----------------------------" << endl;

		cout << "숫자 입력 : ";
		cin >> input;
		if (input == 4)
		{
			system("cls");
			break;
		}
		player[0] = input / 100;
		player[1] = input % 100 / 10;
		player[2] = input % 10;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (player[i] == com[j])
				{
					if (i == j) Strike++;
					else Ball++;
				}
			}
		}
		COORD pos;
		pos.X = 0;
		pos.Y = 1;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

		cout << "Strike : " << Strike << endl;
		cout << "Ball : " << Ball << endl;
		cout << "Out : " << 3 - Strike - Ball << endl;
		cout << "----------------------------" << endl;


		Sleep(1000);
		if (Strike == 3)
			bContine = false;

		Strike = 0;
		Ball = 0;


		

	}

	system("pause");
	return 0;
}




