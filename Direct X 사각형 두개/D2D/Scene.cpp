#include "stdafx.h"
#include "Device.h"

ID3D11Buffer* vertexBuffer;
struct Vertex
{
	D3DXVECTOR3 Pos;
	D3DXCOLOR Color;
};

Vertex vertices[8];
Shader* shader;
D3DXCOLOR color = D3DXCOLOR(1, 1, 1, 1);

D3DXMATRIX W, W2, V, P;
D3DXVECTOR2 position = D3DXVECTOR2(100, 100);
D3DXVECTOR2 position2 = D3DXVECTOR2(200, 200);

void InitScene()
{
	shader = new Shader(L"./_Shader2D/Effect.fx");


	//정점의 위치를 세팅
	vertices[0].Pos = D3DXVECTOR3{ -0.5f,-0.5f,0.0f };
	vertices[1].Pos = D3DXVECTOR3{ -0.5f,+0.5f,0.0f };
	vertices[2].Pos = D3DXVECTOR3{ +0.5f,-0.5f,0.0f };
	vertices[3].Pos = D3DXVECTOR3{ +0.5f,+0.5f,0.0f };

	vertices[4].Pos = D3DXVECTOR3{ -0.5f,-0.5f,0.0f };
	vertices[5].Pos = D3DXVECTOR3{ -0.5f,+0.5f,0.0f };
	vertices[6].Pos = D3DXVECTOR3{ +0.5f,-0.5f,0.0f };
	vertices[7].Pos = D3DXVECTOR3{ +0.5f,+0.5f,0.0f };




	//Create VertexBuffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(Vertex) * 12;
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA data;
		ZeroMemory(&data, sizeof(D3D11_SUBRESOURCE_DATA));
		data.pSysMem = vertices;

		HRESULT hr = Device->CreateBuffer(&desc, &data, &vertexBuffer);
		assert(SUCCEEDED(hr));
	}


}

void DestroyScene()
{
	SAFE_DELETE(shader);
	vertexBuffer->Release();

}

void Update()
{

	D3DXMatrixIdentity(&W);
	D3DXMatrixIdentity(&W2);
	D3DXMatrixIdentity(&V);
	D3DXMatrixIdentity(&P);
	//World(S,R,T)
	D3DXMATRIX S, T;
	D3DXMATRIX S2, T2;
	D3DXMatrixScaling(&S, 100, 100, 1);
	D3DXMatrixScaling(&S2, 100, 100, 1);
	D3DXMatrixTranslation(&T, position.x, position.y, 0);
	D3DXMatrixTranslation(&T2, position2.x, position2.y, 0);
	//행렬곱
	W = S * T;
	W2 = S2 * T2;

	//View
	D3DXVECTOR3 eye(0, 0, -1);
	D3DXVECTOR3 at(0, 0, 0);
	D3DXVECTOR3 up(0, 1, 0);
	D3DXMatrixLookAtLH(&V, &eye, &at, &up);

	//Projection
	D3DXMatrixOrthoOffCenterLH(&P, 0, (float)Width, 0, (float)Height, -1, 1);

	shader->AsMatrix("World")->SetMatrix(W);
	shader->AsMatrix("World2")->SetMatrix(W2);
	shader->AsMatrix("View")->SetMatrix(V);

	shader->AsMatrix("Projection")->SetMatrix(P);

	shader->AsVector("Color")->SetFloatVector(color);
	{
		system("cls");
		cout << "position x " << vertices[0].Pos.x << ", y " << vertices[0].Pos.y << endl;
		cout << "------------------------" << endl;
		cout << W._11 << "\t" << W._12 << "\t" << W._13 << "\t" << W._14 << endl;
		cout << W._21 << "\t" << W._22 << "\t" << W._23 << "\t" << W._24 << endl;
		cout << W._31 << "\t" << W._32 << "\t" << W._33 << "\t" << W._34 << endl;
		cout << W._41 << "\t" << W._42 << "\t" << W._43 << "\t" << W._44 << endl;
	}
}

void Render()
{
	D3DXCOLOR bgColor = D3DXCOLOR(0, 0, 0, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float*)bgColor);
	{
		ImGui::ColorEdit3("C_Editor", (float*)&color);
		ImGui::SliderFloat("X", &position.x, 0, Width);
		ImGui::SliderFloat("Y", &position.y, 0, Height);
		ImGui::SliderFloat("X2", &position2.x, 0, Width);
		ImGui::SliderFloat("Y2", &position2.y, 0, Height);

		UINT stride = sizeof(Vertex);
		//stride 얼만큼씩 주소값을 건너뛸껀지
		UINT offset = 0;

		DeviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
		DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);

		shader->Draw(0, 0, 12);
		shader->Draw(0, 1, 12);
		//technique 
		//pass
		//DeviceContext->DrawIndexed(6, 0, 0); // (a,b) a = 정점(vertex)의 갯수 , b = 시작 주소위치
	}
	ImGui::Render();
	SwapChain->Present(0, 0);

}

