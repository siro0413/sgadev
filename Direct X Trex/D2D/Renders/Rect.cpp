#include "stdafx.h"
#include "Rect.h"

Rect::Rect(wstring shaderFile)
	:position(0, 0),
	scale(1, 1),
	color(1, 1, 1, 1)
{
	CreateBuffer(shaderFile);
	UpdateWorld();
	Color(color);

}

Rect::Rect(wstring shaderFile, D3DXVECTOR2 position, D3DXVECTOR2 scale, D3DXCOLOR color)
	:position(position),scale(scale),color(color)
{
	CreateBuffer(shaderFile);
	UpdateWorld();
	Color(color);
}

Rect::~Rect()
{
	SAFE_RELEASE(vertexBuffer);
	SAFE_DELETE(shader);
}

void Rect::Update(D3DXMATRIX& V, D3DXMATRIX& P)
{
	shader->AsMatrix("View")->SetMatrix(V);
	shader->AsMatrix("Projection")->SetMatrix(P);
}

void Rect::Render()
{
	//stride 얼만큼씩 주소값을 건너뛸껀지
	UINT stride = sizeof(Vertex);
	UINT offset = 0;

	DeviceContext->IASetVertexBuffers(0, 1, &vertexBuffer, &stride, &offset);
	DeviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP);
	shader->Draw(0, 0, 6);
	//technique 
	//pass
	//DeviceContext->DrawIndexed(6, 0, 0); // (a,b) a = 정점(vertex)의 갯수 , b = 시작 주소위치
}

void Rect::Position(float x, float y)
{
	D3DXVECTOR2 input = {x, y};
	Position(input);
}

void Rect::Position(D3DXVECTOR2 & vec)
{
	position = vec;
	UpdateWorld();
}

void Rect::Scale(float x, float y)
{
	D3DXVECTOR2 input = { x, y };
	Scale(input);
}

void Rect::Scale(D3DXVECTOR2 & vec)
{
	scale = vec;
	UpdateWorld();
}

void Rect::Color(float r, float g, float b)
{
	D3DXCOLOR input = { r,g,b,1 };
	Color(input);
}

void Rect::Color(D3DXCOLOR & vec)
{
	color = vec;

	shader->AsVector("Color")->SetFloatVector(color);
}


void Rect::CreateBuffer(wstring shaderFile)
{
	shader = new Shader(L"./_Shader2D/Effect.fx");

	Vertex vertices[4];


	//정점의 위치를 세팅
	vertices[0].Pos = D3DXVECTOR3{ -0.5f,-0.5f,0.0f };
	vertices[1].Pos = D3DXVECTOR3{ -0.5f,+0.5f,0.0f };
	vertices[2].Pos = D3DXVECTOR3{ +0.5f,-0.5f,0.0f };
	vertices[3].Pos = D3DXVECTOR3{ +0.5f,+0.5f,0.0f };


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

void Rect::UpdateWorld()
{
	//World(S,R,T)
	D3DXMATRIX W;
	D3DXMATRIX S, T;

	D3DXMatrixScaling(&S, scale.x, scale.y, 1);
	D3DXMatrixTranslation(&T, position.x, position.y, 0);
	//행렬곱
	W = S * T;
	shader->AsMatrix("World")->SetMatrix(W);
}
