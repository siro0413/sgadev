#include "Device.h"

ID3D11Buffer* vertexBuffer;

ID3D11InputLayout* inputLayout;
D3D11_INPUT_ELEMENT_DESC layoutDesc[] =
{

	{
		"POSITION",
		0,
		DXGI_FORMAT_R32G32B32_FLOAT,
		0,
		0,
		D3D11_INPUT_PER_VERTEX_DATA,
		0
	},
	{
		"COLOR",
		0,
		DXGI_FORMAT_R32G32B32_FLOAT,
		0,
		12,
		D3D11_INPUT_PER_VERTEX_DATA,
		0
	}

};

struct Vertex
{
	D3DXVECTOR3 Pos;
	D3DXCOLOR Color;
};

void InitScene()
{
	//정점의 위치를 세팅
	Vertex vertices[6];
	vertices[0].Pos = D3DXVECTOR3{ 0.0f,+0.7f,0.0f };
	vertices[0].Color = D3DXCOLOR{ 1.0F,0.0F,0.0F,1.0F };

	vertices[1].Pos = D3DXVECTOR3{ -0.35f,-0.5f,0.0f };
	vertices[1].Color = D3DXCOLOR{ 0.0F,1.0F,0.0F,1.0F };

	vertices[2].Pos = D3DXVECTOR3{ +0.5f,+0.3f,0.0f };
	vertices[2].Color = D3DXCOLOR{ 0.0F,0.0F,1.0F,1.0F };

	vertices[3].Pos = D3DXVECTOR3{ -0.5f,+0.3f,0.0f };
	vertices[3].Color = D3DXCOLOR{ 1.0F,0.0F,0.0F,1.0F };

	vertices[4].Pos = D3DXVECTOR3{ +0.35f,-0.5f,0.0f };
	vertices[4].Color = D3DXCOLOR{ 0.0F,1.0F,0.0F,1.0F };

	vertices[5].Pos = D3DXVECTOR3{ +0.0f,+0.7f,0.0f };
	vertices[5].Color = D3DXCOLOR{ 0.0F,0.0F,1.0F,1.0F };
	//Create VertexBuffer
	{
		D3D11_BUFFER_DESC desc;
		ZeroMemory(&desc, sizeof(D3D11_BUFFER_DESC));
		desc.Usage = D3D11_USAGE_DEFAULT;
		desc.ByteWidth = sizeof(Vertex) * ARRAYSIZE(vertices);
		desc.BindFlags = D3D11_BIND_VERTEX_BUFFER;

		D3D11_SUBRESOURCE_DATA data;
		ZeroMemory(&data, sizeof(D3D11_SUBRESOURCE_DATA));
		data.pSysMem = vertices;

		HRESULT hr = Device->CreateBuffer(&desc, &data, &vertexBuffer);
		assert(SUCCEEDED(hr));
	}
	//Create InputLayout
	{
		HRESULT hr = Device->CreateInputLayout
		(
			layoutDesc,
			ARRAYSIZE(layoutDesc),
			VsBlob->GetBufferPointer(),//ByteCode
			VsBlob->GetBufferSize(),
			&inputLayout
		);
		assert(SUCCEEDED(hr));
	}
}

void DestroyScene()
{
	inputLayout->Release();
	vertexBuffer->Release();
}

void Update()
{
}

void Render()
{
	D3DXCOLOR bgColor = D3DXCOLOR(0, 0, 0, 1);
	DeviceContext->ClearRenderTargetView(RTV, (float*)bgColor);
	{
		UINT stride = sizeof(Vertex);
		//stride 얼만큼씩 주소값을 건너뛸껀지
		UINT offset = 0;

		DeviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
		DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP);
		DeviceContext->IASetInputLayout(inputLayout);

		DeviceContext->Draw(6, 0); // (a,b) a = 정점(vertex)의 갯수 , b = 시작 주소위치
	}
	SwapChain->Present(0, 0);

}

