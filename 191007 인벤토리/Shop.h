#pragma once
#include "stdafx.h"


class Shop
{
public:
	Shop();
	~Shop();

	//��� �����ִ� �Լ�
	void SetItem();//�ʱ� ������ ����
	int SetShop(int kind); //�������� ������ ����
	//�������� ������ؼ�
	//���� ��ȣ ��(�����Լ��ϱ� �ּҰ�)
	Item Buy(int kind, int select, int& gold);
	void Sell(Item item);//������ �ǸŽ� ���ƿ��� �ݾ�

private:
	vector<Item> shop;
	vector<Item>::iterator iter;

};


