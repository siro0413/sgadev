#include "stdafx.h"
#include "Keyboard.h"

/*
set() : 특정 bit를 true로 설정
reset() : 특정 bit를 false로 설정
set(i, value) : i번째 값을 value로 설정
flip : bit 반전 true <-> false
all() : 모든 bit가 1일 때 true를 반환
none() : 모든 bit가 0일 때 true를 반환
any() : 1개라도 true면 true반환
count() : true의 갯수를 반환

[] 배열 형태로 접근가능 bit[10] = false;
*/

Keyboard::Keyboard() 
{
	for (int i = 0; i < KEYMAX; i++)
	{
		up.set(i, false);
		down.set(i, false);
	}
}

Keyboard::~Keyboard()
{
}

bool Keyboard::Down(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		if (down[key] == false)
		{
			down.set(key, true);
			return true;
		}
	}
	else
	{
		down.set(key, false);
	}
	return false;
}

bool Keyboard::Up(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
	{
		up.set(key, true);
	}
	else
	{
		if (up[key] == true)
		{
			up.set(key, false);
			return true;
		}
	}

	return false;
}

bool Keyboard::Press(int key)
{
	if (GetAsyncKeyState(key) & 0x8000)
		return true;


	return false;
}

bool Keyboard::Toggle(int key)
{
	if (GetAsyncKeyState(key) & 0x0001)
		return true;
	return false;
}
