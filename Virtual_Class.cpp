#include <iostream>
#include <Windows.h>
using namespace std;

class Parent //�߻� Ŭ���� : �������� �Լ��� �Ѱ��� �����ϸ� �߻�Ŭ����
{
public:
	virtual void Print() { cout << "�θ��� ������" << endl; }
	virtual ~Parent() { cout << "�θ��� �Ҹ���" << endl; }
	virtual void Func() = 0; //���� �����Լ� -> �ڽĿ��� ������ ������ �ʿ�


	int Value() { cout << "���� �θ� Ŭ���� : "; return value; }
	void Value(int val) { value = val; }
private:
	int value;
};


class Child : public Parent
{
public:
	void Print() override { cout << "�ڽ��� ������" << endl; }
	~Child() { cout << "�ڽ��� �Ҹ���" << endl; }

	void Func() override { cout << "���� �����Լ�" << endl; }

	int Value() { cout << "���� �ڽ� Ŭ���� : "; return value; }
	void Value(int val) { value = val; }
private:
	int value;
};


int main()
{
	//Child* Ch = new Child;
	//Ch->Print();
	//Ch->Func();
	//
	//delete Ch;

	Parent* pa = new Child;  //Upcasting
	pa->Print();
	pa->Value(1);
	cout << pa->Value() << endl;
	delete pa;
	//��ӽ� �θ�Ŭ������ �Ҹ��ڿ� virtual�� �ʼ�


	system("pause");
	return 0;
}