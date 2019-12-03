#pragma once

enum class PlayMode { End = 0, Loop, Reverse };
struct Frame
{
	Sprite* Image;	//�׸� ��������
	float Time;		//�׸��� ����� �ð�

	Frame(Sprite* sprite, float time);
	~Frame();
};


class Clip
{
public:
	Clip(PlayMode mode = PlayMode::End, float speed = 1.0f);
	~Clip();


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

	void AddFrame(Sprite* sprite, float time);
	D3DXVECTOR2 TexturSize();

	//��� ����
	void Play();
	void Play(UINT startFrame);
	void Stop();

	void Update(D3DXMATRIX& V, D3DXMATRIX& P);
	void Render();
	void DrawBound(bool val);

	Sprite* GetSprite();

private:
	D3DXVECTOR2 position;
	D3DXVECTOR2 scale;
	D3DXVECTOR3 rotation;

	float length; //Clip�� ��ü ����
	float speed;  //���ó��(Play Speed)
	bool bPlay;   //Clip�� ��� ���� ���� �Ǻ�
	UINT currentFrame; //���� �÷��� ���� ������ ��ȣ
	float playTime; //Timer

	PlayMode mode;

	vector<Frame*> frames;
};

