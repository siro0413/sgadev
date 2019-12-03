#pragma once

class CMouse
{
public:
	CMouse(HWND hwnd);
	~CMouse();
	void WndProc(UINT iMessage, WPARAM wParam, LPARAM lParam);
	//wParam -> wheel정보가 여기에 들어있음
	void Update();
	D3DXVECTOR2 Position() { return position; }
	
	bool Down(UINT button) { return ButtonMap[button] == Button::Down; }
	bool Up(UINT button) { return ButtonMap[button] == Button::Up; }
	bool Press(UINT button) { return ButtonMap[button] == Button::Press; }
	bool DoubleClick(UINT button) { return ButtonMap[button] == Button::DoubleClick; }

	float Wheel() { return wheelMoveValue; }
private:
	enum class Button { None, Down, Up, Press, DoubleClick };

	HWND hwnd;
	D3DXVECTOR2 position;

	BYTE buttonStatus[8];
	BYTE buttonPrevStatus[8];

	Button ButtonMap[8];

	float wheelValue;
	float wheelPrevValue;
	float wheelMoveValue;

	DWORD doubleClickTime; //unsinged Long
	DWORD startDoubleClickTime[8];
	int buttonCount[8];

	bool hovering;
};

