#include "stdafx.h"
#pragma once

#if 1
int input;

char* player = (char*)"��";	//player
short x = 15, y = 4;		//player x,y

char* key = (char*)"��";
short Key_x = 22, Key_y = 16;

char* key2 = (char*)"��";
short Key2_x = 87, Key2_y = 16;


char* door1 = (char*)"@";
bool _door1 = false;

char* door2 = (char*)"@";
bool _door2 = false;

char* door3 = (char*)"@";
bool _door3 = false;

char* monster = (char*)"��";
bool monstera = false;
short m_x = 50, m_y = 12;

char* gool = (char*)"��";
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

void DrawMap();		//�ʱ׸���
void Move();		//move
void battel();		//battel
void View_icon();	//icon
void condition();	//����
void View_ah();		//player ����

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
	pos = { 10,2 };		SETPOS;	cout << "�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�";
	pos = { 10,3 };		SETPOS;	cout << "�ˡ��������ˡ������������������������������������������������������ˡ���������������";
	pos = { 10,4 };		SETPOS;	cout << "�ˡ��������ˡ����������������������������������������������������ˢˡ������ˡ�������";
	pos = { 10,5 };		SETPOS;	cout << "�ˡ��������ˡ��������������ˢˢˢˢˢˢˢˢˢˢˢˢˢˡ��������ˢˡ������ˢˢˢˢˢ�";
	pos = { 10,6 };		SETPOS;	cout << "�ˡ��������ˡ��������������ˡ������������������������ˡ������ˢˡ������ˢˢˢˢˢˢ�";
	pos = { 10,7 };		SETPOS;	cout << "�ˡ��������ˡ��������������ˡ������������������������ˢˢˢˢˡ������ˢˢˢˢˢˢˢ�";
	pos = { 10,8 };		SETPOS;	cout << "�ˡ��ˢˢˢˡ��������������ˡ�������������������������������������������������������";
	pos = { 10,9 };		SETPOS;	cout << "�ˡ��ˡ��������������������ˡ��������������������������������������������ˡ���������";
	pos = { 10,10 };	SETPOS;	cout << "�ˡ��ˢˢˢˢˢˢˢˢˢˢˢˡ������������������������ˢˢˢˢˢˢˢˢˡ��ˡ���������";
	pos = { 10,11 };	SETPOS;	cout << "�ˡ��������������������������������������������������ˡ��������������ˡ��ˡ���������";
	pos = { 10,12 };	SETPOS;	cout << "�ˡ��ˢˢˢˢˢˢˢˢˢˢˢˡ������������������������ˡ��������������ˡ��ˢˢˢˢˢ�";
	pos = { 10,13 };	SETPOS;	cout << "�ˡ������������ˡ����������ˡ������������������������ˡ��������������ˡ�������������";
	pos = { 10,14 };	SETPOS;	cout << "�ˡ��������ˡ��ˡ����������ˡ������������������������ˡ��������������ˢˢˡ���������";
	pos = { 10,15 };	SETPOS;	cout << "�ˡ��������ˡ��ˡ����������ˢˢˢˢˢˢˢˢˢˢˢˢˢˡ������������������ˡ���������";
	pos = { 10,16 };	SETPOS;	cout << "�ˡ��������ˡ��ˡ��������������������������������������������������������ˡ���������";
	pos = { 10,17 };	SETPOS;	cout << "�ˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢˢ�";


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

	cout << "���� �������ϴ�." << endl;
	Sleep(1000);
	system("cls");
	cout << "���� ����" << endl;
	srand((unsigned)time(NULL));
	while (monstera == false)
	{
		int luckm = rand() % 10 + 1;
		int luckp = rand() % 20 + 1;

		if (luckm <= 3)
		{
			printf("������ ����ȸ��\n\n");
			monster1st.hp = monster1st.hp - 0;
			Sleep(1000);
			system("cls");

		}
		else
		{
			printf("�÷��̾� ���ݼ���\n\n");
			monster1st.hp = monster1st.hp - (playerst.att - monster1st.def);
			if (monster1st.hp <= 0)
			{
				monster1st.hp = 0;
			}
			printf("������ ü���� ���� %d�Դϴ�.\n\n", monster1st.hp);
			Sleep(1000);
			system("cls");

		}

		if (monster1st.hp <= 0)
		{
			printf("�÷��̾ �¸��Ͽ����ϴ�.\n");
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
			printf("�÷��̾ ����ȸ���Ͽ����ϴ�.\n\n");
			playerst.hp = playerst.hp - 0;
			Sleep(1000);
			system("cls");

		}
		else
		{
			printf("������ ���ݼ���\n\n");
			playerst.hp = playerst.hp - (playerst.def - monster1st.att);
			printf("�÷��̾��� ü���� ���� %d�Դϴ�.\n\n", playerst.hp);
			Sleep(1000);
			system("cls");


		}

		if (playerst.hp <= 0)
		{
			printf("���Ͱ� �¸��Ͽ����ϴ�.\n");
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
	//���� ȹ��
	if (x == 22 && y == 15)
	{
		pos = { 10,19 }; SETPOS; cout << "���踦 ȹ���߽��ϴ�." << endl;
		key--;
		_door1 = true;
		if (_door1 == true)
		{
			door1--;
		}
	}
	//����ȹ���������� door1 open
	if (_door1 == false)
	{
		if (x >= 33 && y == 11)
		{
			x = 32;
			pos = { 10,19 }; SETPOS;
			cout << "�̵��� �Ұ����մϴ�." << endl;
		}

	}

	//���Ϳ��� ������ ������ door2 open
	if (_door2 == false)
	{
		if (x >= 61 && y == 8)
		{
			x = 60;	pos = { 10,19 }; SETPOS; cout << "���͸� óġ�Ͻʽÿ�." << endl;
		}
		if (x >= 61 && y == 9)
		{
			x = 60; pos = { 10,19 }; SETPOS; cout << "���͸� óġ�Ͻʽÿ�." << endl;
		}

	}
	//key2 ȹ��
	if (x == 87 && y == 15)
	{
		pos = { 10,19 }; SETPOS; cout << "���踦 ȹ���߽��ϴ�." << endl;
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



