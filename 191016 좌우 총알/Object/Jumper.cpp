#include "stdafx.h"
#include "Player.h"
#include "Jumper.h"



Jumper::Jumper(string symbol)
	:Player(symbol)
	,bGround(true)
	,velocity(0)
	,gravity(1)
	,groundPos(0)
	,bRShoot(false)
	,bLShoot(false)
{
	groundPos = pos.Y;
}

Jumper::~Jumper()
{
}

void Jumper::Update()
{
	if (GetAsyncKeyState('A') & 0x8000)
	{
		pos.X -= moveSpeed;
		symbol = "¢¸";
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8002)
			bLShoot = true;
	}
	else if (GetAsyncKeyState('D') & 0x8000)
	{
		pos.X += moveSpeed;
		symbol = "¢º";
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8002)
			bRShoot = true;
	}

	/*if (GetAsyncKeyState(VK_LBUTTON) & 0x8002)
		bRShoot = true;*/

	if (symbol == "¢¸")
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8002)
			bLShoot = true;
	 if (symbol == "¢º")
		if (GetAsyncKeyState(VK_LBUTTON) & 0x8002)
			bRShoot = true;

	Jump();
}

void Jumper::Jump()
{
	//start Jump
	if (bGround)
	{
		if (GetAsyncKeyState(VK_SPACE) & 0x8001)
		{
			velocity = 5;
			bGround = false;
		}
	}
	//Jumping
	velocity -= gravity;
	if (bGround == false)
	{
		pos.Y -= velocity;
	}

	//End Jump
	if (pos.Y > 25)
	{
		pos.Y = 25;
		velocity = 0.0f;
		bGround = true;
	}
}
