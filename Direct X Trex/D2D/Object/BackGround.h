#pragma once


class BackGround
{
public:
	BackGround(D3DXVECTOR2 position, D3DXVECTOR2 scale);
	~BackGround();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();

	Clip* GetClip() { return clip; }
	auto Position() { return position; }



private:
	Clip* clip;
	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;

	vector<Sprite*> bg;
};

