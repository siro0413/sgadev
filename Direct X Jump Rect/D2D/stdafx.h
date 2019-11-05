#pragma once

//Windows
#include <Windows.h>
#include <assert.h>
#include <map>
#include <functional>
#include <time.h>
//#include <iostream>
//#ifdef _DEBUG
//#pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console")
//#endif 

//STL
#include <vector>
#include <string>
using namespace std;

//DirecX
#include <d3d11.h>
#include <D3DX11.h>
#include <D3DX10.h>
#include <D3DX10math.h>
#include <d3dx11effect.h>
#include <d3dcompiler.h>


#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "d3dx11.lib")
#pragma comment(lib, "d3dx10.lib")

#pragma comment(lib, "effects11d.lib")
#pragma comment(lib, "d3dcompiler.lib")

//ImGui
#include <imgui.h>
#include <imguiDx11.h>
#pragma comment(lib, "imgui.lib")


//FrameWork
#include "Renders/Shader.h"
#include "System/Keyboard.h"
#include "Utilities/String.h"

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

extern Keyboard* Key;

//Macro Funtion
#define SAFE_RELEASE(p)			{if (p) {(p)->Release(); (p)= NULL;}}
#define SAFE_DELETE(p)			{ if (p) {delete(p);(p)=NULL;}}
#define SAFE_DLELTE_ARRAY(p)	{ if (p) {delete[](p);(p)=NULL;}}