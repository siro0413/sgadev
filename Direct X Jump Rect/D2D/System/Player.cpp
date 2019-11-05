#include "stdafx.h"
#include "Player.h"

Player::Player(wstring shaderFile)
	:Rect(shaderFile),
	speed(0.1f),
	velocity(0.0f),
	gravity(0.5f),
	bGround(true)
{
}

Player::Player(wstring shaderFile, D3DXVECTOR2 position, D3DXVECTOR2 scale, D3DXCOLOR color)
	:Rect(shaderFile, position, scale),
	speed(0.1f),
	velocity(0.0f),
	gravity(0.5f),
	bGround(true)
{
}

Player::~Player()
{
}

void Player::Update()
{
	Rect::Update();
	D3DXVECTOR2 pos = Position();
	velocity -= gravity * 0.0015f;

	//Jump
	if (bGround == false)
	{
		pos.y += velocity;
		Position(pos);
	}

	if (pos.y < Scale().y * 0.5f)
	{
		pos.y = Scale().y * 0.5f;
		velocity = 0.0f;
		bGround = true;
		Position(pos);
	}
}

void Player::moveLeft()
{
	D3DXVECTOR2 pos = Position();
	pos.x -= speed;
	Position(pos);
}

void Player::moveRight()
{
	D3DXVECTOR2 pos = Position();
	pos.x += speed;
	Position(pos);
}



void Player::startJump()
{
	if (bGround == true)
	{
		velocity = 1.0f;
		bGround = false;
	}
}

void Player::endJump()
{
	if (velocity > 0.25f)
		velocity = 0.25f;
}
