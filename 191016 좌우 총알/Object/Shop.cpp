#include "stdafx.h"
#include "Shop.h"

Shop::Shop()
{
	Item weapon1 = { WEAPON,"��","�����ٴϴٰ� ���ϰ� ���̴� ��",10,0,1'000,1 };
	Item weapon2 = { WEAPON,"����","�����ٴϴٰ� ���ϰ� ���̴� ����",20,0,2'000,1 };
	Item weapon3 = { WEAPON,"��","�����ٴϴٰ� ���ϰ� ���̴� ��",50,0,5'000,1 };

	Item armor1 = { ARMOR,"���� ��","��� �����̶�� �ҹ���..?",0,20,1'500,1 };
	Item armor2 = { ARMOR,"ö ��","������ ���� �� ������",0,50,3'500,1 };
	Item armor3 = { ARMOR,"�Ǳ� ��","<�Ǳݰ���>",0,100,11'500,1 };

	items.push_back(weapon1);
	items.push_back(weapon2);
	items.push_back(weapon3);
	items.push_back(armor1);
	items.push_back(armor2);
	items.push_back(armor3);
}

Shop::~Shop()
{
}

int Shop::ShowItem(int kind)
{
	int index = 1;
	for (Item& i : items)
	{
		if (kind != i.kind) continue;
		cout << "��ȣ : " << index << endl;
		cout << "�̸� : " << i.name << endl;
		cout << "���� : " << i.description << endl;
		if (i.kind == WEAPON)
			cout << "���ݷ� : " << i.atk << endl;
		if (i.kind == ARMOR)
			cout << "���� : " << i.def << endl;
		cout << "���� : " << i.price << endl;
		cout << "��� : ";
		if (i.emout <= 0)
		{
			Device::SetColor(COLOR::RED);
			cout << "����";
			Device::SetColor(COLOR::DEFAULT);
		}
		else cout << i.emout;
		cout << endl;
		cout << "-------------------------------------------" << endl;
		index++;
	}//	for (Item& i : items)

	return index - 1;
}

Item Shop::Buy(int kind, int select, int & money)
{
	Item temp;

	int index = 1;
	for (Item& i : items)
	{
		if (kind != i.kind) continue;
		if (select == index)
		{
			if (money > i.price)
			{
				if (i.emout > 0)
				{
					cout << i.name << " ��(��)";
					cout << i.price << " ���� ����ϴ�" << endl;
					i.emout--;
					temp = i;
					break;
				}
				else cout << "������" << endl;
			}
			else cout << "�����ؿ� �Ӹ� " << endl;
			Sleep(1000);
			break;
		}
		index++;
	}


	return temp;
}

void Shop::AddItem(Item _item)
{
	bool bNew = true;

	for (Item& i : items)
	{
		if (_item.kind != i.kind)
			continue;

		if (i.name == _item.name)
		{
			i.emout++;
			bNew = false;
			break;
		}
	}

	if (bNew == true)
		items.push_back(_item);


}
