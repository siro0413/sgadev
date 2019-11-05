#pragma once

class Inven
{
public:
	Inven();
	~Inven();


	void ShowStatus();
	int ShowInven();

	Item Sell(int select, int& gold);
	void AddItem(Item _item);
	void Equip(int select);
	void EquipW(Item item) { equiW = item; }
	Item EquipW() { return equiW; }

	void EquipA(Item item) { equiA = item; }
	Item EquipA() { return equiA; }

	void Money(int money) { this->gold = money;}
	int Money() { return gold; }
private:
	int atk;
	int def;
	int gold;

	vector<Item> items;
	vector<Item>::iterator iter;

	Item equiW;
	Item equiA;

};

