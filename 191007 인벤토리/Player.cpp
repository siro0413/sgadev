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

	cout << "------------------�ɷ�ġ------------------" << endl;
	cout << "���ݷ� : " << atk + MyWe.atk << "(" << MyWe.atk << ")" << endl;
	cout << "���� : " << def + MyAr.def << "(" << MyAr.def << ")" << endl;
	cout << "-------------------���-------------------" << endl;
	cout << "����\t: " << MyWe.name << endl << "��\t: " << MyAr.name << endl;
}
