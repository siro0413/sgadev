#include "stdafx.h"
/*
	API ? Application program interface(규격)
	inline _inline __inline

	LP -> Long Pointer
	문자열(STR) : cahr[] 0-> char* -> string
	LPCSTR : const char*
	LPCWSTR : const wchar*

	CALLBACK -> 인자로 넘겨받는 함수
*/

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
//함수의 프로토타입
//main
//hInstance
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE prevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	WNDCLASS wc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.hCursor = LoadCursor(NULL, IDC_CROSS);
	wc.hIcon = LoadIcon(NULL, IDI_WARNING);
	wc.hInstance = hInstance;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.lpszClassName = Title.c_str();
	wc.lpszMenuName = NULL;
	wc.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&wc);

	HWND hwnd = CreateWindow
	(
		Title.c_str(),
		Title.c_str(),
		WS_OVERLAPPEDWINDOW,
		100,
		20,
		Width + 50,
		Height + 50,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	ShowWindow(hwnd, nCmdShow);

	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg); //callback함수에서 만든 함수를 번역해주는 함수
			DispatchMessage(&msg);
		}
		else
		{
			//Update();
			//Render();
		}
	}

	DestroyWindow(hwnd);

	UnregisterClass(Title.c_str(), hInstance);
	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//static을 쓰면 멤버변수가 쓰래기값이 아닌 0이 할당
	static RECT rt = { 10,10,70,70 };


	switch (message)
	{
	case WM_KEYDOWN:
	{
		if (wParam == VK_UP)
		{
			rt.top -= 80;
			rt.bottom -= 80;
		}
		else if (wParam == VK_DOWN)
		{
			rt.top += 80;
			rt.bottom += 80;
		}
		if (wParam == VK_LEFT)
		{
			rt.left -= 80;
			rt.right -= 80;
		}
		else if (wParam == VK_RIGHT)
		{
			rt.left += 80;
			rt.right += 80;
		}
		//최대 범위체크
		if (rt.top <= 10 && rt.bottom <= 70)
		{
			rt.top = 10;
			rt.bottom = 70;
		}
		else if (rt.top >= 650 && rt.bottom >= 710)
		{
			rt.top = 650;
			rt.bottom = 710;
		}
		if (rt.left <= 10 && rt.right <= 70)
		{
			rt.left = 10;
			rt.right = 70;
		}
		else if (rt.left >= 1210 && rt.right >= 1270)
		{
			rt.left = 1210;
			rt.right = 1270;
		}
		InvalidateRect(hwnd, nullptr, true);
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);

		for (int i = 0; i < 10; i++) //가로줄
		{
			MoveToEx(hdc, 0, i*Height / 9, NULL);
			LineTo(hdc, Width, i*Height / 9);
		}
		for (int i = 0; i < 17; i++) //세로줄
		{
			MoveToEx(hdc, i*Width / 16, 0, NULL);
			LineTo(hdc, i*Width / 16, Height);
		}
		Rectangle(hdc, rt.left, rt.top, rt.right, rt.bottom);
		EndPaint(hwnd, &ps);
	}
	break;
	case WM_CLOSE: case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}
