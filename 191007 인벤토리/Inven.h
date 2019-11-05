#pragma once
#include "stdafx.h"


class Inven
{

public:
	Inven();
	~Inven();

	int ViewInven();
	void Push_Item(Item item);
	Item Sell(int select, int& gold);
	void MyItem(int select);

	Item GetArmor() { return MyAr; }
	void SetArmor(Item item) { MyAr = item; }

	Item GetWeapon() { return MyWe; }
	void SetWeapon(Item item) { MyWe = item; }

protected: //Player가 내부정보들을 상속받아야함
	vector<Item> inven;
	vector<Item>::iterator iter;
	//장착 장비
	Item MyAr;
	Item MyWe;
};

