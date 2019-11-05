#include "stdafx.h"
#include "Inven.h"


Inven::Inven()
	:atk(100),def(100),gold(50'000)
{
	Item default_W =
	{
		EMPTY,
		"<맨손>","",
		0,0,0,1
	};

	Item default_A =
	{
		EMPTY,
		"<맨몸>","",
		0,0,0,1
	};
	equiW = default_W;
	equiA = default_A;

}

Inven::~Inven()
{
}

void Inven::ShowStatus()
{

	cout << "--------------------<스탯>--------------------" << endl;
	cout << "공격력\t: " << atk + equiW.atk << "(" << equiW.atk << ")" << endl;
	cout << "방어력\t: " << atk + equiA.def << "(" << equiA.def << ")" << endl;
	cout << "--------------------<장비>--------------------" << endl;
	cout << "무기 : " << equiW.name << endl;
	cout << "갑옷 : " << equiA.name << endl;

}

int Inven::ShowInven()
{
	int index = 0;
	for (Item& i : items)
	{
		cout << "번호 : " << index + 1 << endl;
		cout << "이름 : " << i.name << endl;
		switch (i.kind)
		{
		case WEAPON:cout << "공격력 : " << i.atk << endl; break;
		case ARMOR: cout << "방어력 : " << i.def << endl; break;
		}
		cout << "----------------------------------------------" << endl;
		index++;
	}

	return index;
}

Item Inven::Sell(int select, int & gold)
{
	Item temp;
	iter = items.begin() + (select - 1);
	temp = *iter;

	items.erase(iter);
	cout << temp.name << " 을(를) " << temp.price / 2 << " Gold에 팔았습니다." << endl;

	return temp;
}

void Inven::AddItem(Item _item)
{
	items.push_back(_item);
}

void Inven::Equip(int select)
{
	iter = items.begin() + (select - 1);

	Item prev = equiW;
	
	switch (iter->kind)
	{

	case WEAPON:
	{
		prev = equiW;
		equiW = *iter;
		items.erase(iter);
		if (prev.kind == WEAPON)
			items.push_back(prev);
	}
	break;
	case ARMOR:
	{
		prev = equiA;
		equiA = *iter;
		items.erase(iter);
		if (prev.kind == ARMOR)
			items.push_back(prev);
	}
	break;
	default:
		cout << "그런종류의 아이템이 없다." << endl;
		break;
	}

}
