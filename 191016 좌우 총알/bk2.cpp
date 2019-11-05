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
	//������ : Ÿ���� ������ �ν��Ͻ��� ���� �� �� 1�� ȣ���
	Unit(string symbol, int atk=5, int hp=45)//int atk=5, int hp=45 -> Default Parameter
	{
		MoveSpeed = 1;
		this->symbol = symbol;
		this->atk = atk;
		this->hp = hp;
		range = 5;
		bDead = false;

	}
	//�Ҹ��� : Ÿ���� ���� ���ڰ� ������ �ν��Ͻ��� �Ҹ�ɶ� �ڵ� ȣ��
	~Unit()
	{
	}
	void Update()
	{
		if (hp <= 0)
		{
			hp = 0;
			cout << "������" << endl;
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
		//�Ÿ� ���ϴ� ���� x�� y�� ��ǥ�� ���ϰ� x^+y^ ��Ʈ
		short distanceX = target->position.X - this->position.X;
		short distanceY = target->position.Y - this->position.Y;
		short distanceVec2 = sqrt(distanceX*distanceX + distanceY * distanceY);
		if (distanceVec2 > range)
		{
			cout << "���� ��" << endl;
			return false;
		}

		cout << "���� �� : " << distanceVec2 << endl;
		return true;
		
	}

	int Attack()
	{
		cout << "������ ���� ���� : " << endl;
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