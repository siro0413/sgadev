#include <stdio.h>
#include <Windows.h>
#include <time.h>
int main()
{
	while (true)
	{

		int a;
		printf("�����µ� �Է� : ");
		scanf("%d", &a);

		printf("ȭ���µ� ��ȯ : %0.1f\n\n", 1.8 * (float)a + 32);

		float b;
		printf("ȭ���µ� �Է� : ");
		scanf("%f", &b);

		printf("�����µ� ��ȯ : %0.1f\n\n", (b - 32)/1.8);


		int num;
		printf("4�ڸ����ڸ� �Է��Ͻʽÿ� :");
		scanf("%d", &num);
		printf("1000�� �ڸ���	: %d\n", num / 1000);
		num = num % 1000;
		printf("100�� �ڸ���	: %d\n", num / 100);
		num = num % 100;
		printf("10�� �ڸ���	: %d\n", num / 10);
		num = num % 10;
		printf("1�� �ڸ���	: %d\n\n", num / 1);
		printf("3���� ȭ���� �������ϴ�.");
		Sleep(3000);
		system("cls");

	}


	//system("pause");
	return 0;
}