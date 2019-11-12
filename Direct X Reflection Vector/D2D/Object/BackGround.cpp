#include "stdafx.h"
#include "BackGround.h"

BackGround::BackGround(wstring shaderFile)
{
	wstring textureFile = L"";

	textureFile = L"./_Textures/Cloud.png";
	cloud[0] = new Sprite(textureFile, shaderFile, 137, 128);
	cloud[1] = new Sprite(textureFile, shaderFile, 144, 0, 336, 128);

	textureFile = L"./_Textures/Bush.png";
	bush[0] = new Sprite(textureFile, shaderFile);

	textureFile = L"./_Textures/Bush2.png";
	bush[1] = new Sprite(textureFile, shaderFile);

	textureFile = L"./_Textures/Tile.png";
	tile[0] = new Sprite(textureFile, shaderFile);
	tile[1] = new Sprite(textureFile, shaderFile, 0, 66, 0, 0);
}

BackGround::~BackGround()
{
	SAFE_DELETE(tile[1]);
	SAFE_DELETE(tile[0]);
	SAFE_DELETE(bush[1]);
	SAFE_DELETE(bush[0]);
	SAFE_DELETE(cloud[1]);
	SAFE_DELETE(cloud[0]);
}

void BackGround::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	cloud[0]->Update(V, P);
	cloud[1]->Update(V, P);
	bush[0]->Update(V, P);
	bush[1]->Update(V, P);
	tile[0]->Update(V, P);
	tile[1]->Update(V, P);
}

void BackGround::Render()
{
	cloud[0]->Position(40, 420);
	cloud[0]->Render();
	cloud[0]->Position(200, 420);
	cloud[0]->Render();
	cloud[1]->Position(500, 420);
	cloud[1]->Render();

	bush[1]->Position(-50, 170);
	bush[1]->Render();

	bush[1]->Position(300, 170);
	bush[1]->Render();

	bush[1]->Position(600, 170);
	bush[1]->Render();

	bush[0]->Position(100, 170);
	bush[0]->Render();

	bush[0]->Position(650, 170);
	bush[0]->Render();

	float tileWidth = tile[0]->Scale().x;	//128px
	float tileHeight= tile[0]->Scale().y;	//128px

	for (int i = 0; i < 7; i++)
	{
		tile[0]->Position((float)i*tileWidth, 45);
		tile[0]->Render();

		tile[1]->Position((float)i*tileWidth, 0);
		tile[1]->Render();
	}
}
