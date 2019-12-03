#include "stdafx.h"
#include "Marker.h"

Marker::Marker(wstring shaderFile, D3DXVECTOR2 start)
	:position(start), scale(1, 1)
{
	wstring TextureFile = Textures + L"cloud.png";
	sp= new Sprite(TextureFile, shaderFile);

	sp->Position(position);
}

Marker::~Marker()
{
	SAFE_DELETE(sp);

}
void Marker::Position(float x, float y)
{
	D3DXVECTOR2 pos = D3DXVECTOR2(x, y);
	Position(pos);
}

void Marker::Position(D3DXVECTOR2 & vec)
{
	position = vec;
	sp->Position(vec);
}
void Marker::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	sp->Position(position);
	sp->Update(V, P);
}

void Marker::Render()
{
	sp->Render();

}

