#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(wstring shaderFile, D3DXVECTOR2 start, float angle, float speed)
{
	sprite = new Sprite(Textures + L"bullet.png", shaderFile, 2, 120, 22, 143);

	position = start;
	sprite->Position(position);
	//degree -> °¢µµ
	//radian 
	//d -> r : D* PI /180
	float radian = Math::ToRadian(angle);
	velocity.x = cosf(radian);
	velocity.y = sinf(radian);
	velocity *= speed;

}

Bullet::~Bullet()
{
	SAFE_DELETE(sprite);
}

void Bullet::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	ReflectionVector(velocity);
	sprite->Position(position);
	if (position.x < 0 || position.x > Width)
		velocity.x = -velocity.x;

	else if (position.y < 0 || position.y > Height)
		velocity.y = -velocity.y;


	position += velocity;
	sprite->Update(V, P);
}

void Bullet::Render()
{
	sprite->Render();
}

D3DXVECTOR2 Bullet::ReflectionVector(D3DXVECTOR2 velocity)
{
	return velocity + 2 * nomalVector*D3DXVec2Dot(&-velocity, &nomalVector);
}
