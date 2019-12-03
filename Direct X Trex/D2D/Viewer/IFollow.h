#pragma once
//순수 가상함수는 몸체가 필요없으니 헤더 파일만 존재
#include "stdafx.h"

class IFollow
{
public:
	virtual void Focus(D3DXVECTOR2* position, D3DXVECTOR2* size) = 0;//call by addrees


};

