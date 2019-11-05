#pragma once
#include "stdafx.h"

enum KIND { EMPTY, WEAPON, ARMOR};

typedef struct tagItem
{
	KIND kind;
	string name;
	string description;
	UINT atk;
	UINT def;
	UINT price;
	UINT emout;
}Item;





