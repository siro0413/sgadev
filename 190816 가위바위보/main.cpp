#include "stdafx.h"

int main()
{
	int player;
	int com;
	srand((unsigned)time(NULL));
	while (true)
	{

		printf("1_���� 2_���� 3_�� 4_����\n");
		printf("������������ �Է��Ͻÿ� : ");
		scanf("%d", &player);
		com = rand() % 3+ 1;
		if (player >0 && player <4)
		{
			printf("\n��ǻ�� : %s\n", (com == 1 ? "����" : com == 2 ? "����" : "��"));
			printf("player : %s\n", (player == 1 ? "����\n" : player == 2 ? "����\n" : "��\n"));

		}
		if (com == player)
		{
			printf("���\n\n");
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
			printf("����\n");
			break;
		}




	}


	
	return 0;

}