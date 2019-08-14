#include <stdio.h>
#include <Windows.h>
#include <time.h>
int main()
{
	while (true)
	{

		int a;
		printf("섭씨온도 입력 : ");
		scanf("%d", &a);

		printf("화씨온도 변환 : %0.1f\n\n", 1.8 * (float)a + 32);

		float b;
		printf("화씨온도 입력 : ");
		scanf("%f", &b);

		printf("섭씨온도 변환 : %0.1f\n\n", (b - 32)/1.8);


		int num;
		printf("4자리숫자를 입력하십시오 :");
		scanf("%d", &num);
		printf("1000의 자리수	: %d\n", num / 1000);
		num = num % 1000;
		printf("100의 자리수	: %d\n", num / 100);
		num = num % 100;
		printf("10의 자리수	: %d\n", num / 10);
		num = num % 10;
		printf("1의 자리수	: %d\n\n", num / 1);
		printf("3초후 화면이 지워집니다.");
		Sleep(3000);
		system("cls");

	}


	//system("pause");
	return 0;
}