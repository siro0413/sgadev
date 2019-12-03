#pragma once
#include "IFollow.h"
#include "Camera.h"
class FollowCamera : public Camera
{
public:
	FollowCamera(IFollow* focus = NULL);
	~FollowCamera();

	void Change(IFollow* focus); //시점 대상을 다른곳으로 옮기기
	void Update();

private:
	IFollow* focus;
};

