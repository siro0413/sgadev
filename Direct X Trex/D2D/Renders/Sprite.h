#pragma once

class Sprite
{
public:
	Sprite(wstring textureFile, wstring shaderFile);
	//����¥��
	Sprite(wstring textureFile, wstring shaderFile, float endX, float endY);
	//startX,Y �� 0���� ������ endX,Y
	Sprite(wstring textureFile, wstring shaderFile, float startX, float startY, float endX, float endY);
	//�̹��� ��ü�� > �߰��� �ִ� �̹��� (sprite image)

	virtual ~Sprite();

	virtual void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();

	void DrawBound(bool val) { bDrawBound = val; }//�������
	void DrawColision(bool val) { bDrawColision = val; }


	bool Aabb(D3DXVECTOR2 position) { return Aabb(this, position); } // �ڱ��ڽ�
	bool Aabb(Sprite* b) { return Aabb(this, b); }

	bool Obb(Sprite* b) { return Obb(this, b); }

	static bool Aabb(Sprite* sprite, D3DXVECTOR2 position); // �ƹ�����
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
		D3DXVECTOR2 Direction[2]; //[0]���� ,[1]����
		float Length[2]; //����(����)���Ϳ� ��
	};
	static void CreateObb(OUT ObbDesc* out, IN D3DXVECTOR2& position, D3DXMATRIX& world, D3DXVECTOR2 length);
	//position : �浹 üũ�� ������ ��ġ
	//world : ȸ�� ����
	//lenth : ��ŭ�� ���̸� üũ����
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
	ID3D11ShaderResourceView* srv; //ID3D11ShaderResourceView* SRV = NULL; ���ϰ��� ��������

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
		UINT RefCount = 0; //Load�Ҷ����� ++ Remove�ҋ� --
		ID3D11ShaderResourceView* SRV = NULL;
	};



	static map<wstring, SpriteDesc> spriteMap;

};

