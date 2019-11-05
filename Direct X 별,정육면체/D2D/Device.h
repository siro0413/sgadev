#pragma once

//Windows
#include <Windows.h>
#include <assert.h>

//STL
#include <vector>
#include <string>
using namespace std;

//DirecX
#include <d3d11.h>
#include <D3DX11.h>
#include <D3DX10.h>
#include <D3DX10math.h>

#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")

//Golba
const UINT Width = 1024;
const UINT Height = 768;

extern HWND Hwnd;
extern wstring Title;

//DX interfaces
extern IDXGISwapChain* SwapChain;
extern ID3D11Device* Device;
extern ID3D11DeviceContext* DeviceContext;
extern ID3D11RenderTargetView* RTV;

extern ID3D11VertexShader* VertexShader;
extern ID3D11PixelShader* PixelShader;
extern ID3D10Blob* VsBlob;
extern ID3D10Blob* PsBlob;

//Function
void InitWindow(HINSTANCE hInstance, int nCmdShow);
void InitDirect3D(HINSTANCE hInstance);
void Destroy();
WPARAM Running();
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);

//Scene
void InitScene();
void DestroyScene();
void Update();
void Render();

