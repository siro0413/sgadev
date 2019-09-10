#include "stdafx.h"

struct Question
{
	char question[100];
	char answer[100];
};

Question *ques;


char nInput[20];

void Qusetion();


int main()
{

	while (true)
	{
		Qusetion();
	}
	system("pause");
	return 0;
}

void Qusetion()
{
	srand((unsigned)time(NULL));

	Question _ques[5] = { 
		{"Your name is","오택규"},
		{"How old are you?","24살"},
		{"What's your Phone Number?","010-0000-0000"},
		{"Where do you live?","부천"},
		{"What are your hobbies?","책읽기"} 
	};

	for (UINT i = 0; i < 100; i++)
	{

		int src = rand() % 5;
		int dst = rand() % 5;

		swap(_ques[src], _ques[dst]);

		if (i > 4)
			continue;
		cout << "정답 : 오택규, 24살, 010-0000-0000, 부천, 책일기" << endl << endl;
		cout << _ques[i].question << endl;
		cout << "----------------" << endl;
		cout << "input Answer : ";
		cin >> nInput;

		if (!strcmp(nInput, _ques[i].answer))
		{
			cout << "정답" << endl;
			cout << "----------------" << endl;
		}
		else
		{
			cout << "오답" << endl;
			cout << "----------------" << endl;
		}
		Sleep(1500);
		system("cls");

	}



}


