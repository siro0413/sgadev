#include "stdafx.h"

// 1_ 구조체 card -> 카드모양(특수문자)
// 따라서 데이터 타입은 string
// 평상시엔 숫자로 보여야하기에 bool값으로 조건걸기
typedef struct tagCard
{
	string symbol;	//카드의 특수문자
	bool bOpen;		//카드가 뒤집어졌는지여부
}Card;

void Init(Card** card);
void Render(Card** card);
void Update(Card** card, Card** temp);
void Cheat(Card** card, UINT cheatKey);

int main()
{
	//특수문자 저장용 16배열
	Card* card[16];
	//선택한 카드를 저장하기위한 임시 2배열
	Card* temp[2];
	//heap영역에 저장하기위해 포인터선언

	//reset + shuffle
	Init(card);
	Cheat(card, 123);
	//선택한 카드는 처음에 없으니 nullptr선언 - 초기화
	temp[0] = NULL, temp[1] = NULL;


	while (true)
	{
		Render(card);
		Update(card,temp);
	}
	
	
	system("pause");
	return 0;
}

void Init(Card ** card)
{
	//Card Reset
	for (UINT i = 0; i < 2; i++)
	{
		card[i * 8 + 0] = new Card{ "◈",false };	//0, 8
		card[i * 8 + 1] = new Card{ "㉿",false };	//1, 9
		card[i * 8 + 2] = new Card{ "ㅩ",false };	//2, 10
		card[i * 8 + 3] = new Card{ "㎯",false };	//3, 11
		card[i * 8 + 4] = new Card{ "ㅱ",false };	//4, 12
		card[i * 8 + 5] = new Card{ "▶",false };	//5, 13
		card[i * 8 + 6] = new Card{ "♬",false };	//6, 14
		card[i * 8 + 7] = new Card{ "▣",false };	//7, 15
	}

	//Shuffle
	srand((unsigned)time(NULL));
	for (UINT i = 0; i < 160; i++)
	{
		int src = rand() % 16;
		int dst = rand() % 16;
		swap(card[src], card[dst]);
	}

	Render(card);

}

void Render(Card ** card)
{
	system("cls");
	
	//return Shuffle Render
	for (UINT i = 0; i < 16; i++)
	{
		//bOpen이 true인경우 특수문장 출력
		if (card[i]->bOpen == true)
			cout << card[i]->symbol.c_str() << "\t";
		//bOpen이 false인경우 숫자 출력
		else
			cout << i << "\t";
		if (i % 4 == 3)
			cout << endl << endl;
	}
	
	Sleep(500);


}

void Update(Card ** card, Card ** temp)
{
	UINT input;
	cout << "----------------------------------------" << endl;
	cin >> input;

	if (input > 15)
	{
		Cheat(card, input);
		return;
	}

	//Card render number
	if (card[input]->bOpen == false)
	{
		//Choice number opne card
		card[input]->bOpen = true;

		//비교를 위해 임시변수에 저장
		for (UINT i = 0; i < 2; i++)
		{
			if (temp[i] == NULL)
			{
				temp[i] = card[input];
				break;
			}
		}

	}



	if (temp[0] != NULL && temp[1] != NULL)
	{
		Render(card);
		if (temp[0]->symbol != temp[1]->symbol)
		{
			temp[0]->bOpen = false;
			temp[1]->bOpen = false;
		}
		temp[0] = NULL;
		temp[1] = NULL;
	}

}

void Cheat(Card ** card, UINT cheatKey)
{
	if (cheatKey == 123)
	{
		cout << "Render CheatKey" << endl;
		cout << "------------------" << endl;
		for (UINT i = 0; i < 16; i++)
		{
			cout << card[i]->symbol.c_str() << "\t";
			if (i % 4 == 3)
				cout << endl << endl;
		}
	}

	Sleep(2000);
	system("cls");
}
