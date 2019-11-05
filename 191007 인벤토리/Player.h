#pragma once
#include"Inven.h"


class Player : public Inven
{

public:
	Player();
	~Player();

	void Status();

private:
	int atk;
	int def;

};

