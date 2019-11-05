#include "stdafx.h"
#include "Menu.h"

Menu::Menu()
{
	shop = new Shop;
	player = new Player;
	shop->SetItem();
	Gold = 10'000;
	GoMain();
}

Menu::~Menu()
{
	delete shop;
	delete player;

}

void Menu::GoMain()
{
	system("cls");
	cout << "-------------------메뉴-------------------" << endl;
	cout << "1.구매 2.판매 3.장착" << endl;
	cout << "------------------------------------------" << endl;
	cout << "어디갈거시냐 : ";
	cin >> input;

	if (input == 1)
		GoShop();
	else if (input == 2)
		GoSell();
	else if (input == 3)
		GoInven();
	else
		GoMain(); 
}

void Menu::GoShop()
{
	while (true) //while문으로 돌리지않으니 구매나 판매가 제대로 안돌아감
	{
		system("cls");
		cout << "-------------------상점-------------------" << endl;
		cout << "1.무기 2.방어구" << endl;
		cout << "------------------------------------------" << endl;
		cout << "뭘 살래? : ";
		cin >> input;
		if (input == 0)
			GoMain();
		else if (input == 1)
			GoBuy(input);
		else if (input == 2)
			GoBuy(input);
		else GoShop();
	}
}

void Menu::GoBuy(int kind)
{

	system("cls");
	shop->SetShop(kind);
	cout << "------------------------------------------" << endl;

	cout << "Money : " << Gold << endl;
	cout << "뭘 살래? : ";
	cin >> input;

	//번호입력 조건문
	if (input == 0)
	{
		GoShop();//카테고리 목록으로 복귀
	}
	else if (input < 0 || input>shop->SetShop(kind))
	{
		cout << "제대로된 번호점" << endl;
		Sleep(1000);
	}
	//제대로 입력했다면?
	else
	{
		player->Push_Item(shop->Buy(kind, input, Gold));
	}
	//kind 종류 input 아이템번호 gold 내돈
}

void Menu::GoSell()
{
	system("cls");
	player->ViewInven();
	cout << "------------------------------------------" << endl;

	cout << "Money : " << Gold << endl;
	cout << "뭘 팔래? : ";
	cin >> input;
	//번호입력 조건문
	if (input == 0)
	{
		GoShop();//카테고리 목록으로 복귀
	}
	else if (input < 0 || input > player->ViewInven())
	{
		cout << "제대로된 번호점" << endl;
		Sleep(1000);
	}
	else
	{
		shop->Sell(player->Sell(input, Gold));
		GoSell();
	}
}

void Menu::GoInven()
{

	system("cls");
	player->Status();
	player->ViewInven();
	cout << "------------------------------------------" << endl;

	cout << "장착할 장비 입력 : ";
	cin >> input;
	if (input == 0)
	{
		GoMain();//메인 목록으로 복귀
	}
	else if (input < 0 || input > player->ViewInven())
	{
		cout << "제대로된 번호점" << endl;
		Sleep(1000);
	}
	else
	{
		player->MyItem(input);
		GoInven();
	}
}
