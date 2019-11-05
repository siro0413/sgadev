#pragma once


class Shop
{
public:
	Shop();
	~Shop();

	int ShowItem(int kind);
	Item Buy(int kind, int select, int& money);
	void AddItem(Item _item);

private:
	vector<Item> items;
	vector<Item>::iterator iter;


};

