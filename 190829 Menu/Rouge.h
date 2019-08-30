#include "stdafx.h"
#pragma once

#if 1
int input;

char* player = (char*)"◎";	//player
short x = 15, y = 4;		//player x,y

char* key = (char*)"◈";
short Key_x = 22, Key_y = 16;

char* key2 = (char*)"◈";
short Key2_x = 87, Key2_y = 16;


char* door1 = (char*)"@";
bool _door1 = false;

char* door2 = (char*)"@";
bool _door2 = false;

char* door3 = (char*)"@";
bool _door3 = false;

char* monster = (char*)"♣";
bool monstera = false;
short m_x = 50, m_y = 12;

char* gool = (char*)"♥";
short gx = 90, gy = 4;
bool gool_ = false;

typedef struct ability
{
	int hp;
	int att;
	int def;
	float luck;
#endif // 1

}St;

St playerst = { 200,32,21,20.0f };
St monster1st = { 50,12,16,5.0f };

COORD pos;

void DrawMap();		//맵그리기
void Move();		//move
void battel();		//battel
void View_icon();	//icon
void condition();	//조건
void View_ah();		//player 상태

int Rouge()
{
	while (true)
	{
		if (_kbhit())
		{
			system("cls");
			DrawMap();
			Move();
			View_icon();
			condition();
			while (_kbhit())_getch();
			View_ah();
			if (GetAsyncKeyState(VK_ESCAPE) & 0x8000)
			{
				system("cls");
				break;
			}
		}
	}
	system("pause");
	return 0;
}

void DrawMap()
{
	pos = { 10,2 };		SETPOS;	cout << "▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦";
	pos = { 10,3 };		SETPOS;	cout << "▦　　　　▦　　　　　　　　　　　　　　　　　　　　　　　　　　　▦　　　　　　　▦";
	pos = { 10,4 };		SETPOS;	cout << "▦　　　　▦　　　　　　　　　　　　　　　　　　　　　　　　　　▦▦　　　▦　　　▦";
	pos = { 10,5 };		SETPOS;	cout << "▦　　　　▦　　　　　　　▦▦▦▦▦▦▦▦▦▦▦▦▦▦　　　　▦▦　　　▦▦▦▦▦▦";
	pos = { 10,6 };		SETPOS;	cout << "▦　　　　▦　　　　　　　▦　　　　　　　　　　　　▦　　　▦▦　　　▦▦▦▦▦▦▦";
	pos = { 10,7 };		SETPOS;	cout << "▦　　　　▦　　　　　　　▦　　　　　　　　　　　　▦▦▦▦▦　　　▦▦▦▦▦▦▦▦";
	pos = { 10,8 };		SETPOS;	cout << "▦　▦▦▦▦　　　　　　　▦　　　　　　　　　　　　　　　　　　　　　　　　　　　▦";
	pos = { 10,9 };		SETPOS;	cout << "▦　▦　　　　　　　　　　▦　　　　　　　　　　　　　　　　　　　　　　▦　　　　▦";
	pos = { 10,10 };	SETPOS;	cout << "▦　▦▦▦▦▦▦▦▦▦▦▦▦　　　　　　　　　　　　▦▦▦▦▦▦▦▦▦　▦　　　　▦";
	pos = { 10,11 };	SETPOS;	cout << "▦　　　　　　　　　　　　　　　　　　　　　　　　　▦　　　　　　　▦　▦　　　　▦";
	pos = { 10,12 };	SETPOS;	cout << "▦　▦▦▦▦▦▦▦▦▦▦▦▦　　　　　　　　　　　　▦　　　　　　　▦　▦▦▦▦▦▦";
	pos = { 10,13 };	SETPOS;	cout << "▦　　　　　　▦　　　　　▦　　　　　　　　　　　　▦　　　　　　　▦　　　　　　▦";
	pos = { 10,14 };	SETPOS;	cout << "▦　　　　▦　▦　　　　　▦　　　　　　　　　　　　▦　　　　　　　▦▦▦　　　　▦";
	pos = { 10,15 };	SETPOS;	cout << "▦　　　　▦　▦　　　　　▦▦▦▦▦▦▦▦▦▦▦▦▦▦　　　　　　　　　▦　　　　▦";
	pos = { 10,16 };	SETPOS;	cout << "▦　　　　▦　▦　　　　　　　　　　　　　　　　　　　　　　　　　　　　▦　　　　▦";
	pos = { 10,17 };	SETPOS;	cout << "▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦▦";


}
void Move()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		y -= 1;
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		y += 1;
	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		x -= 1;
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		x += 1;


}
void battel()
{
	pos = { 10,19 }; SETPOS;

	cout << "적과 만났습니다." << endl;
	Sleep(1000);
	system("cls");
	cout << "전투 시작" << endl;
	srand((unsigned)time(NULL));
	while (monstera == false)
	{
		int luckm = rand() % 10 + 1;
		int luckp = rand() % 20 + 1;

		if (luckm <= 3)
		{
			printf("몬스터의 공격회피\n\n");
			monster1st.hp = monster1st.hp - 0;
			Sleep(1000);
			system("cls");

		}
		else
		{
			printf("플레이어 공격성공\n\n");
			monster1st.hp = monster1st.hp - (playerst.att - monster1st.def);
			if (monster1st.hp <= 0)
			{
				monster1st.hp = 0;
			}
			printf("몬스터의 체력은 현재 %d입니다.\n\n", monster1st.hp);
			Sleep(1000);
			system("cls");

		}

		if (monster1st.hp <= 0)
		{
			printf("플레이어가 승리하였습니다.\n");
			Sleep(1000);
			system("cls");
			_door2 = true;
			if (_door2 == true)
			{
				door2--;
			}
			DrawMap();
			monstera = true;
			if (monstera = true)
			{
				monster--;
			}
			break;
		}
		if (luckm == 1)
		{
			printf("플레이어가 공격회피하였습니다.\n\n");
			playerst.hp = playerst.hp - 0;
			Sleep(1000);
			system("cls");

		}
		else
		{
			printf("몬스터의 공격성공\n\n");
			playerst.hp = playerst.hp - (playerst.def - monster1st.att);
			printf("플레이어의 체력은 현재 %d입니다.\n\n", playerst.hp);
			Sleep(1000);
			system("cls");


		}

		if (playerst.hp <= 0)
		{
			printf("몬스터가 승리하였습니다.\n");
			Sleep(1000);
			system("cls");
			DrawMap();
			break;
		}

	}

}
void View_icon()
{
	//player
	pos = { x,y }; SETPOS; cout << player;
	//monster
	pos = { m_x,m_y }; SETPOS; cout << monster;
	//key2
	pos = { Key_x,Key_y }; SETPOS; cout << key;
	pos = { Key2_x,Key2_y }; SETPOS; cout << key2;
	//door
	pos = { 35,11 }; SETPOS; cout << door1;
	pos = { 63,8 }; SETPOS; cout << door2;
	pos = { 63,9 }; SETPOS; cout << door2;
	pos = { 84,3 }; SETPOS; cout << door3;
	//gool
	pos = { gx,gy }; SETPOS; cout << gool;
}
void condition()
{
	//열쇠 획득
	if (x == 22 && y == 15)
	{
		pos = { 10,19 }; SETPOS; cout << "열쇠를 획득했습니다." << endl;
		key--;
		_door1 = true;
		if (_door1 == true)
		{
			door1--;
		}
	}
	//열쇠획득으로인한 door1 open
	if (_door1 == false)
	{
		if (x >= 33 && y == 11)
		{
			x = 32;
			pos = { 10,19 }; SETPOS;
			cout << "이동이 불가능합니다." << endl;
		}

	}

	//몬스터와의 전투가 끝날시 door2 open
	if (_door2 == false)
	{
		if (x >= 61 && y == 8)
		{
			x = 60;	pos = { 10,19 }; SETPOS; cout << "몬스터를 처치하십시오." << endl;
		}
		if (x >= 61 && y == 9)
		{
			x = 60; pos = { 10,19 }; SETPOS; cout << "몬스터를 처치하십시오." << endl;
		}

	}
	//key2 획득
	if (x == 87 && y == 15)
	{
		pos = { 10,19 }; SETPOS; cout << "열쇠를 획득했습니다." << endl;
		key2--;
		_door3 = true;
		if (_door3 == true)
		{
			door3--;
		}
	}

	//GOOL
	if (x == gx - 2 && y == gy || x == gx && y == gy - 1)
	{
		pos = { 10,19 }; SETPOS; cout << "CLEAR!!";
		gool_ = true;
	}


	if (x == m_x - 2 && y == m_y || x == m_x + 2 && y == m_y || x == m_x && y == m_y - 1 || x == m_x && y == m_y + 1)
	{
		battel();
	}
}
void View_ah()
{
	pos = { 10,18 }; SETPOS;
	cout << "Player HP : " << playerst.hp << "\t" << "Player att : " << playerst.att << "\t\t" << "Player def : " << playerst.def;

}



