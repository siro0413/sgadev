#pragma once
#include "IFollow.h"
#include "Camera.h"
class FollowCamera : public Camera
{
public:
	FollowCamera(IFollow* focus = NULL);
	~FollowCamera();

	void Change(IFollow* focus); //���� ����� �ٸ������� �ű��
	void Update();

private:
	IFollow* focus;
};

