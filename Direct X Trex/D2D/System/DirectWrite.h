#pragma once

class DirectWrite
{
public:
	//½Ì±ÛÅæ
	static void Create();
	static void Delete();
	static DirectWrite* Get();
	static ID2D1DeviceContext* GetDC() { return deviceContext; }

	//2d¿ë BackBuffer°ü¸® ÇÔ¼ö
	static void CreateBackBuffer();
	static void DeleteBackBuffer();

	static void RenderText(wstring& text, RECT& rect);

private:
	DirectWrite();
	~DirectWrite();

	static DirectWrite* instance;

	ID2D1Factory1* factory;
	static IDWriteFactory* writeFactory;
	ID2D1Device* device;
	static ID2D1DeviceContext* deviceContext;
	static ID2D1Bitmap1* bitmap; //input backbuffer 
	static IDXGISurface* surface;
	static ID2D1SolidColorBrush* brush;
	static IDWriteTextFormat* format;
};

