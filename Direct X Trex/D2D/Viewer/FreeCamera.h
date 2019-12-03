#pragma once
#include "Camera.h"

class FreeCamera : public Camera
{
public:
	FreeCamera(float speed = 200.0f);
	~FreeCamera();

	void Positon(float x, float y);
	void Position(D3DXVECTOR2& vec);

	void Update();

private:
	float speed;
	//��ӹ��� position�� ����

	void Move(D3DXVECTOR2 translation);
};

