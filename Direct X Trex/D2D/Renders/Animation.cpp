#include "stdafx.h"
#include "Animation.h"

Animation::Animation()
	:currenClip(-1), position(0, 0), scale(1, 1), rotation(0, 0, 0)
{
}

Animation::~Animation()
{
	for (Clip* clip : clips)
		SAFE_DELETE(clip);
}

void Animation::AddClip(Clip * clip)
{
	clips.push_back(clip);
}

void Animation::Play(UINT clipNumber)
{
	if (clipNumber == currenClip)
		return;

	if (clipNumber > -1)
		clips[currenClip]->Stop();

	currenClip = clipNumber;
	clips[currenClip]->Play();
}

void Animation::Stop()
{
	if (currenClip > -1)
		clips[currenClip]->Stop();
}

void Animation::Position(float x, float y)
{
	Position(D3DXVECTOR2(x, y));
}

void Animation::Position(D3DXVECTOR2 & vec)
{
	position = vec;
}

void Animation::Scale(float x, float y)
{
	Scale(D3DXVECTOR2(x, y));
}

void Animation::Scale(D3DXVECTOR2 & vec)
{
	scale = vec;
}

void Animation::Rotation(float x, float y, float z)
{
	Rotation(D3DXVECTOR3(x, y, z));
}

void Animation::Rotation(D3DXVECTOR3 & vec)
{
	rotation = vec;
}

void Animation::RotationDegree(float x, float y, float z)
{
	RotationDegree(D3DXVECTOR3(x, y, z));
}

void Animation::RotationDegree(D3DXVECTOR3 & vec)
{
	vec.x = Math::ToRadian(vec.x);
	vec.y = Math::ToRadian(vec.y);
	vec.z = Math::ToRadian(vec.z);

	Rotation(vec);
}

D3DXVECTOR3 Animation::RotationDegree()
{
	D3DXVECTOR3 vec = Rotation();
	vec.x = Math::ToDegree(vec.x);
	vec.y = Math::ToDegree(vec.y);
	vec.z = Math::ToDegree(vec.z);
	return vec;
}

D3DXVECTOR2 Animation::TexturSize()
{
	if (currenClip < 0)
		return D3DXVECTOR2(0, 0);
	return clips[currenClip]->TexturSize();
}

void Animation::Update(D3DXMATRIX& V,D3DXMATRIX& P)
{
	if (currenClip < 0)
		return;

	clips[currenClip]->Position(position);
	clips[currenClip]->Scale(scale);
	clips[currenClip]->Rotation(rotation);
	
	clips[currenClip]->Update(V, P);

}

void Animation::Render()
{
	if (currenClip < 0)
		return;

	clips[currenClip]->Render();
}

void Animation::DrawBound(bool val)
{
	for (Clip* clip : clips)
		clip->DrawBound(val);
}

Clip * Animation::GetClip()
{
	if (currenClip < 0)
		return NULL;

	return clips[currenClip];
}

Sprite * Animation::GetSprite()
{
	return GetClip()->GetSprite();
}
