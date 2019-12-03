#include "stdafx.h"
#include "FreeCamera.h"

FreeCamera::FreeCamera(float speed)
	:speed(speed)
{
}

FreeCamera::~FreeCamera()
{
}

void FreeCamera::Positon(float x, float y)
{
	Position(D3DXVECTOR2(x, y));
}

void FreeCamera::Position(D3DXVECTOR2 & vec)
{
	position = vec;
}

void FreeCamera::Update()
{
	if (Key->Press('A'))
		Move(D3DXVECTOR2(-1, 0)*speed);
	else if (Key->Press('D'))
		Move(D3DXVECTOR2(1, 0)*speed);

	if (Key->Press('W'))
		Move(D3DXVECTOR2(0, 1)*speed);
	else if (Key->Press('S'))
		Move(D3DXVECTOR2(0, -1)*speed);

	__super::Update();
}

void FreeCamera::Move(D3DXVECTOR2 translation)
{
	position += translation * Time::Delta();

}
