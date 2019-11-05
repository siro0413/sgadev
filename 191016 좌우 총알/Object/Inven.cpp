#include "stdafx.h"
#include "Inven.h"


Inven::Inven()
	:atk(100),def(100),gold(50'000)
{
	Item default_W =
	{
		EMPTY,
		"<�Ǽ�>","",
		0,0,0,1
	};

	Item default_A =
	{
		EMPTY,
		"<�Ǹ�>","",
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

	cout << "--------------------<����>--------------------" << endl;
	cout << "���ݷ�\t: " << atk + equiW.atk << "(" << equiW.atk << ")" << endl;
	cout << "����\t: " << atk + equiA.def << "(" << equiA.def << ")" << endl;
	cout << "--------------------<���>--------------------" << endl;
	cout << "���� : " << equiW.name << endl;
	cout << "���� : " << equiA.name << endl;

}

int Inven::ShowInven()
{
	int index = 0;
	for (Item& i : items)
	{
		cout << "��ȣ : " << index + 1 << endl;
		cout << "�̸� : " << i.name << endl;
		switch (i.kind)
		{
		case WEAPON:cout << "���ݷ� : " << i.atk << endl; break;
		case ARMOR: cout << "���� : " << i.def << endl; break;
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
	cout << temp.name << " ��(��) " << temp.price / 2 << " Gold�� �Ⱦҽ��ϴ�." << endl;

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
		cout << "�׷������� �������� ����." << endl;
		break;
	}

}
