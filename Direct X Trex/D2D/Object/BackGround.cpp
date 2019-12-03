#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround(D3DXVECTOR2 position, D3DXVECTOR2 scale)
	:position(position), scale(1, 1)
{
	wstring shaderFile = L"./_Shader2D/Effect.fx";
	wstring spriteFile = Textures + L"ground.png";
	bg.push_back(new Sprite(spriteFile, shaderFile));
	for (Sprite* back : bg)
	{
		back->Position(1200, -250);
		back->Scale(1.0f, 1.0f);
	}

	clip->Position(position);
	clip->Play();
}

BackGround::~BackGround()
{
	SAFE_DELETE(clip);
}

void BackGround::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	clip->Position(position);

	clip->Update(V, P);
}

void BackGround::Render()
{
	clip->Scale(scale);
	clip->Render();
}

