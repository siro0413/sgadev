#pragma once


class BackGround
{
public:
	BackGround(wstring shaderFile);
	~BackGround();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();



private:
	Sprite* cloud[2];
	Sprite* bush[2];
	Sprite* tile[2];
};

