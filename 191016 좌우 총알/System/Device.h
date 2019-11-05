#pragma once

enum class COLOR { DEFAULT, RED, GREEN, BLUE, PURPLE, YELLOW };

class Device
{
public:
	static void Crate();
	static void Delete();
	static Device* Get();
	//↑ 나자신을 리턴하는 함수
	//static 초기화가 한번만되는 함수

	void ClearScreen();

	static void SetColor(COLOR color);


private:
	Device();
	~Device();
	static Device* instance;
	COLOR color;
};
