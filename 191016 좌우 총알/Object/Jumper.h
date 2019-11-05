#pragma once

class Jumper : public Player
{
public:
	Jumper(string symbol);
	~Jumper();


	//상속 받을 함수에 virtual 을 붙이면 오버로딩이안된다.
	//오버로딩 : 같은 이름의 함수를 재사용
	//오버라이딩 : 부모 클래스의 함수를 자식의서 재정의
	void Update() override;


	void SetGroundPos(short y) { groundPos = y; }

	bool RShoot() { return bRShoot; }
	void RShoot(bool val) { bRShoot = val; }
	bool LShoot() { return bLShoot; }
	void LShoot(bool val) { bLShoot = val; }

private:
	bool bGround;
	UINT velocity; //점프 높이
	UINT gravity;
	short groundPos;
	bool bLShoot;
	bool bRShoot;
	void Jump();
};

