#pragma once


class Portal
{
public:
	Portal(string symbol);
	~Portal();

	void Update();
	void Render();
	COORD Pos() { return pos; }
	void Pos(COORD val) { pos = val; }



private:

	string symbol;
	COORD pos;
	COLOR color;
	UINT prevTime;
	int index;

	void ChangeColor();
};
