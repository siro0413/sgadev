#include "stdafx.h"
#include "System/Device.h"
#include "Object/BackGround.h"
#include "Object/Bullet.h"
//ID3D11Buffer* vertexBuffer2;
//Vertex vertices2[4];
//D3DXVECTOR2 position2 = D3DXVECTOR2(0, 0);

D3DXMATRIX V, P;

Sprite* spMario;
BackGround* Bg;
vector<Bullet*> bullets;
D3DXVECTOR2 position;

void InitScene()
{
	wstring shaderFile = L"./_Shader2D/Effect.fx";
	Bg = new BackGround(shaderFile);
	spMario = new Sprite(L"./_Textures/spriteMario.png", shaderFile, 332, 252, 380, 327);
	spMario->Position(400, 170);
	position = D3DXVECTOR2(400, 170);

}

void DestroyScene()
{
	SAFE_DELETE(spMario);
	SAFE_DELETE(Bg);
	for (Bullet* bullet : bullets)
		SAFE_DELETE(bullet);

}

void Update()
{


	//View
	D3DXVECTOR3 eye(0, 0, -1);
	D3DXVECTOR3 at(0, 0, 0);
	D3DXVECTOR3 up(0, 1, 0);
	D3DXMatrixLookAtLH(&V, &eye, &at, &up);

	//Projection
	D3DXMatrixOrthoOffCenterLH(&P, 0, (float)Width, 0, (float)Height, -1, 1);


	Bg->Update(V, P);
	spMario->Update(V, P);

	if (Key->Down(VK_SPACE))
	{
		wstring file = Shaders + L"Effect.fx";
		float angle = Math::Random(-179.9f, 179.9f);
		float speed = Math::Random(0.1f, 1.0f);

		Bullet* bullet = new Bullet(file, position, angle, speed);
		bullets.push_back(bullet);
		
	}

	for (Bullet* bullet : bullets)
		bullet->Update(V, P);
}

void Render()
{

	D3DXCOLOR bgColor = D3DXCOLOR(1, 1, 1, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float*)bgColor);
	{
		Bg->Render();
		spMario->Render();
		for (Bullet* bullet : bullets)
			bullet->Render();
	}
	ImGui::Render();
	SwapChain->Present(0, 0);

}

