#pragma once
#include "stdafx.h"

enum KIND
{
	EMPTY,	//종류
	WEAPON,	//무기
	ARMOR,	//방어구
	SOLD	//재고
};

typedef struct tagItem
{
	KIND kind;		//종류
	string name;	//이름
	int atk;
	int def;
	int price;		//가격
	int count;		//재고
	
}Item;