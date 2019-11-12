#include "stdafx.h"
#include "Player.h"

Player::Player(wstring shaderFile)
	:Rect(shaderFile),
	speed(1.0f),
	velocity(0.0f),
	gravity(-2.5f),
	bGround(true)
{
}

Player::Player(wstring shaderFile, D3DXVECTOR2 position, D3DXVECTOR2 scale, D3DXCOLOR color)
	: Rect(shaderFile, position, scale, color),
	speed(1.0f),
	velocity(0.0f),
	gravity(-2.5f),
	bGround(true)

{
}

Player::~Player()
{
}

void Player::Update(D3DXMATRIX& V, D3DXMATRIX& P)
{
	Rect::Update(V,P);
	D3DXVECTOR2 pos = Position();
	velocity += gravity * Time::Delta();

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
	pos.x -= speed * Time::Delta();
	Position(pos);

}

void Player::moveRight()
{
	D3DXVECTOR2 pos = Position();
	pos.x += speed*Time::Delta();
	Position(pos);
}

void Player::startJump()
{
	if (bGround == true)
	{
		velocity = 0.5f;
		bGround = false;
	}
}

void Player::endJump()
{
	if (velocity > 0.08f)
		velocity = 0.08f;
}
