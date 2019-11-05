#include "stdafx.h"
#include "Deal.h"
#include "Object/Shop.h"
#include "Object/Inven.h"
Deal::Deal()
{
	sp = new Shop;
	In = new Inven;
	TopMenu();

}

Deal::~Deal()
{
	SAFE_DELETE(sp);
	SAFE_DELETE(In);
}

void Deal::TopMenu()
{
	while (true)
	{
		system("cls");
		cout << "------------------------------------------" << endl;
		cout << "1.���� 2.�Ǹ� 3.���" << endl;
		cout << "------------------------------------------" << endl;
		cout << "��𰥰ų� : ";
		int input;
		cin >> input;

		switch (input)
		{
		case 1: ShopMenu(); break;
		case 2: SellMenu();	break;
		case 3: EquopMenu(); break;

		default: TopMenu();
			break;
		}

	}

}

void Deal::ShopMenu()
{
	while (true)
	{
		system("cls");
		cout << "--------------------����--------------------" << endl;
		cout << "1.���� 2.�� 0.����" << endl;
		cout << "��𰥰ų� : ";
		int kind;
		cin >> kind;

		switch (kind)
		{
		case 0: TopMenu(); break;
		case 1: case 2:
			BuyMenu(kind);
			break;
		default:
			cout << "����� ������ ����" << endl;
			Sleep(1000);
			break;
		}
	}

}

void Deal::BuyMenu(int selectedkind)
{
	int count = 0;

	while (true)
	{
		system("cls");
		cout << "--------------------����--------------------" << endl;
		count = sp->ShowItem(selectedkind);
		cout << "--------------------����0-------------------" << endl;
		int money = In->Money();
		cout << "Gold : " << money << endl;
		cout << "������ ���� : " << count << endl;

		cout << "���� ������ ��ȣ : ";
		int ninput;
		cin >> ninput;
		if (ninput == 0)
		{
			ShopMenu();
			break;
		}
		else if (ninput<0 || ninput >count)
		{
			cout << "���� ��Ͽ� ���� ������ ��ȣ" << endl;
			Sleep(1000);
		}
		else
		{
			Item item = sp->Buy(selectedkind, ninput, money);
			In->AddItem(item);
			int pay = money - item.price;
			In->Money(pay);
		}
	}
}

void Deal::SellMenu()
{
	int count = 0;

	while (true)
	{
		system("cls");
		cout << "--------------------�κ�--------------------" << endl;
		count = In->ShowInven();
		cout << "--------------------����0-------------------" << endl;
		int money = In->Money();
		cout << "Gold : " << money << endl;
		cout << "������ ���� : " << count << endl;
		cout << "�Ǹ��� ������ ��ȣ : ";
		int ninput;
		cin >> ninput;
		if (ninput == 0)
		{
			ShopMenu();
			break;
		}
		else if (ninput<0 || ninput >count)
		{
			cout << "�Ǹ� ��Ͽ� ���� ������ ��ȣ" << endl;
			Sleep(1000);
		}
		else
		{
			int money = In->Money();
			Item item = In->Sell(ninput, money);
			In->Money(money + item.price/2);
			sp->AddItem(item);
			Sleep(1000);
		}
	}
}

void Deal::EquopMenu()
{
	int count = 0;

	while (true)
	{
		system("cls");
		In->ShowStatus();

		cout << "--------------------�κ�--------------------" << endl;
		count = In->ShowInven();
		cout << "--------------------����0-------------------" << endl;
		cout << "������ ������ ��ȣ : ";
		int ninput;
		cin >> ninput;
		if (ninput == 0)
		{
			ShopMenu();
			break;
		}
		else if (ninput<0 || ninput >count)
		{
			cout << "��� ��Ͽ� ���� ������ ��ȣ" << endl;
			Sleep(1000);
		}
		else
		{
			In->Equip(ninput);
		}

	}

}
