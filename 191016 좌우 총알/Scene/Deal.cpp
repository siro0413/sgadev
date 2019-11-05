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
		cout << "1.구매 2.판매 3.장비" << endl;
		cout << "------------------------------------------" << endl;
		cout << "어디갈거냐 : ";
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
		cout << "--------------------상점--------------------" << endl;
		cout << "1.무기 2.방어구 0.상위" << endl;
		cout << "어디갈거냐 : ";
		int kind;
		cin >> kind;

		switch (kind)
		{
		case 0: TopMenu(); break;
		case 1: case 2:
			BuyMenu(kind);
			break;
		default:
			cout << "제대로 선택좀 ㅇㅇ" << endl;
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
		cout << "--------------------상점--------------------" << endl;
		count = sp->ShowItem(selectedkind);
		cout << "--------------------상위0-------------------" << endl;
		int money = In->Money();
		cout << "Gold : " << money << endl;
		cout << "아이템 개수 : " << count << endl;

		cout << "구매 아이템 번호 : ";
		int ninput;
		cin >> ninput;
		if (ninput == 0)
		{
			ShopMenu();
			break;
		}
		else if (ninput<0 || ninput >count)
		{
			cout << "구매 목록에 없는 아이템 번호" << endl;
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
		cout << "--------------------인벤--------------------" << endl;
		count = In->ShowInven();
		cout << "--------------------상위0-------------------" << endl;
		int money = In->Money();
		cout << "Gold : " << money << endl;
		cout << "아이템 개수 : " << count << endl;
		cout << "판매할 아이템 번호 : ";
		int ninput;
		cin >> ninput;
		if (ninput == 0)
		{
			ShopMenu();
			break;
		}
		else if (ninput<0 || ninput >count)
		{
			cout << "판매 목록에 없는 아이템 번호" << endl;
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

		cout << "--------------------인벤--------------------" << endl;
		count = In->ShowInven();
		cout << "--------------------상위0-------------------" << endl;
		cout << "장착할 아이템 번호 : ";
		int ninput;
		cin >> ninput;
		if (ninput == 0)
		{
			ShopMenu();
			break;
		}
		else if (ninput<0 || ninput >count)
		{
			cout << "장비 목록에 없는 아이템 번호" << endl;
			Sleep(1000);
		}
		else
		{
			In->Equip(ninput);
		}

	}

}
