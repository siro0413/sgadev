#pragma once

enum class COLOR { DEFAULT, RED, GREEN, BLUE, PURPLE, YELLOW };

class Device
{
public:
	static void Crate();
	static void Delete();
	static Device* Get();
	//�� ���ڽ��� �����ϴ� �Լ�
	//static �ʱ�ȭ�� �ѹ����Ǵ� �Լ�

	void ClearScreen();

	static void SetColor(COLOR color);


private:
	Device();
	~Device();
	static Device* instance;
	COLOR color;
};
