#pragma once
#include "stdafx.h"

enum KIND
{
	EMPTY,	//����
	WEAPON,	//����
	ARMOR,	//��
	SOLD	//���
};

typedef struct tagItem
{
	KIND kind;		//����
	string name;	//�̸�
	int atk;
	int def;
	int price;		//����
	int count;		//���
	
}Item;