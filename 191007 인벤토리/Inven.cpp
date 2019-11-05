#include "stdafx.h"
#include "Inven.h"

Inven::Inven()
{
	Item First1;//�ʱ����
	First1.atk = 10;
	First1.kind = WEAPON;
	First1.def = 0;
	First1.name = "�ʱ����";
	First1.price = 0;

	Item First2;//�ʱ����
	First2.atk = 0;
	First2.kind = ARMOR;
	First2.def = 10;
	First2.name = "�ʱ����";
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
	cout << "-------------------�κ�-------------------" << endl;
	for (auto& i : inven)
	{
		cout << "��ȣ : " << _count << endl;
		cout << "�̸� : " << i.name << endl;
		if (i.kind == WEAPON)
			cout << "���ݷ� : " << i.atk << endl;
		else if (i.kind == ARMOR)
			cout << "���� : " << i.def << endl;
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
	cout << temp.name << "��(��) " << temp.price / 2 << "���� �ȾҴ�" << endl
		<< "��� ȣ����" << endl;
	
	gold += temp.price / 2;
	return temp;
	//temp�� ����������
	//*iter�� ������ �ּҰ��� ����
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
		cout << "�޴� ��ȣ�� ���" << endl;


}
