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
	cout << "-------------------�޴�-------------------" << endl;
	cout << "1.���� 2.�Ǹ� 3.����" << endl;
	cout << "------------------------------------------" << endl;
	cout << "��𰥰Žó� : ";
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
	while (true) //while������ ������������ ���ų� �ǸŰ� ����� �ȵ��ư�
	{
		system("cls");
		cout << "-------------------����-------------------" << endl;
		cout << "1.���� 2.��" << endl;
		cout << "------------------------------------------" << endl;
		cout << "�� �췡? : ";
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
	cout << "�� �췡? : ";
	cin >> input;

	//��ȣ�Է� ���ǹ�
	if (input == 0)
	{
		GoShop();//ī�װ� ������� ����
	}
	else if (input < 0 || input>shop->SetShop(kind))
	{
		cout << "����ε� ��ȣ��" << endl;
		Sleep(1000);
	}
	//����� �Է��ߴٸ�?
	else
	{
		player->Push_Item(shop->Buy(kind, input, Gold));
	}
	//kind ���� input �����۹�ȣ gold ����
}

void Menu::GoSell()
{
	system("cls");
	player->ViewInven();
	cout << "------------------------------------------" << endl;

	cout << "Money : " << Gold << endl;
	cout << "�� �ȷ�? : ";
	cin >> input;
	//��ȣ�Է� ���ǹ�
	if (input == 0)
	{
		GoShop();//ī�װ� ������� ����
	}
	else if (input < 0 || input > player->ViewInven())
	{
		cout << "����ε� ��ȣ��" << endl;
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

	cout << "������ ��� �Է� : ";
	cin >> input;
	if (input == 0)
	{
		GoMain();//���� ������� ����
	}
	else if (input < 0 || input > player->ViewInven())
	{
		cout << "����ε� ��ȣ��" << endl;
		Sleep(1000);
	}
	else
	{
		player->MyItem(input);
		GoInven();
	}
}
