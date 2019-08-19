#include "stdafx.h"

int main()
{
	int player;
	int com;
	srand((unsigned)time(NULL));
	while (true)
	{

		printf("1_바위 2_가위 3_보 4_종료\n");
		printf("가위바위보를 입력하시오 : ");
		scanf("%d", &player);
		com = rand() % 3+ 1;
		if (player >0 && player <4)
		{
			printf("\n컴퓨터 : %s\n", (com == 1 ? "바위" : com == 2 ? "가위" : "보"));
			printf("player : %s\n", (player == 1 ? "바위\n" : player == 2 ? "가위\n" : "보\n"));

		}
		if (com == player)
		{
			printf("비김\n\n");
			Sleep(1000);
			system("cls");
		}
		else if (com == 1 && player == 2 || com == 2 && player == 3 || com == 3 && player == 1)
		{
			printf("you loser\n\n");
			Sleep(1000);
			system("cls");
		}
		else if (com == 1 && player == 3 || com == 2 && player == 1 || com == 3 && player == 2)
		{
			printf("you winner\n\n");
			Sleep(1000);
			system("cls");
		}
		else if (player == 4)
		{
			printf("종료\n");
			break;
		}




	}


	
	return 0;

}