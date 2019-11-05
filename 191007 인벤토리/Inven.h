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

protected: //Player�� ������������ ��ӹ޾ƾ���
	vector<Item> inven;
	vector<Item>::iterator iter;
	//���� ���
	Item MyAr;
	Item MyWe;
};

