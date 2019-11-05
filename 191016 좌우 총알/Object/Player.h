#pragma once



class Player
{
public:
	Player(string symbol);
	~Player();

	virtual void Update();
	void Render(COLOR color = COLOR::DEFAULT);

	void Position(COORD val) { pos = val; }
	COORD Position() { return pos; }

	void MoveSpeed(short val) { moveSpeed = val; }
	short MoveSpeed() { return moveSpeed; }
	
protected:
	string symbol;
	COORD pos;
	short moveSpeed;
	void Move();
};
