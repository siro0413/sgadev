#include "stdafx.h"
#include "Camera.h"

Camera::Camera()
	:position(0,0)
{
	D3DXMatrixIdentity(&view);//��� �ʱ�ȭ
}

Camera::~Camera()
{
}

void Camera::Update()
{
	//View
	D3DXMatrixTranslation(&view, -position.x, -position.y, 0.0f);

}
