#include "stdafx.h"
#include "rock-paper-scissors.h"
#include "Rouge.h"
#include "baseball.h"
#include "High_LowS_even.h"
#include "Bingo.h"
COORD pos_;
void Keycontrol();
void StartMenu();
char* choice = (char*)"ขั";	//player
short c_y = 11, c_x = 63;


int main()
{

	while (true)
	{
		
		pos_ = { c_x,c_y }; SETPOS_; cout << choice;

		if (_kbhit())
		{
			system("cls");
			StartMenu();
			Keycontrol();
			while (_kbhit())_getch();
			
			if (c_y == 11 && (GetAsyncKeyState(VK_SPACE) & 0x8000))
			{
				system("cls");
				rock_paper_scissors();
		
			}
			else if (c_y == 13 && (GetAsyncKeyState(VK_SPACE) & 0x8000))
			{
				system("cls");
				High_LowS_even();
			}
			else if (c_y == 15 && (GetAsyncKeyState(VK_SPACE) & 0x8000))
			{
				system("cls");
				Baseball();
			}
			else if (c_y == 17 && (GetAsyncKeyState(VK_SPACE) & 0x8000))
			{
				system("cls");
				Bingo();
			}
			else if (c_y == 19 && (GetAsyncKeyState(VK_SPACE) & 0x8000))
			{
				system("cls");
				Rouge();
			}
			else if (c_y == 21 && (GetAsyncKeyState(VK_SPACE) & 0x8000))
			{
				break;
				
			}
		}

	}
	system("pause");
	return 0;
}

void Keycontrol()
{
	if (GetAsyncKeyState(VK_UP) & 0x8000)
		 c_y -= 2;
	else if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		c_y += 2;


}

void StartMenu()
{

	cout << "     .S8WWBZX          2SXZ         .ZXX27       SSXSZ     .ZXXXSX2Z;     ,ZXX2X       2XXSZ     ,ZSXSXSS0i    ;aX2       a2Z     .ZSZ      ZSr"<<endl;;
	cout << "   7WMMMMMMMM;        iMMMMa        :MMMMM      ,MMMMM     :MMMMMMMMZ     iMMMMM      :MMMMM     :MMMMMMMMa    2MMM@      MMM     iMMM      MM@"<<endl;;
	cout << "  MMMMX.   ,Z:        MM@WMMi       ;MMWMMM     MM@@MM     iMMM.   .      ;MMWMM@     MMBMMM     ;MMM    ,     ZMMMMM;    MMM.    ;MMM     .MMW"<<endl;;
	cout << " MMMW                WMM  MMM       iMM22MM7   ZMM;MMM     iMMM           ;MMXaMM7   ZMM;MMM     iMMM          2MMZ0MMX   MMM     ;MMM      MMW"<<endl;;
	cout << "ZMMM   rMW080B      rMM0  0MMa      iMM2 MMM   MMi MMM     :MMMMMMMM,     ;MM2 MMM   MMi MMM     ;MMMMMMMM.    aMMS 0MMZ  MMM     iMMM      MMB"<<endl;;
	cout << "0MMM   2MMMMMM      MMM;  iMMM.     iMMB XMMZ @MM .MMM     iMMMB0W@M.     ;MM0 XMMZ MMM ,MMM     iMMM0BW@M.    aMM8  ZMM8 MMM     rMMM      MMW"<<endl;;
	cout << ":MMMW     ,MMM     BMMMMMMMMMMM     ;MMW  MMM2MMi iMMM     iMMM           ;MMW  MMMaMM: ;MMM     ;MMM          aMM8   XMMW@MM.    ,MMM.    :MM@"<<endl;;
	cout << " :MMMMX,  XMMM    ;MMM;:i;:iMMMS    iMMW  .MMMMB  iMMM     iMMM;,::;i     ;MMB  ,MMMM0  rMMM     iMMMi,:i;;    aMM0    iMMMMM      WMMM7:,XMMMX"<<endl;;
	cout << "   ;8MMMMMMWWZ    MMMX      rMMM    ,MM8   7M@M   ,MMM     .MWWMMMMMM     ,MM8   XMM@   ,MMM     ,MWWMMMMMM    XMMZ      B@@M       ;0MMMMMM8: "<<endl;;

	pos_ = { 65,11 }; SETPOS_; cout << "1.rock-paper-scissors";
	pos_ = { 65,13 }; SETPOS_; cout << "2.High_LowS_even";
	pos_ = { 65,15 }; SETPOS_; cout << "3.BaseBall";
	pos_ = { 65,17 }; SETPOS_; cout << "4.Bingo";
	pos_ = { 65,19 }; SETPOS_; cout << "5.Roguelike";
	pos_ = { 65,21 }; SETPOS_; cout << "6.End";
	pos_ = { 65,23 }; SETPOS_; cout << "";



}


