#include "stdafx.h"
#include "CMouse.h"

CMouse::CMouse(HWND hwnd)
	:hwnd(hwnd), position(0, 0), wheelMoveValue(0), wheelPrevValue(0), wheelValue(0)
	,hovering(false)
{
	ZeroMemory(buttonStatus, sizeof(BYTE) * 8);
	ZeroMemory(buttonPrevStatus, sizeof(BYTE) * 8);
	ZeroMemory(ButtonMap, sizeof(Button) * 8);
	ZeroMemory(buttonCount, sizeof(int) * 8);
	doubleClickTime = GetDoubleClickTime();//시스템에서 설정한 더블클릭속도 불러오는함수
	startDoubleClickTime[0] = GetTickCount(); //시간단위를 ms단위로 세팅

	for (int i = 1; i < 8; i++)
		startDoubleClickTime[i] = startDoubleClickTime[0];
}

CMouse::~CMouse()
{
}

void CMouse::WndProc(UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	if (iMessage == WM_MOUSEMOVE)
	{
		position.x = (float)LOWORD(lParam);
		position.y = (float)HIWORD(lParam);
	}
	if (iMessage == WM_MOUSEHWHEEL)
	{
		short temp = (short)HIWORD(wParam);

		wheelPrevValue = wheelValue;
		wheelValue += (float)temp;
	}
}

void CMouse::Update()
{
	hovering = ImGui::IsMouseHoveringAnyWindow();

	memcpy(buttonPrevStatus, buttonStatus, sizeof(BYTE) * 8);
	buttonStatus[0] = GetAsyncKeyState(VK_LBUTTON) & 0x08000 ? 1 : 0;//왼쪽버튼
	buttonStatus[1] = GetAsyncKeyState(VK_RBUTTON) & 0x08000 ? 1 : 0;//오른쪽
	buttonStatus[2] = GetAsyncKeyState(VK_MBUTTON) & 0x08000 ? 1 : 0;//휠

	for (UINT i = 0; i < 8; i++)
	{
		BYTE prevStatus = buttonPrevStatus[i];
		BYTE currenStatus = buttonStatus[i];

		if (prevStatus == 0 && currenStatus == 1)
			ButtonMap[i] = Button::Down;
		else if (prevStatus == 1 && currenStatus == 0)
			ButtonMap[i] = Button::Up;
		else if (prevStatus == 1 && currenStatus == 1)
			ButtonMap[i] = Button::Press;
		else
			ButtonMap[i] = Button::None;
	}
	//더블 클릭
	UINT buttonStatus = GetTickCount();
	for (UINT i = 0; i < 8; i++)
	{
		if (ButtonMap[i] == Button::Down)
		{
			if (buttonCount[i] == 1)
				if (buttonStatus - startDoubleClickTime[i] >= doubleClickTime)
					buttonCount[i] = 0;

			buttonCount[i]++;

			if (buttonCount[i] == 1)
				startDoubleClickTime[i] = buttonStatus;
		}

		if (ButtonMap[i] == Button::Up)
		{
			if (buttonCount[i] == 1)
			{
				if (buttonStatus - startDoubleClickTime[i] >= doubleClickTime)
					buttonCount[i] = 0;
			}
			else if (buttonCount[i] == 2)
			{
				if (buttonStatus - startDoubleClickTime[i] <= doubleClickTime)
					ButtonMap[i] = Button::DoubleClick;
				buttonCount[i] = 0;
			}
		}
	}
	POINT point;
	GetCursorPos(&point);
	ScreenToClient(hwnd, &point);

	wheelPrevValue = wheelValue;
	wheelMoveValue = wheelValue - wheelPrevValue;


}
