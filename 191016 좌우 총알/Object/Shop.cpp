#include "stdafx.h"
#include "Shop.h"

Shop::Shop()
{
	Item weapon1 = { WEAPON,"검","지나다니다가 흔하게 보이는 검",10,0,1'000,1 };
	Item weapon2 = { WEAPON,"도끼","지나다니다가 흔하게 보이는 도끼",20,0,2'000,1 };
	Item weapon3 = { WEAPON,"총","지나다니다가 흔하게 보이는 총",50,0,5'000,1 };

	Item armor1 = { ARMOR,"가죽 셋","사람 가죽이라는 소문이..?",0,20,1'500,1 };
	Item armor2 = { ARMOR,"철 셋","이제야 조금 방어구 스럽군",0,50,3'500,1 };
	Item armor3 = { ARMOR,"판금 셋","<판금간지>",0,100,11'500,1 };

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
		cout << "번호 : " << index << endl;
		cout << "이름 : " << i.name << endl;
		cout << "설명 : " << i.description << endl;
		if (i.kind == WEAPON)
			cout << "공격력 : " << i.atk << endl;
		if (i.kind == ARMOR)
			cout << "방어력 : " << i.def << endl;
		cout << "가격 : " << i.price << endl;
		cout << "재고 : ";
		if (i.emout <= 0)
		{
			Device::SetColor(COLOR::RED);
			cout << "매진";
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
					cout << i.name << " 을(를)";
					cout << i.price << " 원에 샀습니다" << endl;
					i.emout--;
					temp = i;
					break;
				}
				else cout << "재고없음" << endl;
			}
			else cout << "돈구해와 임마 " << endl;
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
