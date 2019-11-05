#include "stdafx.h"
#include "Inven.h"

Inven::Inven()
{
	Item First1;//초기장비
	First1.atk = 10;
	First1.kind = WEAPON;
	First1.def = 0;
	First1.name = "초기장비";
	First1.price = 0;

	Item First2;//초기장비
	First2.atk = 0;
	First2.kind = ARMOR;
	First2.def = 10;
	First2.name = "초기장비";
	First2.price = 0;

	MyAr = First1;
	MyWe = First2;
}

Inven::~Inven()
{
}

int Inven::ViewInven()
{
	int _count = 1;
	cout << "-------------------인벤-------------------" << endl;
	for (auto& i : inven)
	{
		cout << "번호 : " << _count << endl;
		cout << "이름 : " << i.name << endl;
		if (i.kind == WEAPON)
			cout << "공격력 : " << i.atk << endl;
		else if (i.kind == ARMOR)
			cout << "방어력 : " << i.def << endl;
		cout << endl << endl;

		_count++;
	}
	if (inven.empty())
		cout << "You no hane Item" << endl;

	return _count - 1;


}

void Inven::Push_Item(Item item)
{
	if (item.kind == WEAPON || item.kind == ARMOR)
		inven.push_back(item);
}

Item Inven::Sell(int select, int & gold)
{
	Item temp;
	iter = inven.begin() + (select - 1);
	temp = *iter;
	inven.erase(iter);
	cout << temp.name << "을(를) " << temp.price / 2 << "원에 팔았다" << endl
		<< "어서와 호갱님" << endl;
	
	gold += temp.price / 2;
	return temp;
	//temp를 넣은이유는
	//*iter를 넣으면 주소값이 터짐
}

void Inven::MyItem(int select)
{
	Item temp;
	iter = inven.begin() + (select - 1);

	if (iter->kind == WEAPON)
	{
		temp = GetWeapon();
		SetWeapon(*iter);
		inven.erase(iter);
		if (temp.kind == WEAPON)
			inven.push_back(temp);
	}
	else if (iter->kind == ARMOR)
	{
		temp = GetArmor();
		SetArmor(*iter);
		inven.erase(iter);
		if (temp.kind == ARMOR)
			inven.push_back(temp);
	}
	else 
		cout << "메뉴 번호좀 골라" << endl;


}
