#include <iostream>
#include <Windows.h>
using namespace std;
template<typename T>
void Print(T data)
{
	cout << "�Ϲ� �� : " << data << endl;
}
template<typename T>
void Print(T* data)
{
	cout << "������ �� : " << *data << endl;
}
template<>
void Print(const char* data)
{
	cout << "Ư�� ���ڿ� : " << data << endl;
}

template<typename T>
class Parametor
{
public:
	void Set(T value) { this->value = value; }
	virtual void Print() { cout << "�� : " << value << endl; }

protected:
	T value;
};

class Reference : public Parametor<int*>
{
public:
	void Print() override { cout << "�ּ� : " <<value<< endl; }
};


int main()
{

	//int a = 100;
	//Print(&a);
	//Print("����");

	Parametor<int> ob;
	ob.Set(100);

	ob.Print();

	Reference ref;
	ref.Set(new int);
	ref.Print();

	system("pause");
	return 0;
}