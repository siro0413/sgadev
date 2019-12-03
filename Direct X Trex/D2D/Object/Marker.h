#pragma once

//cloud
class Marker
{
public:
	Marker(wstring shaderFile, D3DXVECTOR2 start);
	~Marker();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();

	Sprite* GetSprite() { return sp; }
	void Position(float x, float y);
	void Position(D3DXVECTOR2& vec);
	auto Position() { return position; }

private:
	Sprite* sp;
	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;

};

