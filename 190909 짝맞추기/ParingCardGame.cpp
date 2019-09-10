#include "stdafx.h"

// 1_ ����ü card -> ī����(Ư������)
// ���� ������ Ÿ���� string
// ���ÿ� ���ڷ� �������ϱ⿡ bool������ ���ǰɱ�
typedef struct tagCard
{
	string symbol;	//ī���� Ư������
	bool bOpen;		//ī�尡 ����������������
}Card;

void Init(Card** card);
void Render(Card** card);
void Update(Card** card, Card** temp);
void Cheat(Card** card, UINT cheatKey);

int main()
{
	//Ư������ ����� 16�迭
	Card* card[16];
	//������ ī�带 �����ϱ����� �ӽ� 2�迭
	Card* temp[2];
	//heap������ �����ϱ����� �����ͼ���

	//reset + shuffle
	Init(card);
	Cheat(card, 123);
	//������ ī��� ó���� ������ nullptr���� - �ʱ�ȭ
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
		card[i * 8 + 0] = new Card{ "��",false };	//0, 8
		card[i * 8 + 1] = new Card{ "��",false };	//1, 9
		card[i * 8 + 2] = new Card{ "��",false };	//2, 10
		card[i * 8 + 3] = new Card{ "��",false };	//3, 11
		card[i * 8 + 4] = new Card{ "��",false };	//4, 12
		card[i * 8 + 5] = new Card{ "��",false };	//5, 13
		card[i * 8 + 6] = new Card{ "��",false };	//6, 14
		card[i * 8 + 7] = new Card{ "��",false };	//7, 15
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
		//bOpen�� true�ΰ�� Ư������ ���
		if (card[i]->bOpen == true)
			cout << card[i]->symbol.c_str() << "\t";
		//bOpen�� false�ΰ�� ���� ���
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

		//�񱳸� ���� �ӽú����� ����
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
