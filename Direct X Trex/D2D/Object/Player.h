#pragma once
#include "Viewer/IFollow.h"

class Player : public IFollow
{
public:
	Player(D3DXVECTOR2 position, D3DXVECTOR2 scale);
	~Player();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();

	void Focus(D3DXVECTOR2* position, D3DXVECTOR2* size) override;
	void StartJump();
	void EndJump();


	void Position(float x, float y);
	void Position(D3DXVECTOR2 vec);
	D3DXVECTOR2 Position() { return ani->Position(); }

	Sprite* GetSprite();
	Animation* GetAnimation() { return ani; }


private:
	float moveSpeed;
	Animation* ani;
	D3DXVECTOR2 focusOffest;
	bool bGround;
	float velocity;
	float gravity;
};

