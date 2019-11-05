#pragma once
#include "stdafx.h"
#include "Shop.h"
#include "Inven.h"
#include "Player.h"

class Menu 
{
public:
	Menu();
	~Menu();
	void GoMain();
	void GoShop();
	void GoBuy(int kind);
	void GoSell();
	void GoInven();

private:
	Shop* shop;
	Player* player;
	int input;
	int Gold;
};

