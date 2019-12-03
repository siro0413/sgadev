#pragma once
#include "stdafx.h"
#include "Viewer/Camera.h"
struct SceneValues
{
	//D3DXMATRIX View; //Main Camera
	class Camera* MainCamera;
	D3DXMATRIX Projection;
};

//////////////////////////////////
class Scene
{
public:
	Scene(SceneValues* values)
		:values(values) {}
	virtual ~Scene() {};

	virtual void Update() = 0;
	virtual void Render() = 0;

protected:
	SceneValues* values;
};

/*
IA -> VS -> RS -> PS -> OM
IA backbuffer,정점
VS world,view,projection
RS viewport 절두체를 정사각형으로 변경으로인해 원근감
PS 
OM 
*/