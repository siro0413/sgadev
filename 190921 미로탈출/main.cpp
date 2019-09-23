#include "stdafx.h"
#define UP 72
#define DOWN 80 //키보드 방향키의 아스키코드값을 정의해둔것입니다.
#define LEFT 75     //이런식으로 정의해두면 편하게 사용할 수 있습니다.
#define RIGHT 77
int checker, key;
int X = 8, Y = 3;
int key1x = 6, key1y = 13;
bool bKey1 = false;
bool bKey2 = false;
bool bKey3 = false; // 신발
bool bKey4 = false; // 두개짜리
bool bKey5 = false; // 두개짜리

bool weapon = false;
bool helmet = false;
bool Armor = false;
bool shoes = false;
bool ring = false;
bool hiden = false;
bool heal = false;
bool heal2 = false;
bool posion = false;

bool door1 = false;
bool door2 = false;
bool door3 = false;//신발
bool door4 = false;//위에 두개
bool door5 = false;

bool mon1 = false;
bool mon2 = false;
bool boos = false;

bool gool1 = false;
bool gool2 = false;
typedef struct Stat
{
	int hp;
	int att;
	int def;
	int luck;
	int speed;
}ST;

ST playerST = { 200,15,20,5 };
ST monster1 = { 10,10,15,3 };
ST monster2 = { 50,12,17,2 };
ST monster3 = { 50,12,17,2 };
ST _Boos = { 100,20,20,3 };

void gotoxy(int x, int y) //gotoxy함수를 호출해올 기본함수.
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
int map[24][68] =
{
	{0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9},
	{0,9,0,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9},
	{0,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,1,9},
	{0,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,1,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9,0,9,0,9,0,9,1,9},
	{0,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,1,9,1,9,1,9,0,9,0,9,1,9,1,9,1,9,1,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,1,9,1,9},
	{0,9,0,9,1,9,0,9,1,9,1,9,1,9,1,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,1,9},
	{0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,0,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9},
	{0,9,0,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,1,9},
	{0,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,0,9,1,9,0,9,1,9,1,9,0,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9},
	{0,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9},
	{0,9,0,9,1,9,1,9,1,9,0,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9,0,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,1,9,0,9,1,9,1,9,1,9,0,9,0,9,1,9,1,9,1,9,1,9,1,9},
	{0,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,1,9,1,9,1,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,1,9,1,9,0,9,0,9,1,9,0,9,0,9,1,9},
	{0,9,0,9,1,9,1,9,1,9,1,9,1,9,0,9,1,9,1,9,1,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,1,9,1,9,1,9,1,9,1,9,0,9,0,9,1,9,1,9,0,9,1,9,0,9,1,9,1,9},
	{0,9,0,9,1,9,0,9,0,9,0,9,1,9,1,9,1,9,0,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9,1,9,0,9,1,9,1,9,0,9,0,9,0,9,1,9,1,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,1,9},
	{0,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,0,9,1,9,1,9,0,9,1,9,1,9,1,9,1,9,1,9,1,9},
	{0,9,0,9,1,9,0,9,1,9,1,9,1,9,1,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,1,9,1,9,1,9,1,9,1,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9},
	{0,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,0,9,1,9,0,9,0,9,0,9,1,9,1,9,1,9,1,9,0,9,1,9,1,9,1,9,1,9,1,9,1,9},
	{0,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,1,9,1,9,1,9,1,9,1,9,0,9,1,9,1,9,1,9,1,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,1,9},
	{0,9,0,9,1,9,1,9,1,9,1,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,1,9,1,9,1,9,1,9,1,9,1,9,0,9,1,9,0,9,1,9,1,9,1,9,1,9,1,9,0,9,1,9,0,9,1,9},
	{0,9,0,9,1,9,0,9,0,9,1,9,0,9,0,9,1,9,0,9,1,9,1,9,1,9,1,9,1,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,1,9},
	{0,9,0,9,1,9,1,9,0,9,1,9,0,9,1,9,1,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,1,9,1,9,1,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9},
	{0,9,0,9,1,9,0,9,0,9,1,9,0,9,1,9,0,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,1,9,0,9,1,9,0,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9},
	{0,9,0,9,1,9,0,9,0,9,0,9,0,9,1,9,0,9,1,9,1,9,0,9,0,9,0,9,1,9,0,9,1,9,1,9,1,9,0,9,1,9,1,9,1,9,1,9,0,9,0,9,0,9,1,9,0,9,0,9,0,9,0,9,0,9,1,9},
	{0,9,0,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9,1,9}
};
void DrawMap()
{
	gotoxy(0, 2); //원하는 좌표로 가서

	for (int i = 0; i < 24; i++)
	{

		for (int j = 0; j < 67; j++)
		{

			if (map[i][j] == 1)
				cout << "▩";
			else if (map[i][j] == 0)
				cout << "　";
		}
		cout << endl;
	}

}

void battel(ST player,ST monster);



int keeper(int(*map)[68], int X, int Y) 
{ //2차원 배열과 좌표를 받습니다.

	int checker;

	if (*(*(map + Y) + X) == 0)
	{ //야 간단히 검사만 하면 되겠네요? 그렇죠?
		checker = 1;
	} //좌표부분의 맵값이 0이면 1을 반환하고
	else if (*(*(map + Y) + X) == 2) {
		checker = 1;
	}
	else { checker = 0; } //0이 아니면 지나다니면 안된다는듯으로 0을 반환시킬께요. 

	return checker;
}
void DrawCharter()
{
	gotoxy(X, Y + 2);
	cout << "◎";

	gotoxy(4, 26);
	cout << "Player HP : " << playerST.hp << "\t" << "Player Att : " << playerST.att << "\t\t" << "Player Def : " << playerST.def << endl;


	if (bKey1 == false)
	{
		gotoxy(key1x, key1y);
		cout << "◆";
		if (X == key1x + 2 && Y == key1y-2)
		{
			bKey1 = true;
			door1 = true;
		
			gotoxy(4, 27);
			cout << "1번째 열쇠를 획득했습니다." << endl;
		}
	}
	if (bKey2 == false)
	{
		gotoxy(6, 21);
		cout << "◆";
		if (X == 8 && Y + 2 == 21)
		{
			bKey2 = true;
			door2 = true;
			gotoxy(4, 27);
			cout << "2번째 열쇠를 획득했습니다." << endl;
		}
	}
	if (bKey3 == false)
	{
		gotoxy(50, 17);
		cout << "◆";
		if (X == 48 && Y + 2 == 17)
		{
			bKey3 = true;
			door3 = true;
			gotoxy(4, 27);
			cout << "3번째 열쇠를 획득했습니다." << endl;
		}
	}
	if (bKey4 == false)
	{
		gotoxy(52, 6);
		cout << "◆";
		if (X == 52 && Y + 2 == 7)
		{
			bKey4 = true;
			door4 = true;
			gotoxy(4, 27);
			cout << "4번째열쇠를 획득했습니다." << endl;
		}
	}
	if (bKey5 == false)
	{
		gotoxy(64, 13);
		cout << "◆";
		if (X == 62 && Y + 2 == 13)
		{
			bKey5 = true;
			door5 = true;
			gotoxy(4, 27);
			cout << "마지막 열쇠를 획득했습니다." << endl;
		}
	}
	if (mon1 == false)
	{
		gotoxy(6, 15);
		cout << "★";
		if (X == 8 && Y + 2 == 15)
		{
			gotoxy(4, 27);
			cout << "몬스터와 조우 했습니다." << endl;
			Sleep(1000);
			battel(playerST,monster1);
		}
	}
	if (mon2 == false)
	{
		gotoxy(44, 15);
		cout << "★";
		if (X == 42 && Y + 2 == 15)
		{
			gotoxy(4, 27);
			cout << "몬스터와 조우 했습니다." << endl;
			Sleep(1000);
			battel(playerST, monster2);
		}
	}
	if (boos == false)
	{
		gotoxy(60, 9);
		cout << "★";
		if (X == 58 && Y + 2 == 9)
		{
			gotoxy(4, 27);
			cout << "보스와 조우 했습니다." << endl;
			Sleep(1000);
			battel(playerST, _Boos);
		}
	}

	if (door1 == false)
	{
		gotoxy(10, 8);
		cout << "＠";
		if (X == 8 && Y + 2 == 8)
		{
			gotoxy(4, 27);
			cout << "지나갈수없습니다. 열쇠를 획득해주세요." << endl;
			X -= 2;
		}
		else
		{
			gotoxy(8, 8);
			cout << "　";
			gotoxy(4, 27);
			cout << "                                                               " << endl;
		}
	}
	if (door2 == false)
	{
		gotoxy(26, 14);
		cout << "＠";
		if (X == 24 && Y + 2 == 14)
		{
			gotoxy(4, 27);
			cout << "지나갈수없습니다. 열쇠를 획득해주세요." << endl;
			X -= 2;
		}
		else
		{
			gotoxy(24, 14);
			cout << "　";
		}
	}
	if (door3 == false)
	{
		gotoxy(40, 23);
		cout << "＠";
		if (X == 42 && Y + 2 == 23)
		{
			gotoxy(4, 27);
			cout << "지나갈수없습니다. 열쇠를 획득해주세요." << endl;
			X += 2;
		}
		else
		{
			gotoxy(42, 23);
			cout << "　";
		}
	}
	if (door4 == false)
	{
		gotoxy(30, 6);
		cout << "＠";
		gotoxy(32, 6);
		cout << "＠";
		if ((X == 30 && Y + 2 == 7) || (X == 32 && Y + 2 == 7))
		{
			gotoxy(4, 27);
			cout << "지나갈수없습니다. 열쇠를 획득해주세요." << endl;
			Y += 2;
		}
		else
		{
			gotoxy(30, 7);
			cout << "　";
			gotoxy(32, 7);
			cout << "　";
		}
	}
	if (door5 == false)
	{
		gotoxy(54, 18);
		cout << "＠";
		if (X == 54 && Y + 2 == 17)
		{
			gotoxy(4, 27);
			cout << "지나갈수없습니다. 열쇠를 획득해주세요." << endl;
			Y -= 2;
		}
		else
		{
			gotoxy(54, 17);
			cout << "　";
		}
	}
	if (weapon == false)
	{					
		gotoxy(14, 6);	
		cout << "ψ";
		if (X == 14 && Y + 2 == 5)
		{
			gotoxy(4, 27);
			cout << "무기(검)을 획득했습니다. 공격력 10증가" << endl;
			playerST.att += 10;
			weapon = true;
		}
	}					
	if (helmet == false)
	{
		gotoxy(16, 24);
		cout << "Ω";
		if (X == 16 && Y + 2 == 23)
		{
			gotoxy(4, 27);
			cout << "투구을 획득했습니다. 방어력 10증가" << endl;
			playerST.def += 10;
			helmet = true;
		}
	}
	if (hiden == false)
	{
		gotoxy(18, 11);
		cout << "　";
		if (X == 18 && Y + 2 == 10)
		{
			gotoxy(18, 11);
			cout << "♬";
			gotoxy(4, 27);
			cout << "히든 피스 발견!! 공격력 방어력 10증가" << endl;
			playerST.att += 10;
			playerST.def += 10;
			hiden = true;
		}
	}
	if (ring == false)
	{
		gotoxy(26, 4);
		cout << "⊙";
		if ((X == 28 && Y + 2 == 4) || (X == 26 && Y + 2 == 5))
		{
			gotoxy(4, 27);
			cout << "반지를 획득했습니다. 공격력 5증가";
			playerST.att += 5;
			ring = true;
		}
	}
	if (shoes == false)
	{
		gotoxy(38, 24);
		cout << "♣";
		if (X == 38 && Y+2 == 23)
		{
			gotoxy(4, 27);
			cout << "사실 이건 낚시였습니다 따란~";
			shoes = true;
		}
	}
	if (Armor == false)
	{
		gotoxy(38, 4);
		cout << "◇";
		if ((X == 36 && Y + 2 == 4) || (X == 38 && Y + 2 == 5))
		{
			gotoxy(4, 27);
			cout << "갑옷을 획득했습니다. 최대 체력 15증가";
			playerST.hp += 15;
			Armor = true;
		}
	}
	if (heal == false)
	{
		gotoxy(22, 22);
		cout << "Η";
		if (X == 22 && Y + 2 == 23)
		{
			gotoxy(4, 27);
			cout << "회복 포션을 먹었습니다.";
			playerST.hp += 200 - playerST.hp;
			if (Armor == true)
				playerST.hp += 15;
			heal = true;
		}
	}
	if (heal2 == false)
	{
		gotoxy(64, 17);
		cout << "Η";
		if (X == 62 && Y + 2 == 17)
		{
			gotoxy(4, 27);
			cout << "회복 포션을 먹었습니다.";
			playerST.hp += 200 - playerST.hp;
			if (Armor == true)
				playerST.hp += 15;
			heal2 = true;
		}
	}
	if (posion == false)
	{
		gotoxy(26, 12);
		cout << "H";
		if ((X == 26 && Y + 2 == 11) || (X == 28 && Y + 2 == 12))
		{
			gotoxy(4, 27);
			cout << "회복 포션으로 둔갑한 독약이였습니다 따란~ 체력 10감소!";
			playerST.hp -= 10;
			posion = true;
		}
	}
	if (gool1 == false)
	{
		gotoxy(64, 19);
		cout << "♥";
		if (X == 64 && Y+2 == 20)
		{
			gotoxy(4, 27);
			cout << "골이아닌 몬스터였습니다!";
			Sleep(1000);
			battel(playerST,monster3);
		}
	}
	if (gool2 == false)
	{
		gotoxy(64, 4);
		cout << "♥";
		if ((X == 62 && Y + 2 == 4) || (X == 64 && Y + 2 == 5))
		{
			gotoxy(4, 27);
			cout << "CLEAR!!!!!";
			gool2 = true;
		}
	}

}
void Cherker()
{
	if (bKey1 == true)
	{
		gotoxy(key1x, key1y);
		cout << "　";
		gotoxy(4, 27);
		cout << "                                                               " << endl;
	}
	if (bKey2 == true)
	{
		gotoxy(6, 21);
		cout << "　";
		gotoxy(4, 27);
		cout << "                                                               " << endl;
	}	
	if (bKey3 == true)
	{
		gotoxy(50, 17);
		cout << "　";
		gotoxy(4, 27);
		cout << "                                                               " << endl;
	}	
	if (bKey4 == true)
	{
		gotoxy(52, 6);
		cout << "　";
		gotoxy(4, 27);
		cout << "                                                               " << endl;
	}
	if (bKey5 == true)
	{
		gotoxy(64, 13);
		cout << "　";
	}
	if (door1 == true)
	{
		gotoxy(10, 8);
		cout << "　　";
	}

	if (door2 == true)
	{
		gotoxy(26, 14);
		cout << "　";
	}
	if (door3 == true)
	{
		gotoxy(40, 23);
		cout << "　";
	}
	if (door4 == true)
	{
		gotoxy(30, 6);
		cout << "　";
		gotoxy(32, 6);
		cout << "　";
	}
	if (door5 == true)
	{
		gotoxy(54, 18);
		cout << "　";
	}
	if (weapon == true)
	{
		gotoxy(14, 6);
		cout << "　";
	}
	if (helmet == true)
	{
		gotoxy(16, 24);
		cout << "　";
	}
	if (shoes == true)
	{
		gotoxy(38, 24);
		cout << "　";
	}
	if (hiden == true)
	{
		gotoxy(18, 11);
		cout << "　";
	}
	if (ring == true)
	{
		gotoxy(26, 4);
		cout << "　";
	}
	if (Armor == true)
	{
		gotoxy(38,4);
		cout << "　";
	}
	if (heal == true)
	{
		gotoxy(22, 22);
		cout << "　";
	}
	if (heal2 == true)
	{
		gotoxy(64, 17);
		cout << "　";
	}
	if (posion == true)
	{
		gotoxy(26, 12);
		cout << "　";
	}
	if (gool2 == true)
	{
		gotoxy(64, 4);
		cout << "　";

	}
}


void Control()
{
	key = _getch();
	switch (key)
	{
	case UP: gotoxy(X, Y + 2);
		cout << "　";
		Y -= 1;
		checker = keeper(map, X, Y);
		if (checker == 1)
		{
			gotoxy(X, Y + 2);
			cout << "◎";
			break;
		}
		else if (checker == 0)
		{
			Y += 1;
			gotoxy(X, Y + 2);
			cout << "◎";
			break;
		}
	case DOWN: gotoxy(X, Y + 2);
		cout << "　";
		Y += 1;
		checker = keeper(map, X, Y);
		if (checker == 1)
		{
			gotoxy(X, Y + 2);
			cout << "◎";
			break;
		}
		else if (checker == 0)
		{
			Y -= 1;
			gotoxy(X, Y + 2);
			cout << "◎";
			break;
		}
	case LEFT: gotoxy(X, Y + 2);
		cout << "　";
		X -= 2;
		checker = keeper(map, X, Y);
		if (checker == 1)
		{
			gotoxy(X, Y + 2);
			cout << "◎";
			break;
		}
		else if (checker == 0)
		{
			X += 2;
			gotoxy(X, Y + 2);
			cout << "◎";
			break;
		}
	

	case RIGHT: gotoxy(X, Y + 2);
		cout << "　";
		X += 2;
		checker = keeper(map, X, Y);
		if (checker == 1)
		{
			gotoxy(X, Y + 2);
			cout << "◎";
			break;
		}
		else if (checker == 0)
		{
			X -= 2;
			gotoxy(X, Y + 2);
			cout << "◎";
			break;
		}


	default:
		break;
	}

}
int main()
{
	DrawMap();


	while (true)
	{
		gotoxy(75, 5);
		cout << "무늬 설명";
		gotoxy(75, 6);
		cout << "Player \t: ◎";
		gotoxy(75, 7);
		cout << "Key \t\t: ◆";
		gotoxy(75, 8);
		cout << "Monster \t: ★";
		gotoxy(75, 9);
		cout << "Door \t: ＠";
		gotoxy(75, 10);
		cout << "Weapon \t: ψ";
		gotoxy(75, 11);
		cout << "Helmet \t: Ω";
		gotoxy(75, 12);
		cout << "Ring \t: ⊙";
		gotoxy(75, 13);
		cout << "Shose \t: ♣";
		gotoxy(75, 14);
		cout << "Armor \t: ◇";
		gotoxy(75, 15);
		cout << "Healing \t: Η";
		gotoxy(75, 16);
		cout << "Gool \t: ♥";
		gotoxy(75, 17);
		cout << "게임설명";
		gotoxy(75, 18);
		cout<<"플레이어를 조종하여 골을찾아가면됩니다.";
		gotoxy(75, 19);
		cout << "열쇠를 획득하여 문을열고 몬스터를 처치하며";
		gotoxy(75, 20);
		cout << "각종 아이템들을 얻어 골을향하시면 됩니다.";

		gotoxy(4, 28);
		cout << "↑↑↑↑↑↑↑↑↑↑↑↑";
		gotoxy(4, 29);
		cout << "이곳에 정보가 표기됩니다.";

		map;
		DrawCharter();
		Control();
		Cherker();
	}



	system("pause");
	return 0;
}

void battel(ST player,ST monster)
{
	int ninput;
	int count = 0;
	int monc = 1;
	system("cls");
	srand((unsigned)time(NULL));
	while (player.hp >= 0 && monster.hp >= 0)
	{
		int Sp_P = rand() % 15 + 1;
		int Sp_M = rand() % 15 + 1;

		int Luck = rand() % 10 + 1;

		player.speed = Sp_P;
		monster.speed = Sp_M;

		if (player.speed > monster.speed)
		{
			monc = 1;
			gotoxy(3, 10);
			cout << "플레이어의 공격" << endl;
			gotoxy(3, 11);
			cout << "-------------------------------------" << endl;
			gotoxy(3, 12);
			cout << "Player HP : " << player.hp << "\t\t" << "Player Att : " << player.att << "\t\t" << "Player Def : " << player.def << "\t\t" << "Player Speed : " << player.speed << endl;
			gotoxy(3, 13);
			cout << "Monster HP : " << monster.hp << "\t\t" << "Monster Att : " << monster.att << "\t" << "Monster Def : " << monster.def << "\t" << "Monster Speed : " << monster.speed << endl;
			gotoxy(3, 14);
			cout << "-------------------------------------" << endl;
			gotoxy(3, 15);
			cout << "1.공격\t\t\t 2.방어" << endl;
			gotoxy(3, 16);
			cout << "무엇을 선택하시겠습니까? : ";
			cin >> ninput;

			if (ninput == 1)
			{
				system("cls");
				if (monster.luck < Luck)
				{
					gotoxy(3, 10);
					cout << "공격 성공" << endl;
					monster.hp = monster.hp - (player.att - (monster.def / 2));
					player.speed = 0;
					if (monster.hp <= 0)
						monster.hp = 0;

					if (monster.hp == 0)
					{
						system("cls");
						gotoxy(3, 10);
						cout << "토벌 성공";
						Sleep(1000);
						system("cls");
						if (X == 8 && Y + 2 == 15)
							mon1 = true;
						else if (X == 42 && Y + 2 == 15)
							mon2 = true;
						else if (X == 64 && Y + 2 == 20)
							gool1 = true;
						else if (X == 58 && Y + 2 == 9)
							boos = true;
						playerST.hp = player.hp;
						map;
						DrawMap();
						break;
					}
					Sleep(1000);
					system("cls");
				}
				else if (monster.luck > Luck)
				{
					gotoxy(3, 10);
					cout << "몬스터가 공격을 회피했습니다." << endl;
					player.speed = 0;
					monster.hp = monster.hp;
					Sleep(1000);
					system("cls");
				}
			}
			else if (ninput == 2)
			{
				if (count > 2)
				{
					system("cls");
					gotoxy(3, 10);
					cout << "더이상 방어력을 증가시킬수 없습니다." << endl;
					player.speed = 0;
					Sleep(1000);
					system("cls");
				}
				else if (count <= 2)
				{
					system("cls");
					gotoxy(3, 10);
					cout << "Player가 방어자세를 만들었습니다." << endl;
					gotoxy(3, 11);
					cout << "Player의 방어력 +10" << endl;
					player.def += 10;
					player.speed = 0;
					count++;
					Sleep(1000);
					system("cls");
				}
			}
			else
			{
				gotoxy(3, 10);
				cout << "이봐 자네 1~2번만 누르라고?" << endl;
				Sleep(1000);
				system("cls");
			}
		}
		else if (player.speed < monster.speed)
		{
			gotoxy(3, 10);
			cout << "-------------------------------------" << endl;
			gotoxy(3, 11);
			cout << "Player HP : " << player.hp << "\t\t" << "Player Att : " << player.att << "\t\t" << "Player Def : " << player.def << "\t\t" << "Player Speed : " << player.speed << endl;
			gotoxy(3, 12);
			cout << "Monster HP : " << monster.hp << "\t\t" << "Monster Att : " << monster.att << "\t" << "Monster Def : " << monster.def << "\t" << "Monster Speed : " << monster.speed << endl;
			gotoxy(3, 13);
			cout << "-------------------------------------" << endl;
			gotoxy(3, 14);
			cout << "몬스터의 공격" << endl;
			gotoxy(3, 15);
			cout << "몬스터는 공격만 합니다." << endl;
			gotoxy(3, 16);
			cout << "현재 몬스터가 " << monc << "번째 연속공격중입니다."<<endl;
			monc++;
			if (monc >= 4)
			{
				gotoxy(3, 17);
				cout << "당신 느리구만?";
			}
			player.hp = player.hp - (monster.att - (player.def / 10));
			if (X == 58 && Y + 2 == 9)
			{
				if (player.hp <= 0)
				{
					gotoxy(X = 56, Y = 5);
					cout << "◎";
					playerST.hp += 200 - playerST.hp;
					if (Armor == true)
						playerST.hp += 15;
					map;
					DrawMap();
					break;
				}
			}
			Sleep(1000);
			system("cls");


		}

	}

}
