#include "stdafx.h"
#include "Portal.h"



Portal::Portal(string symbol)
	:symbol(symbol)
	,index(0)
	,color(COLOR::PURPLE)
{
	prevTime = GetTickCount();
	//OS�� ���õǰ� ���ݱ��� �帣�� �ð��� ms������ ������
}

Portal::~Portal()
{
}

void Portal::Update()
{
}

void Portal::Render()
{
	ChangeColor();
	SetConsoleCursorPosition(Handle, pos);

	Device::SetColor(color);
	{
		cout << symbol;
	}
	Device::SetColor(COLOR::DEFAULT);
}

void Portal::ChangeColor()
{
	COLOR temp[3];
	temp[0] = COLOR::RED;
	temp[1] = COLOR::GREEN;
	temp[2] = COLOR::YELLOW;

	UINT currentTime = GetTickCount();
	if (currentTime - prevTime > 250)
	{
		prevTime = GetTickCount();
		color = temp[index];
		index++;

		if (index >= 3) index = 0;
	}
}
