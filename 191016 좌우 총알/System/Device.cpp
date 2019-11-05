#include "stdafx.h"
#include "Device.h"

Device::Device()
	:color(COLOR::DEFAULT)
{
	system("mode con:cols=100 lines=50");//cmd 창 크기 조절
	Handle = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO curinfo;
	curinfo.bVisible = false;
	curinfo.dwSize = 1;
	SetConsoleCursorInfo(Handle, &curinfo);
}

Device::~Device()
{
}

//싱글톤
//프로젝트 전체에 객체가 유일하게 한개만 존재
Device* Device::instance = NULL;
void Device::Crate()
{
	if (instance == NULL)
		instance = new Device;
}

void Device::Delete()
{
	SAFE_DELETE(instance);
}

Device * Device::Get()
{
	if (instance != NULL)
		return instance;

	return NULL;
}

void Device::ClearScreen()
{
	system("cls");
	while (_kbhit()) _getch();
}

void Device::SetColor(COLOR color)
{
	if (color == COLOR::RED)
		SetConsoleTextAttribute(Handle, FOREGROUND_RED);
	else if (color == COLOR::BLUE)
		SetConsoleTextAttribute(Handle, FOREGROUND_BLUE);
	else if (color == COLOR::GREEN)
		SetConsoleTextAttribute(Handle, FOREGROUND_GREEN);
	else if (color == COLOR::PURPLE)
		SetConsoleTextAttribute(Handle, FOREGROUND_RED | FOREGROUND_BLUE);
	else if (color == COLOR::YELLOW)
		SetConsoleTextAttribute(Handle, FOREGROUND_RED | FOREGROUND_GREEN);
	else
		SetConsoleTextAttribute(Handle, FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);

}

