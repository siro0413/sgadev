#include "stdafx.h"
using namespace std;

/*
하이 로우 세븐
1. 컴퓨터가 52장의 카드 중에서 4장을 뽑아서
2. 배팅 금액 입력
3. 하이 ,로우, 세븐  선택
4. 카드를 모두 소진하면 게임 끝
5. 내가 보유하고 있는 금액이 0 이 되면 게임 끝->파산
*/

void main()
{

	int card[52];//카드 변수 선언
	int cardNum = 52;//카드 갯수
	int select;//하이 로우 세븐인지 선택
	int money;//소지금
	int batting;//배팅할 돈
	int count;//게임 횟수
	int openCard = 4;//열어볼 카드 갯수
	int maxGamePlay = cardNum / openCard;//플레이 횟수(카드 소진시 게임 종료)




	//카드 값 지정
	for (int i = 0; i < cardNum; i++)
	{

		card[i] = i + 1;

	}


	//셔플

	srand(time(NULL));



	for (int i = 0; i < 1000; i++)
	{

		int dest = rand() % cardNum;
		int sour = rand() % cardNum;


		int temp = card[dest];
		card[dest] = card[sour];
		card[sour] = temp;

	}

	money = 5'000;//초기자금 10000원
	count = 0;

	//게임 플레이
	while (true)
	{


		for (int i = 0; i < 4; i++)//꺼낼카드 4장
		{
			//cout << card[4 * count +i] << "\t";//?

			//A,2,3,4,5,6,7,8,9,10,J,Q,K

			int number = card[4 * count + i] % 13;
			int shape = card[4 * count + i] / 13;



			//♠◆♥♣문양

			if (i == 3)//4번째 카드 숨김처리
			{
				cout << "◎";
				continue;
			}

			switch (shape)
			{
			case 0:
				cout << "♠";

				break;
			case 1:
				cout << "◆";
				break;
			case 2:
				cout << "♥";
				break;
			case 3:
				cout << "♣";
				break;

			}


			switch (number)
			{
			case 0:
				cout << "A\t";

				break;
			case 10:
				cout << "J\t";
				break;
			case 11:
				cout << "Q\t";
				break;
			case 12:
				cout << "K\t";
				break;
			default:
				cout << number + 1 << "\t";
				break;

				//실제 데이터랑 화면 출력하는 데이터는 다를 수 있다.
				//예를들어 체력 바는 숫자로 움직이지만, 실제 출력은  이미지인것처럼

			}

		}
		cout << endl;

		int number = card[4 * count + 3] % 13;

		cout << endl << "남은 카드 갯수 :" << cardNum - (count*openCard) << endl;

		cout << "My Money : " << money << "원" << endl;
		cout << "" << endl;
		cout << "Betting Your Moeny : ";
		cin >> batting;

		if (batting > money)
		{
			cout << "Over betting your money." << endl;


			Sleep(2000);

			system("cls");

			continue;



		}
		//하이 로우 세븐

		int score = -1;
		bool bcheck;
		cout << "----------------------------------------------------------------" << endl;
		cout << "High,Low : Betting money " << endl;
		cout << "Seven : Betting money sextuple " << endl ;
		cout << "----------------------------------------------------------------" << endl;
		cout << "High : 1, Low : 2, Seven : 3 " << endl;
		cout << "choice Number : ";
		cin >> select;
		printf("Plyaer : %s\n", (select == 1 ? "High" : select == 2 ? "Low" : "Seven"));



		if (select == 1)
		{
			if (number > 7)
			{
				score = 1;
				bcheck = true;
			}
			else
			{
				score = -1;
				bcheck = false;
			}
		}

		if (select == 2)//로우 선택
		{
			if (number < 7)
			{
				score = 1;
				bcheck = true;
			}
			else
			{
				score = -1;
				bcheck = false;
			}
		}
		if (select == 3)//세븐 선택
		{
			if (number == 7)
			{
				score = 6;
				bcheck = true;


			}
			else
			{
				score = -6;
				bcheck = false;

			}
		}


		printf("Answer : %s\n", (number > 7 ? "High" : number < 7 ? "Low" : "Seven"));
		cout << endl;

		int benefit = (batting*(score * 1));//괄호 조심


		if (bcheck == 1)
		{

			cout << "Bingo! " << endl;
			cout << benefit << "원 acquire  " << endl;
		}
		else {
			cout << "you lose " << endl;
			cout << -benefit << "원 lose" << endl;
		}
		cout << endl;

		//cout << number << endl;

		money = money + benefit;

		cout << "Total your money : " << money << endl;
		count++;
		if (money <= 0)
		{
			cout << "You die" << endl;
			Sleep(2000);
			break;
		}

		Sleep(2000);
		system("cls");

		if (count > maxGamePlay) {

			cout << "ALL consume card." << endl;

			Sleep(2000);
			system("cls");

			break;

		}
	}
}
