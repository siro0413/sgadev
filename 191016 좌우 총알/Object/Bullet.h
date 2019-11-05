#pragma once


class Bullet
{
public:
	Bullet(string symbol,COORD start,short speed);
	~Bullet();


	void Update(int val);
	void Render();

	COORD Position() { return postion; }

private:
	string symbol;
	COORD postion;
	short velocity;


};

