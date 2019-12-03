#include "stdafx.h"
#include "Camera.h"

Camera::Camera()
	:position(0,0)
{
	D3DXMatrixIdentity(&view);//행렬 초기화
}

Camera::~Camera()
{
}

void Camera::Update()
{
	//View
	D3DXMatrixTranslation(&view, -position.x, -position.y, 0.0f);

}
