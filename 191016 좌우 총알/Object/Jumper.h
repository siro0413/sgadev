#pragma once

class Jumper : public Player
{
public:
	Jumper(string symbol);
	~Jumper();


	//��� ���� �Լ��� virtual �� ���̸� �����ε��̾ȵȴ�.
	//�����ε� : ���� �̸��� �Լ��� ����
	//�������̵� : �θ� Ŭ������ �Լ��� �ڽ��Ǽ� ������
	void Update() override;


	void SetGroundPos(short y) { groundPos = y; }

	bool RShoot() { return bRShoot; }
	void RShoot(bool val) { bRShoot = val; }
	bool LShoot() { return bLShoot; }
	void LShoot(bool val) { bLShoot = val; }

private:
	bool bGround;
	UINT velocity; //���� ����
	UINT gravity;
	short groundPos;
	bool bLShoot;
	bool bRShoot;
	void Jump();
};

