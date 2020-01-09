#include <iostream>
#include <Windows.h>
using namespace std;
template<typename T>
void Print(T data)
{
	cout << "일반 값 : " << data << endl;
}
template<typename T>
void Print(T* data)
{
	cout << "포인터 값 : " << *data << endl;
}
template<>
void Print(const char* data)
{
	cout << "특수 문자열 : " << data << endl;
}

template<typename T>
class Parametor
{
public:
	void Set(T value) { this->value = value; }
	virtual void Print() { cout << "값 : " << value << endl; }

protected:
	T value;
};

class Reference : public Parametor<int*>
{
public:
	void Print() override { cout << "주소 : " <<value<< endl; }
};


int main()
{

	//int a = 100;
	//Print(&a);
	//Print("하하");

	Parametor<int> ob;
	ob.Set(100);

	ob.Print();

	Reference ref;
	ref.Set(new int);
	ref.Print();

	system("pause");
	return 0;
}