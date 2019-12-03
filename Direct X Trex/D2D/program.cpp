#include "stdafx.h"
#include "System/Device.h"
#include "Viewer/FreeCamera.h"
#include "Viewer/FollowCamera.h"
#include "Scene/Scene.h"
#include "Scene/Trex.h"
SceneValues* values;
Trex* trex;
void InitScene()
{
	values = new SceneValues;
	values->MainCamera = new FreeCamera();

	D3DXMatrixIdentity(&values->Projection);
	trex = new Trex(values);

}

void DestroyScene()
{
	SAFE_DELETE(trex);
	SAFE_DELETE(values->MainCamera);
	SAFE_DELETE(values);
}


void Update()
{
	values->MainCamera->Update();
	D3DXMatrixOrthoOffCenterLH
	(
		&values->Projection,
		(float)Width * -0.5f,
		(float)Width * 0.5f,
		(float)Height * -0.5f,
		(float)Height * 0.5f,
		-10, 10
	);
	bool bPlay = false;
	if (!bPlay)
	{
		if (Key->Down('R'))
		{
			bPlay = true;
			trex->Play();
		}
	}
	trex->Update();
	bPlay = trex->bPlay();

}

void Render()
{
	D3DXCOLOR bgColor = D3DXCOLOR(1, 1, 1, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float*)bgColor);
	{
		trex->Render();
	}
	ImGui::Render();
	////3D Render ÈÄ 2D Render
	DirectWrite::GetDC()->BeginDraw();
	{
		RECT rect = { 0,0,500,200 };
		wstring text = L"FPS : " + to_wstring((UINT)Time::Get()->FPS());
		DirectWrite::RenderText(text, rect);
		rect.top += 20;
		rect.bottom += 20;
		text = L"score : " + to_wstring((UINT)trex->Score());
		DirectWrite::RenderText(text, rect);
		rect.top += 20;
		rect.bottom += 20;
		text = L"High score : " + to_wstring((UINT)trex->HScore());
		DirectWrite::RenderText(text, rect);
		rect.top += 20;
		rect.bottom += 20;
		text = L"Speed : " + to_wstring((UINT)trex->Speed());
		DirectWrite::RenderText(text, rect);
	}
	DirectWrite::GetDC()->EndDraw();
	SwapChain->Present(0, 0);

}
