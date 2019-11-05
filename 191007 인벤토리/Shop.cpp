#include "stdafx.h"
#include "Shop.h"
#include "Inven.h"
Shop::Shop()
{
}

Shop::~Shop()
{
}

void Shop::SetItem()
{
	//KIND kind;		//종류
	//string name;		//이름
	//int price;		//가격
	//int count;		//재고
	Item Weapon1;
	Weapon1.kind = WEAPON;
	Weapon1.count = 1;
	Weapon1.price = 1'000;
	Weapon1.name = "검";
	Weapon1.atk = 100;
	Weapon1.def = 0;

	Item Weapon2;
	Weapon2.kind = WEAPON;
	Weapon2.count = 1;
	Weapon2.price = 1'500;
	Weapon2.name = "도끼";
	Weapon2.atk = 200;
	Weapon2.def = 0;

	Item Weapon3;
	Weapon3.kind = WEAPON;
	Weapon3.count = 1;
	Weapon3.price = 2'000;
	Weapon3.name = "총";
	Weapon3.atk = 300;
	Weapon3.def = 0;

	Item Armor1;
	Armor1.kind = ARMOR;
	Armor1.count = 1;
	Armor1.name = "천 방어구";
	Armor1.price = 2'000;
	Armor1.atk = 0;
	Armor1.def = 100;

	Item Armor2;
	Armor2.kind = ARMOR;
	Armor2.count = 1;
	Armor2.name = "가죽 방어구";
	Armor2.price = 4'000;
	Armor2.atk = 0;
	Armor2.def = 200;

	shop.push_back(Weapon1);
	shop.push_back(Weapon2);
	shop.push_back(Weapon3);
	shop.push_back(Armor1);
	shop.push_back(Armor2);


}

int Shop::SetShop(int kind)
{
	int _count = 1;
	system("cls");
	cout << "-------------------상점-------------------" << endl;
	for (auto& i : shop)
	{
		if (kind != i.kind) continue; //Kind가 내가 선택한것과 다른것은 불러오지마라
		cout << "번호 : " << _count << endl;
		cout << "이름 : " << i.name << endl;
		cout << "가격 : " << i.price << endl;
		//kind로 설정한것에따라 출력을 다르게
		if (i.kind == WEAPON)
			cout << "공격력 : " << i.atk << endl;
		else if (i.kind == ARMOR)
			cout << "방어력 : " << i.def << endl;
		cout << "재고 : ";
		(i.count > 0) ? cout << i.count : cout << "매진";
		_count++;
		cout << endl << endl;
	}
	if (shop.empty())
		cout << "Sell All Item" << endl;

	return _count - 1;
}

Item Shop::Buy(int kind, int select, int & gold)
{
	Item _new;
	int _count = 1;
	for (auto& i : shop)
	{
		if (kind != i.kind) continue; //Kind가 내가 선택한것과 다른것은 불러오지마라
		if (select == _count) //입력한것과 번호가 동일
		{
			if (gold > i.price)
			{
				if (i.count > 0)
				{
					cout << i.name << " 을(를) " << i.price << "원에 구입" << endl;
					i.count--;
					gold -= i.price;
					_new = i; //new = i 안하면 인벤에 번호만 들어감
					Sleep(1000);
				}//(i.count > 0)
				else
				{
					cout << "매물이 없어 돌아가" << endl;
					Sleep(1000);
				}
			}// (gold > i.price)
			else
			{
				cout << "돈도 없으면서? 가서 돈벌어와" << endl;
				Sleep(1000);
			}
			break;
		}//(select == _count)
		_count++;
	}

	return _new;
}

void Shop::Sell(Item item)
{

	for (auto& i : shop)
	{
		if (item.kind != i.kind) continue;
		i.count++;
		break;
	}

}

