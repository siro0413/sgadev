#include "stdafx.h"
#include "Bullet.h"

Bullet::Bullet(wstring shaderFile, D3DXVECTOR2 start, int type)
	:scale(1, 1), position(start), check(false)
{
	if (type < 6)
	{
		wstring textureFile = Textures + L"cactus.png";
		clip = new Clip(PlayMode::Loop);

		switch (type)
		{
		case 0:
			clip->AddFrame(new Sprite(textureFile, shaderFile, 34, 70), 0.2f);
			break;
		case 1:
			clip->AddFrame(new Sprite(textureFile, shaderFile, 34, 0, 102, 70), 0.2f);
			break;
		case 2:
			clip->AddFrame(new Sprite(textureFile, shaderFile, 102, 0, 204, 70), 0.2f);
			break;
		case 3:
			clip->AddFrame(new Sprite(textureFile, shaderFile, 207, 0, 302, 100), 0.2f);
			break;
		case 4:
			clip->AddFrame(new Sprite(textureFile, shaderFile, 307, 0, 504, 100), 0.2f);
			break;

		}
	}
	else if (type == 5)
	{
		wstring textureFile = Textures + L"bird.png";
		clip = new Clip(PlayMode::Loop);
		clip->AddFrame(new Sprite(textureFile, shaderFile, 92, 82), 0.15f);
		clip->AddFrame(new Sprite(textureFile, shaderFile, 92, 0, 184, 82), 0.15f);
	}

	clip->Position(start);
	clip->Play();
}

Bullet::~Bullet()
{
	SAFE_DELETE(clip);
}

void Bullet::Position(float x, float y)
{
	D3DXVECTOR2 pos = D3DXVECTOR2(x, y);
	Position(pos);
}

void Bullet::Position(D3DXVECTOR2 & vec)
{
	position = vec;
	clip->Position(vec);
}

void Bullet::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	clip->Position(position);
	clip->Update(V, P);
}

void Bullet::Render()
{
	clip->Scale(scale);
	clip->Render();
}

