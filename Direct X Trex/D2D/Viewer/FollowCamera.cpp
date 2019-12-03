#include "stdafx.h"
#include "FollowCamera.h"

FollowCamera::FollowCamera(IFollow * focus)
	:focus(focus)
{
}

FollowCamera::~FollowCamera()
{
}

void FollowCamera::Change(IFollow * focus)
{
	this->focus = focus;
}

void FollowCamera::Update()
{
	if (focus == NULL)
		return;

	D3DXVECTOR2 location, size;

	focus->Focus(&location, &size);
	D3DXVECTOR2 temp = location;
	//포거스 대상 위치를 화면 중심
	temp.x -= (float)Width*0.5f;
	temp.y -= (float)Height*0.5f;

	temp.x += size.x *0.5f;
	temp.y += size.y *0.5f;

	position = temp;

	__super::Update();
}
