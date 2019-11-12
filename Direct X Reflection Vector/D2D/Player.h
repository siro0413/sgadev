#pragma once
#include "Renders/Rect.h"

class Player : public Rect
{
public:
	Player(wstring shaderFile);
	Player(wstring shaderFile, D3DXVECTOR2 position, D3DXVECTOR2 scale, D3DXCOLOR color = D3DXCOLOR(1, 1, 1, 1));

	~Player();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P) override;

	void moveLeft();
	void moveRight();

	void startJump();
	void endJump();

	void Speed(float val) { speed = val; }
	auto Speed() { return speed; }


private:
	float speed;
	float velocity;
	float gravity;
	bool bGround;

};

