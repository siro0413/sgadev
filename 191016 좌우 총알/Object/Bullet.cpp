#include "stdafx.h"
#include "Bullet.h"
Bullet::Bullet(string symbol, COORD start, short speed)
	:symbol(symbol),postion(start),velocity(1)
{
	velocity *= speed;
}

Bullet::~Bullet()
{
}

void Bullet::Update(int val)
{
	switch (val)
	{
	case 1:postion.X += velocity; break;
	case 2:postion.X -= velocity; break;
	}
	//postion.X += velocity;
}

void Bullet::Render()
{
	SetConsoleCursorPosition(Handle, postion);
	cout << symbol;


}
