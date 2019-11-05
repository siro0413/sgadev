#pragma once


//Vertex Position, Color, World(S,T), Buffer, Shader

class Rect
{
public:
	Rect(wstring shaderFile);
	Rect(wstring shaderFile, D3DXVECTOR2 position, D3DXVECTOR2 scale, D3DXCOLOR color = D3DXCOLOR(1, 1, 1, 1));
	virtual ~Rect();

	virtual void Update();
	void Render();

	void ViewProjection(D3DXMATRIX& V, D3DXMATRIX& P);

	void Position(float x, float y);
	void Position(D3DXVECTOR2& vec);
	auto Position() { return position; }

	void Scale(float x, float y);
	void Scale(D3DXVECTOR2& vec);
	auto Scale() { return scale; }

	void Color(float r, float g, float b);
	void Color(D3DXCOLOR& vec);
	auto Color() { return color; }

private:
	D3DXVECTOR2 position; // T¿¡ ÇÒ´ç
	D3DXVECTOR2 scale;
	D3DXCOLOR color;

	struct Vertex
	{
		D3DXVECTOR3 Pos;
		D3DXCOLOR Color;
	};

	Shader* shader;
	ID3D11Buffer* vertexBuffer;

	void CreateBuffer(wstring shaderFile);
	void UpdateWorld();
};

