#include "stdafx.h"

enum E_STAT { E_NONE, E_HIGH, E_LOW, E_SEVEN = 7 };


int main()
{
	int card[4][13];
	int shape;
	int num;
	int count = 0;
	int input;

	int money = 10'000;
	int batting;

	srand((unsigned)time(NULL));
	//reset
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			card[i][j] = count;
			count++;
		}
	}

	//shuffle
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 13; j++)
		{
			int src2 = rand() % 4;
			int src1 = rand() % 4;
			int dst1 = rand() % 13;
			int dst2 = rand() % 13;
			int temp = card[src1][dst1];
			card[src1][dst1] = card[src2][dst2];
			card[src2][dst2] = temp;

		}
	}



	//reset number -> making number shape
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			shape = card[j][i] / 13;
			num = card[j][i] % 13;

			if (j==3)
			{
				cout << "[?]";
				continue;
			}

			switch (shape)
			{
			case 0: cout << "♠";
				break;
			case 1: cout << "♣";
				break;
			case 2: cout << "♥";
				break;
			case 3: cout << "◆";
				break;
			}

			switch (num)
			{
			case 0: cout << "A\t";
				break;
			case 10:cout << "J\t";
				break;
			case 11:cout << "Q\t";
				break;
			case 12:cout << "K\t";
				break;

			default: cout << num + 1 << "\t"; break;
			}
		}//for (int j = 0; j < 13; j++)
		cout << endl;
		cout << "=========================================" << endl;
		cout << "Your Money : " << money << endl;
		cout << "High(1), Low(2), Seven(7) : ";
		cin >> input;

		cout << "Batting your money : ";
		cin >> batting;

		while (batting <1000)
		{
			cout << "Up batting 1,000$" << endl;
			cout << "Batting your money : ";
			cin >> batting;
		}


		if (input == E_SEVEN)
		{
			cout << "choice Seven";
			batting *= 2;
			cout << endl;
			cout << batting << " Batting!" << endl;
		}

		//High 조건
		if (num + 1 > 6)
		{
			if (input == E_SEVEN && num + 1 == 7)
			{
				cout << "Seven(" << num + 1 << ")" << endl;
				money += batting;
			}

			else if (input == E_HIGH)
			{
				cout << "정답(" << num + 1 << ")" << endl;
				money += batting;
			}
			else
			{
				cout << "오답(" << num + 1 << ")" << endl;
				money -= batting;
			}

		}

		if (num + 1 < 7)
		{
			if (input == E_LOW)
			{
				cout << "정답(" << num + 1 << ")" << endl;
				money += batting;
			}
			else
			{
				cout << "오답(" << num + 1 << ")" << endl;
				money -= batting;
			}
		}
		


		//all batting lose your money
		if (money <= 0)
		{
			cout << "ALL loes your Money " << endl;
			Sleep(1000);
			return 0;
		}
		Sleep(2000);
		system("cls");

	}
	cout << "All card lose " << endl;
	cout << "Now your money : " << money << endl;

	system("pause");
	return 0;
}







