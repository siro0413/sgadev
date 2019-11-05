#pragma once
#include "stdafx.h"


class Shop
{
public:
	Shop();
	~Shop();

	//재고를 보여주는 함수
	void SetItem();//초기 아이템 설정
	int SetShop(int kind); //종류별로 아이템 설정
	//아이템을 사기위해서
	//종류 번호 돈(지역함수니까 주소값)
	Item Buy(int kind, int select, int& gold);
	void Sell(Item item);//아이템 판매시 돌아오는 금액

private:
	vector<Item> shop;
	vector<Item>::iterator iter;

};


