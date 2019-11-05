#pragma once


class Deal
{
public:
	Deal();
	~Deal();

	void TopMenu();
	void ShopMenu();
	void BuyMenu(int selectedkind);
	void SellMenu();
	void EquopMenu();
private:
	class Shop* sp;
	class Inven* In;
};
