#include "stdafx.h"
#include "Player.h"

Player::Player(D3DXVECTOR2 position, D3DXVECTOR2 scale)
	:moveSpeed(200.0f), focusOffest(180,140), bGround(true), velocity(0), gravity(0.5f)
{
	ani = new Animation();
	wstring shaderFile = L"./_Shader2D/Effect.fx";
	wstring spriteFile = Textures + L"trex.png";
	Clip* clip;

	//Trex Idle
	{
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(spriteFile, shaderFile, 0, 0, 88, 94),5.0f);
		ani->AddClip(clip);
	}
	//Trex Move
	{
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(spriteFile, shaderFile, 87, 0, 176, 94),0.2f);
		clip->AddFrame(new Sprite(spriteFile, shaderFile, 175, 0, 264, 94),0.2f);
		ani->AddClip(clip);
	}
	//Trex Dead
	{
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(spriteFile, shaderFile, 263, 0, 352, 94), 5.0f);
		ani->AddClip(clip);
	}
	//Trex Down
	{
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(spriteFile, shaderFile, 355, 37, 466, 90), 0.2f);
		clip->AddFrame(new Sprite(spriteFile, shaderFile, 473, 37, 584, 90), 0.2f);
		ani->AddClip(clip);
	}

	ani->Position(position);
	ani->Scale(scale);
	ani->Play(0);
}

Player::~Player()
{
	SAFE_DELETE(ani);

}

void Player::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	D3DXVECTOR2 position = ani->Position();


	if (Key->Down(VK_SPACE))
		StartJump();
	else if (Key->Up(VK_SPACE))
		EndJump();

	if (Key->Down(VK_DOWN))
		ani->Play(3);
	else if (Key->Up(VK_DOWN))
		ani->Play(1);

	velocity -= gravity * 0.0015f;

	//Jump
	if (bGround == false)
	{
		position.y += velocity;
	}

	if (position.y < -170)
	{
		position.y = -170;
		velocity = 0.0f;
		bGround = true;
	}

	ani->Position(position);
	ani->Update(V, P);

}

void Player::Render()
{
	//ImGui::SliderFloat("Move Speed", &moveSpeed, 50, 400);
	ani->Render();
}

void Player::Focus(D3DXVECTOR2 * position, D3DXVECTOR2 * size)
{
	*position = ani->Position() + focusOffest;
	*size = D3DXVECTOR2(1, 1);
}


void Player::StartJump()
{
	if (bGround == true)
	{
		velocity = 0.7f;
		bGround = false;
	}
}

void Player::EndJump()
{
	if (velocity > 0.25f)
		velocity = 0.25f;
}

void Player::Position(float x, float y)
{
	Position(D3DXVECTOR2(x, y));
}

void Player::Position(D3DXVECTOR2 vec)
{
	ani->Position(vec);
}


Sprite * Player::GetSprite()
{
	return ani->GetSprite();
}
