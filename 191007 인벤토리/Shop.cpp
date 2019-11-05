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
	//KIND kind;		//����
	//string name;		//�̸�
	//int price;		//����
	//int count;		//���
	Item Weapon1;
	Weapon1.kind = WEAPON;
	Weapon1.count = 1;
	Weapon1.price = 1'000;
	Weapon1.name = "��";
	Weapon1.atk = 100;
	Weapon1.def = 0;

	Item Weapon2;
	Weapon2.kind = WEAPON;
	Weapon2.count = 1;
	Weapon2.price = 1'500;
	Weapon2.name = "����";
	Weapon2.atk = 200;
	Weapon2.def = 0;

	Item Weapon3;
	Weapon3.kind = WEAPON;
	Weapon3.count = 1;
	Weapon3.price = 2'000;
	Weapon3.name = "��";
	Weapon3.atk = 300;
	Weapon3.def = 0;

	Item Armor1;
	Armor1.kind = ARMOR;
	Armor1.count = 1;
	Armor1.name = "õ ��";
	Armor1.price = 2'000;
	Armor1.atk = 0;
	Armor1.def = 100;

	Item Armor2;
	Armor2.kind = ARMOR;
	Armor2.count = 1;
	Armor2.name = "���� ��";
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
	cout << "-------------------����-------------------" << endl;
	for (auto& i : shop)
	{
		if (kind != i.kind) continue; //Kind�� ���� �����ѰͰ� �ٸ����� �ҷ���������
		cout << "��ȣ : " << _count << endl;
		cout << "�̸� : " << i.name << endl;
		cout << "���� : " << i.price << endl;
		//kind�� �����ѰͿ����� ����� �ٸ���
		if (i.kind == WEAPON)
			cout << "���ݷ� : " << i.atk << endl;
		else if (i.kind == ARMOR)
			cout << "���� : " << i.def << endl;
		cout << "��� : ";
		(i.count > 0) ? cout << i.count : cout << "����";
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
		if (kind != i.kind) continue; //Kind�� ���� �����ѰͰ� �ٸ����� �ҷ���������
		if (select == _count) //�Է��ѰͰ� ��ȣ�� ����
		{
			if (gold > i.price)
			{
				if (i.count > 0)
				{
					cout << i.name << " ��(��) " << i.price << "���� ����" << endl;
					i.count--;
					gold -= i.price;
					_new = i; //new = i ���ϸ� �κ��� ��ȣ�� ��
					Sleep(1000);
				}//(i.count > 0)
				else
				{
					cout << "�Ź��� ���� ���ư�" << endl;
					Sleep(1000);
				}
			}// (gold > i.price)
			else
			{
				cout << "���� �����鼭? ���� �������" << endl;
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

