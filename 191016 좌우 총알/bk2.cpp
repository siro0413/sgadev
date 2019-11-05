#include "stdafx.h"

HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
const short Width = 100;
const short Height = 50;

class Unit
{
private:
	string symbol;
	COORD position;
	short MoveSpeed;
	int atk;
	int hp;

	int range;
	bool bDead;
public:
	void Move()
	{
		if (GetAsyncKeyState('A') & 0x8000)
			position.X -= MoveSpeed;
		else if (GetAsyncKeyState('D') & 0x8000)
			position.X += MoveSpeed;
		if (GetAsyncKeyState('W') & 0x8000)
			position.Y -= MoveSpeed;
		else if (GetAsyncKeyState('S') & 0x8000)
			position.Y += MoveSpeed;

		if (position.X <= 0) position.X = 0;
		if (position.X >= Width - 2) position.X = Width - 2;
		if (position.Y <= 0) position.Y = 0;
		if (position.Y >= Height - 2) position.Y = Height - 2;
	}

public:
	//생성자 : 타입이 없으며 인스턴스를 만들 떄 딱 1번 호출됨
	Unit(string symbol, int atk=5, int hp=45)//int atk=5, int hp=45 -> Default Parameter
	{
		MoveSpeed = 1;
		this->symbol = symbol;
		this->atk = atk;
		this->hp = hp;
		range = 5;
		bDead = false;

	}
	//소멸자 : 타입이 없고 인자가 없으며 인스턴스가 소멸될때 자동 호출
	~Unit()
	{
	}
	void Update()
	{
		if (hp <= 0)
		{
			hp = 0;
			cout << "유다희" << endl;
		}
	}
	void Render()
	{
		SetConsoleCursorPosition(handle, position);
		cout << symbol;
	}

	COORD Position() { return position; }

	void Position(short x, short y)
	{
		COORD temp = { x,y };
		Position(temp);
	}
	void Position(COORD val) { position = val; }

	bool Range(const Unit* target)
	{
		//거리 구하는 공식 x와 y의 좌표를 구하고 x^+y^ 루트
		short distanceX = target->position.X - this->position.X;
		short distanceY = target->position.Y - this->position.Y;
		short distanceVec2 = sqrt(distanceX*distanceX + distanceY * distanceY);
		if (distanceVec2 > range)
		{
			cout << "범위 밖" << endl;
			return false;
		}

		cout << "범위 안 : " << distanceVec2 << endl;
		return true;
		
	}

	int Attack()
	{
		cout << "잔인한 공격 시작 : " << endl;
		return atk;
	}

	int HP() { return hp; } //Get
	void HP(int val) { hp = val; } //Set

	void Cout(Unit* Mon,Unit* Player)
	{
		short distanceX = Mon->Position().X - Player->Position().X;
		short distanceY = Mon->Position().Y - Player->Position().Y;
		cout << distanceX << ", " << distanceY << endl;
		short distanceVec2 = sqrt(distanceX*distanceX + distanceY * distanceY);
		cout << "Vector2 : " << distanceVec2 << endl;
		cout << "Zergling HP : " << Mon->HP() << endl;
	}
};




int main()
{

	Unit* player = new Unit("M");
	Unit* zergling = new Unit("Z");
	Unit* temp = new Unit("z");
	player->Position(8, 8);
	zergling->Position(12, 14);



	while (true)
	{
		system("cls");
		temp->Cout(zergling, player);
		int hp = zergling->HP();
		if (player->Range(zergling))
		{
			hp -= player->Attack();

		}
		zergling->HP(hp);
		zergling->Update();

		player->Move();
		player->Render();
		zergling->Render();
	}

	SAFE_DELETE(player);
	SAFE_DELETE(zergling);
	SAFE_DELETE(temp);

	system("pause");
	return 0;
}