#include "stdafx.h"
using namespace std;

int main()
{
	int input[3];
	int com[9] = { 1,2,3,4,5,6,7,8,9 };
	srand((unsigned)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		int src = rand() % 10;
		int dst = rand() % 10;
		int kfc = rand() % 10;
				
		int temp = com[src];
		com[src] = com[dst];
		com[dst] = temp;				

	}

	while (true)
	{
		cout << "숫자 3자리 입력하십시요" << endl;
		cin >> input[0] >> input[1] >> input[2];

		//3Strike
		if (com[0] == input[0] && com[1] == input[1] && com[2] == input[2])
		{
			cout << "3Strike" << endl;
			cout << "Clear!" << endl << endl;

			cout << "정답은 : " << com[0] << "," << com[1] << "," << com[2] << endl;
			Sleep(2000);
			system("cls");
		}
		//2Strike 1Out
		else if (com[0] == input[0] && com[1] == input[1] && (com[2] > input[2] || com[2] < input[2])) //2번틀림
			cout << "2Strike 1Out" << endl;
		else if (com[0] == input[0] && com[2] == input[2] && (com[1] > input[1] || com[1] < input[1])) //1번틀림
			cout << "2Strike 1Out" << endl;
		else if (com[2] == input[2] && com[1] == input[1] && (com[0] > input[0] || com[0] < input[0])) //0번틀림
			cout << "2Strike 1Out" << endl;
		//1Strike 2Ball
		//00 12 21 , 01 10 21 , 02 11 20
		else if (com[0] == input[0] && com[1] == input[2] && com[2] == input[1])
			cout << "1Strike 2Ball" << endl;
		else if (com[0] == input[1] && com[1] == input[0] && com[2] == input[2])
			cout << "1Strike 2Ball" << endl;
		else if (com[0] == input[2] && com[1] == input[1] && com[2] == input[0])
			cout << "1Strike 2Ball" << endl;
		//1Strike 1Ball 1Out
		//00 1x 21
		else if (com[0] == input[0] && com[1] == input[2] && (com[2] > input[2] || com[2] < input[2]))
			cout << "1Strike 1Ball 1Out" << endl;
		else if (com[0] == input[0] && (com[1] > input[1] || com[1] < input[1]) && com[2] == input[1])
			cout << "1Strike 1Ball 1Out" << endl;
		else if (com[0] == input[1] && (com[1] > input[1] || com[1] < input[1]) && com[2] == input[2])
			cout << "1Strike 1Ball 1Out" << endl;
		else if (com[0] == input[2] && com[1] == input[1] && (com[2] > input[2] || com[2] < input[2]))
			cout << "1Strike 1Ball 1Out" << endl;
		else if ((com[0] > input[0] || com[0] < input[0]) && com[1] == input[1] && com[2] == input[0])
			cout << "1Strike 1Ball 1Out" << endl;
		else if ((com[0] > input[0] || com[0] < input[0]) && com[1] == input[0] && com[2] == input[2])
			cout << "1Strike 1Ball 1Out" << endl;
		//1Strike 2Ball
		else if (com[0] == input[0] && com[1] == input[2] && com[2] == input[1])
			cout << "1Strike 2Ball" << endl;
		else if (com[0] == input[1] && com[1] == input[0] && com[2] == input[2])
			cout << "1Strike 2Ball" << endl;
		else if (com[0] == input[2] && com[1] == input[1] && com[2] == input[0])
			cout << "1Strike 2Ball" << endl;
		//1Strike 2Out
		else if (com[0] == input[0] && (com[1] > input[1] || com[1] < input[1]) && (com[2] > input[2] || com[2] < input[2]))
			cout << "1Strike 2Out" << endl;
		else if (com[1] == input[1] && (com[0] > input[0] || com[0] < input[0]) && (com[2] > input[2] || com[2] < input[2]))
			cout << "1Strike 2Out" << endl;
		else if (com[2] == input[2] && (com[1] > input[1] || com[1] < input[1]) && (com[0] > input[0] || com[0] < input[0]))
			cout << "1Strike 2Out" << endl;
		//3Ball
		else if (com[0] == input[1] && com[1] == input[2] && com[2] == input[0])
			cout << "3Ball" << endl;
		else if (com[0] == input[2] && com[1] == input[0] && com[2] == input[1])
			cout << "3Ball" << endl;
		//2Ball 1Out
		else if (com[0] == input[1] && com[1] == input[0] && (com[2] > input[2] || com[2] < input[2]))
			cout << "2Ball 1Out" << endl;
		else if (com[0] == input[2] && com[2] == input[0] && (com[1] > input[1] || com[1] < input[1]))
			cout << "2Ball 1Out" << endl;
		else if (com[2] == input[1] && com[1] == input[2] && (com[0] > input[0] || com[0] < input[0]))
			cout << "2Ball 1Out" << endl;
		//1Ball 2Out
		else if (com[0] == input[1] && (com[1] > input[1] || com[1] < input[1]) && (com[2] > input[2] || com[2] < input[2]))
			cout << "1Ball 2Out" << endl;
		else if (com[0] == input[2] && (com[1] > input[1] || com[1] < input[1]) && (com[2] > input[2] || com[2] < input[2]))
			cout << "1Ball 2Out" << endl;
		else if (com[1] == input[2] && (com[0] > input[0] || com[0] < input[0]) && (com[2] > input[2] || com[2] < input[2]))
			cout << "1Ball 2Out" << endl;
		else if (com[1] == input[0] && (com[0] > input[0] || com[0] < input[0]) && (com[2] > input[2] || com[2] < input[2]))
			cout << "1Ball 2Out" << endl;
		else if (com[2] == input[1] && (com[1] > input[1] || com[1] < input[1]) && (com[0] > input[0] || com[0] < input[0]))
			cout << "1Ball 2Out" << endl;
		else if (com[2] == input[0] && (com[1] > input[1] || com[1] < input[1]) && (com[0] > input[0] || com[0] < input[0]))
			cout << "1Ball 2Out" << endl;

		//3Out
		else cout << "3Out" << endl;


		


	}

	system("pause");
	return 0;
}

//--------------------------------방법2
#include "stdafx.h"
using namespace std;

int main()
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
		system("cls");
		cout << "chet : " << com[0] << com[1] << com[2] << endl;
		cout << "----------------------------" << endl;
		cout << endl << endl << endl;
		cout << "----------------------------" << endl;

		cout << "숫자 입력 : ";
		cin >> input;

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
		pos.Y = 2;
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






