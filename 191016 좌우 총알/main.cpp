#include "stdafx.h"
#include "Scene/ColorPlayer.h"
#include "Scene/Deal.h"
HANDLE Handle;

int main()
{
	Device::Crate();
	ColorPlayer* p = new ColorPlayer;
	while (true)
	{
		system("cls");
		p->Update();
		Device::Get()->ClearScreen();
		{
			p->Render();
		}
		
	}
	SAFE_DELETE(p);
	Device::Delete();

	system("pause");
	return 0;
}
