#include "stdafx.h"
#include "Player.h"
#include "Inven.h"


Player::Player()
{
	atk = 100;
	def = 200;
}

Player::~Player()
{
}

void Player::Status()
{

	cout << "------------------능력치------------------" << endl;
	cout << "공격력 : " << atk + MyWe.atk << "(" << MyWe.atk << ")" << endl;
	cout << "방어력 : " << def + MyAr.def << "(" << MyAr.def << ")" << endl;
	cout << "-------------------장비-------------------" << endl;
	cout << "무기\t: " << MyWe.name << endl << "방어구\t: " << MyAr.name << endl;
}
