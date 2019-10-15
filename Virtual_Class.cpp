#include <iostream>
#include <Windows.h>
using namespace std;

class Parent //추상 클래스 : 순수가상 함수를 한개라도 포함하면 추상클래스
{
public:
	virtual void Print() { cout << "부모의 생성자" << endl; }
	virtual ~Parent() { cout << "부모의 소멸자" << endl; }
	virtual void Func() = 0; //순수 가상함수 -> 자식에서 무조건 재정의 필요


	int Value() { cout << "나는 부모 클래스 : "; return value; }
	void Value(int val) { value = val; }
private:
	int value;
};


class Child : public Parent
{
public:
	void Print() override { cout << "자식의 생성자" << endl; }
	~Child() { cout << "자식의 소멸자" << endl; }

	void Func() override { cout << "순수 가상함수" << endl; }

	int Value() { cout << "나는 자식 클래스 : "; return value; }
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
	//상속시 부모클래스의 소멸자에 virtual이 필수


	system("pause");
	return 0;
}