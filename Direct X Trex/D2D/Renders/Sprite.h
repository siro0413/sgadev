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

	void DrawBound(bool val) { bDrawBound = val; }//한장기준
	void DrawColision(bool val) { bDrawColision = val; }


	bool Aabb(D3DXVECTOR2 position) { return Aabb(this, position); } // 자기자신
	bool Aabb(Sprite* b) { return Aabb(this, b); }

	bool Obb(Sprite* b) { return Obb(this, b); }

	static bool Aabb(Sprite* sprite, D3DXVECTOR2 position); // 아무때나
	static bool Aabb(Sprite* a, Sprite* b);
	static bool Obb(Sprite* a, Sprite* b);

	void Position(float x, float y);
	void Position(D3DXVECTOR2& vec);
	auto Position() { return position; }

	void Scale(float x, float y);
	void Scale(D3DXVECTOR2& vec);
	auto Scale() { return scale; }

	void Rotation(float x, float y, float z);
	void Rotation(D3DXVECTOR3& vec);
	auto Rotation() { return rotation; }

	void RotationDegree(float x, float y, float z);
	void RotationDegree(D3DXVECTOR3& vec);
	D3DXVECTOR3 RotationDegree();

	D3DXVECTOR2 TextureSize() { return textureSize; }
	////////////OBB
	struct ObbDesc
	{
		D3DXVECTOR2 Position;
		D3DXVECTOR2 Direction[2]; //[0]수평 ,[1]수직
		float Length[2]; //단위(방향)벡터에 곱
	};
	static void CreateObb(OUT ObbDesc* out, IN D3DXVECTOR2& position, D3DXMATRIX& world, D3DXVECTOR2 length);
	//position : 충돌 체크를 시작할 위치
	//world : 회전 방향
	//lenth : 얼만큼의 길이를 체크할지
	static float SeparateAxis(D3DXVECTOR2& separate, D3DXVECTOR2& e1, D3DXVECTOR2& e2);

	static bool CheckObb(ObbDesc& obbA, ObbDesc& obbB);
private:
	Shader* shader;
	Shader* boundShader;
	ID3D11Buffer* vertexBuffer;
	ID3D11Buffer* boundVertexBuffer;

	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	D3DXVECTOR2 textureSize;
	D3DXVECTOR3 rotation;
	D3DXMATRIX world;

	wstring textureFile;
	ID3D11ShaderResourceView* srv; //ID3D11ShaderResourceView* SRV = NULL; 리턴값을 여기저장

	bool bDrawBound;
	bool bDrawColision;
	struct Vertex
	{
		D3DXVECTOR3 Position;
		D3DXVECTOR2 Uv;
	};
	struct BoundVertex
	{
		D3DXVECTOR3 position;
	};

	void Initialize(wstring spriteFile, wstring shaderFile, float startX, float startY, float endX, float endY);
	void CreateBound();

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

