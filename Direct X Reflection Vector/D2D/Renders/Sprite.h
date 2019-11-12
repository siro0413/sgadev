#pragma once

class Sprite
{
public:
	Sprite(wstring textureFile, wstring shaderFile);
	//한장짜리
	Sprite(wstring textureFile, wstring shaderFile, float endX, float endY);
	//startX,Y 는 0으로 나머진 endX,Y
	Sprite(wstring textureFile, wstring shaderFile, float startX, float startY, float endX, float endY);
	//이미지 통체로 > 중간에 있는 이미지 (sprite image)

	virtual ~Sprite();

	virtual void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();


	void Position(float x, float y);
	void Position(D3DXVECTOR2& vec);
	auto Position() { return position; }

	void Scale(float x, float y);
	void Scale(D3DXVECTOR2& vec);
	auto Scale() { return scale; }


private:
	Shader* shader;
	ID3D11Buffer* vertexBuffer;

	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	D3DXVECTOR2 textureSize;

	wstring textureFile;
	ID3D11ShaderResourceView* srv; //ID3D11ShaderResourceView* SRV = NULL; 리턴값을 여기저장

	struct Vertex
	{
		D3DXVECTOR3 Position;
		D3DXVECTOR2 Uv;
	};

	void UpdateWorld();
	void Initialize(wstring spriteFile, wstring shaderFile, float startX, float startY, float endX, float endY);

};

///////////////////////////////////////////////////////////////////////
class Sprites
{
private:
	friend class Sprite;

	static ID3D11ShaderResourceView* Load(wstring file);
	static void Remove(wstring file);

	struct  SpriteDesc
	{
		UINT RefCount = 0; //Load할때마다 ++ Remove할떄 --
		ID3D11ShaderResourceView* SRV = NULL;
	};
	static map<wstring, SpriteDesc> spriteMap;

};

