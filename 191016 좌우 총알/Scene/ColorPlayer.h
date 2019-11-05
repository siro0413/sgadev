#pragma once


class ColorPlayer 
{
public:

	ColorPlayer();
	~ColorPlayer();

	void Update();
	void Render();

private:
	class Jumper* jumper;
	vector<class Bullet*> bullets;
	vector<class Bullet*> bullets2;
};

