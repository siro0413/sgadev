#include "stdafx.h"
#include "Device.h"
#include "System/Player.h"
//ID3D11Buffer* vertexBuffer2;
//Vertex vertices2[4];
//D3DXVECTOR2 position2 = D3DXVECTOR2(0, 0);

D3DXMATRIX V, P;

Player* player;

float x = (float)Width*0.5f;
float y = 50;
void InitScene()
{

	player = new Player(L"./_Shader2D/Effect.fx");
	player->Color(0, 1, 0);

	player->Scale(100, 100);



	player->Position(x, y);

}

void DestroyScene()
{
	SAFE_DELETE(player);

}

void Update()
{

	if (Key->Press(VK_LEFT))
		player->moveLeft();

	else if (Key->Press(VK_RIGHT))
		player->moveRight();

	if (Key->Down(VK_SPACE))
		player->startJump();
	else if (Key->Up(VK_SPACE))
		player->endJump();


	//View
	D3DXVECTOR3 eye(0, 0, -1);
	D3DXVECTOR3 at(0, 0, 0);
	D3DXVECTOR3 up(0, 1, 0);
	D3DXMatrixLookAtLH(&V, &eye, &at, &up);

	//Projection
	D3DXMatrixOrthoOffCenterLH(&P, 0, (float)Width, 0, (float)Height, -1, 1);


	player->ViewProjection(V, P);
	player->Update();

}

void Render()
{
	D3DXCOLOR bgColor = D3DXCOLOR(1, 1, 1, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float*)bgColor);
	{
		player->Render();

	}
	ImGui::Render();
	SwapChain->Present(0, 0);

}

