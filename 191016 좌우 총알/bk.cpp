#include "stdafx.h"
vector<Item> shop;
vector<Item> Inventory;
vector<Item>::iterator iter;


Item sword = { WEAPON,"��",10 };
Item shirt = { ARMOR,"����",0 };
Item granade = { WEAPON,"����ź",100 };
void ShowItem();
void ShowInven();

void Buy();
void Sell();


int main()
{
	shop.push_back(sword);
	shop.push_back(shirt);
	shop.push_back(granade);


	int input;
	while (true)
	{
		system("cls");

		ShowItem();
		ShowInven();
		cout << "--------------------�޴�--------------------" << endl;
		cout << "1.���� 2.�Ǹ� : ";
		cin >> input;

		if (input == 1)
			Buy();
		else if (input == 2)
			Sell();
		else
		{
			cout << "����� �Է���" << endl;
			Sleep(1000);
		}


	}

	system("pause");
	return 0;
}

void ShowItem()
{
	int count = 1;
	cout << "--------------------����--------------------" << endl;
	for (Item item : shop)
	{
		cout << count << " : " << item.name << " : " << item.atk << endl;
		count++;
	}
	if (shop.empty())
		cout << "Sell All Item" << endl;
}

void ShowInven()
{
	int count = 1;
	cout << "--------------------�κ�--------------------" << endl;
	for (Item item : Inventory)
	{
		cout << count << " : " << item.name << " : " << item.atk << endl;
		count++;
	}
	if (Inventory.empty())
		cout << "No have Item" << endl;
}

void Buy()
{
	int input;
	cout << endl << endl;
	cout << "<���Ÿ��> �� �췡? : ";
	cin >> input;

	for (int i = 0; i < shop.size(); i++)
	{
		if (input > shop.size() || input <= 0)
			continue;
		iter = shop.begin() + (input - 1);
		Inventory.push_back(*iter);
		shop.erase(iter);
		break;
	}
}

void Sell()
{
	int input;
	cout << endl << endl;
	cout << "<�ǸŸ��> �� �ȷ�? : ";
	cin >> input;

	for (int i = 0; i < Inventory.size(); i++)
	{
		if (input > Inventory.size() || input <= 0)
			continue;
		iter = Inventory.begin() + (input - 1);
		shop.push_back(*iter);
		Inventory.erase(iter);
		break;
	}

}
