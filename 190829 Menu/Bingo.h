#pragma once
#include "stdafx.h"
void _array();
void shuffle();
void cmd();
void markingcheck();
void bingopcheck();

typedef unsigned int uint;


int ninput;
int markingCount = 0;
int bingocount = 0;
int BingoTable[5][5];

void endpage();

int Bingo()
{
	_array();
	shuffle();


	while (true)
	{
		cmd();
		markingcheck();


		bingopcheck();
		if (bingocount >= 3) break;

		if (ninput == 123)
			break;

	}

	system("cls");
	endpage();
	system("pause");
	return 0;
}

void _array()
{
	srand((uint)time(NULL));

	uint count = 1;
	//array
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			BingoTable[i][j] = count;
			count++;
		}
	}
}

void shuffle()
{
	//shuffle
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			int src1 = rand() % 5;
			int src2 = rand() % 5;
			int dst1 = rand() % 5;
			int dst2 = rand() % 5;
			int temp = BingoTable[src1][dst1];
			BingoTable[src1][dst1] = BingoTable[dst2][src2];
			BingoTable[dst2][src2] = temp;

		}
	}
}

void cmd()
{

	system("cls");


	cout << "현재 " << bingocount << " 빙고 입니다" << endl;

	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (BingoTable[i][j] == -1)
				cout << "◎" << "\t";
			else
				cout << BingoTable[i][j] << "\t";

		}
		cout << endl << endl;
	}


	cout << "input : ";
	cin >> ninput;

}
void markingcheck()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (ninput == BingoTable[i][j])
				BingoTable[i][j] = -1;
		}
	}
}
void bingopcheck()
{
	bingocount = 0;

	//garo
	for (int i = 0; i < 5; i++)
	{
		markingCount = 0;
		for (int j = 0; j < 5; j++)
		{
			if (BingoTable[i][j] == -1)
			{
				markingCount++;
			}
		}
		if (markingCount == 5) bingocount++;
	}

	//sero
	for (int i = 0; i < 5; i++)
	{
		markingCount = 0;
		for (int j = 0; j < 5; j++)
		{
			if (BingoTable[j][i] == -1)
			{
				markingCount++;
			}
		}
		if (markingCount == 5) bingocount++;
	}
	//대각선 (\)
	markingCount = 0;
	for (int i = 0; i < 5; i++)
	{
		if (BingoTable[i][i] == -1)
			markingCount++;
	}
	if (markingCount == 5)
		bingocount++;
	//대각선 (/)
	markingCount = 0;
	for (int i = 0; i < 5; i++)
	{
		if (BingoTable[i][4 - i] == -1)
			markingCount++;
	}
	if (markingCount == 5)
		bingocount++;

}


void endpage()
{
	cout << endl << endl << endl;

	cout << "                                                                                              " << endl;
	cout << "    ..    .,,,,.   .                                                                           " << endl;
	cout << "    ,.. .##X###X-..., .,    ;                 ,   ..... ,#####x;  x     .....    ..   ......   " << endl;
	cout << "    ;.. ;#       ,... ,######  ,.......  ,...,.  ..... =#+...,+#x+-   ,,..   ,x######= . ....  " << endl;
	cout << "    ,.. ;#       ...;          .......,  ,..... ..... -#        xX   ..  .  X##x-.,,+##....... " << endl;
	cout << "    .... ; .........+  ......  ......... ,...,  ,.....x   .,....  . ..   . x#;        -x.....,	" << endl;
	cout << "    ;.... ..........,  .....;  .......,.,....,, .....;.   ......... .,..,. #,           ;...,. " << endl;
	cout << "    ;,.,.. ..,,;;;.,,, ,.,.,,  ;,,.,.,.,.,.,,,. ,,.,,,    --,;.,.,,  ,,,...x            ;,,,,, " << endl;
	cout << "    .,,..x#X#X#XXx;.,, ,,,,,;  ,,,,..,,.,,,,,,. +.,,,,    ###x.,,,, .,,,,,,,            ,,,..= " << endl;
	cout << "    ,;,. #;       ;,,, ,.,,,,  ;,,.;- .,,,,,,,, =- ,.,,     ,..,,,, ..,,,,,,.          ,,,.,,x " << endl;
	cout << "    .,,. #;       ,.,. .,.,.,  ,,.,.#= ...,.,,;  #. ..,,,,......... + ..,.,,;,. .   ..;,,.. x; " << endl;
	cout << "     ,.. =,    .,,.. . ....,,  ,...  #+ ...,.,.  ;#.  .........   - -x ....,.,,,;;,,,,.... =x  " << endl;
	cout << "     .... ..,.,...  ,#  ....,  .....  #x  ....,   =#+.        .,-x#  ##.  .............   +#   " << endl;
	cout << "     ,            ;x#- .       .....   #X  ...,    .####XX#######+    x#x;              -#x    " << endl;
	cout << "    .##=;,;;;,-=X##+  .#,..,x.     .    xX    .       .---==-,.         X##x+-;,....-+###,     " << endl;
	cout << "      x########X=.     +####+  #XX##     =#+++X.                          ,+x#########+.       " << endl;
	cout << "                               --;-.      ;x+xx                                                " << endl;
	cout << "                                                                                               " << endl;
	cout << "                                                                                               " << endl;



	cout << endl;
	cout << endl;


}

