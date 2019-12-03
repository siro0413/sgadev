#pragma once


class Bullet
{
public:
	Bullet(wstring shaderFile, D3DXVECTOR2 start, int type);
	~Bullet();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();

	Clip* GetClip() { return clip; }
	Animation* GetAnimation() { return ani; }

	void Position(float x, float y);
	void Position(D3DXVECTOR2& vec);
	auto Position() { return position; }

private:
	Clip* clip;
	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	bool check;
	Animation* ani;


};

	/*else if (type == 6)
	{
	wstring textureFile = Textures + L"bird.png";
	clip = new Clip(PlayMode::Loop);
	clip->AddFrame(new Sprite(textureFile, shaderFile, 92, 82), 0.15f);
	clip->AddFrame(new Sprite(textureFile, shaderFile, 92, 0, 184, 82), 0.15f);
	}*/