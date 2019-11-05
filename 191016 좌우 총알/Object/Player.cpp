#include "stdafx.h"
#include "Player.h"

Player::Player(string symbol)
	: symbol(symbol)
	, pos({ 0,0 })
	, moveSpeed(1)
{
	//this->symbol = symbol;
	//pos = { 0,0 };
	//moveSpeed = 1;
}

Player::~Player()
{
}

void Player::Move()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		pos.Y -= moveSpeed;
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		pos.Y += moveSpeed;

	if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		pos.X -= moveSpeed;
	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		pos.X += moveSpeed;


	if (pos.X <= 0)
		pos.X = 0;

	if (pos.X >= Width - 2)
		pos.X = Width - 2;

	if (pos.Y <= 0)
		pos.Y = 0;

	if (pos.Y >= Height - 1)
		pos.Y = Height - 1;


	
}
void Player::Update()
{
	Move();
}

void Player::Render(COLOR color)
{
	
	SetConsoleCursorPosition(Handle, pos);
	Device::SetColor(color);
	{
		cout << symbol;
	}
	Device::SetColor(COLOR::DEFAULT);



}

