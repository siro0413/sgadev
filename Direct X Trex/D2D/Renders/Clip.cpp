#include "stdafx.h"
#include "Clip.h"

//-----------------------------------------------------------------------------
//Frame(Struct)
//-----------------------------------------------------------------------------
Frame::Frame(Sprite * sprite, float time)
{
	Image = sprite;	//프레임 이미지 한장 (Frame Image)
	Time = time;	//프레임 한장을 띄우는 시간 (Frame Rendering Time)
}

Frame::~Frame()
{
	SAFE_DELETE(Image);
}
//-----------------------------------------------------------------------------
//Clip(Class)
//-----------------------------------------------------------------------------

Clip::Clip(PlayMode mode, float speed)
	:mode(mode), speed(speed), length(0), playTime(0), bPlay(false),
	position(0, 0), scale(1, 1), rotation(0, 0, 0), currentFrame(0)
{
}

Clip::~Clip()
{
	for (Frame* frame : frames)
		SAFE_DELETE(frame);
}

void Clip::Position(float x, float y)
{
	Position(D3DXVECTOR2(x, y));
}

void Clip::Position(D3DXVECTOR2 & vec)
{
	position = vec;
}

void Clip::Scale(float x, float y)
{
	Scale(D3DXVECTOR2(x, y));
}

void Clip::Scale(D3DXVECTOR2 & vec)
{
	scale = vec;
}

void Clip::Rotation(float x, float y, float z)
{
	Rotation(D3DXVECTOR3(x, y, z));
}

void Clip::Rotation(D3DXVECTOR3 & vec)
{
	rotation = vec;
}

void Clip::RotationDegree(float x, float y, float z)
{
	RotationDegree(D3DXVECTOR3(x, y, z));
}

void Clip::RotationDegree(D3DXVECTOR3 & vec)
{
	D3DXVECTOR3 temp = Rotation();
	temp.x = Math::ToDegree(vec.x);
	temp.y = Math::ToDegree(vec.y);
	temp.z = Math::ToDegree(vec.z);
	Rotation(temp);
}

D3DXVECTOR3 Clip::RotationDegree()
{
	D3DXVECTOR3 temp = Rotation();
	temp.x = Math::ToDegree(temp.x);
	temp.y = Math::ToDegree(temp.y);
	temp.z = Math::ToDegree(temp.z);

	return temp;
}

void Clip::AddFrame(Sprite * sprite, float time)
{
	frames.push_back(new Frame(sprite, time));
}

D3DXVECTOR2 Clip::TexturSize()
{
	return frames[currentFrame]->Image->TextureSize();
}

void Clip::Play()
{
	playTime = 0.0f;
	currentFrame = 0;
	bPlay = true;
}

void Clip::Play(UINT startFrame)
{
	playTime = 0.0f;
	currentFrame = startFrame;
	bPlay = true;
}

void Clip::Stop()
{
	bPlay = false;
	currentFrame = 0;
}

void Clip::Update(D3DXMATRIX & V, D3DXMATRIX & P)
{
	Frame* frame = frames[currentFrame];

	if (bPlay == true)
	{
		float time = frame->Time * speed;	//time : 그림 한장을 띄우는 시간
		playTime += Time::Delta();			//real Timer

		if (playTime >= time)
		{
			switch (mode)
			{
			case PlayMode::End:
			{
				currentFrame++;
				if (currentFrame >= frames.size())
					Stop();
			}
			break;
			case PlayMode::Loop:
			{
				currentFrame++;
				currentFrame %= frames.size();
			}
			break;
			case PlayMode::Reverse:
			{
				if (currentFrame <= 0)
					currentFrame = frames.size();
				currentFrame--;
			}
			break;
			}//switch (mode)
			playTime = 0.0f;
		}//if (playTime >= time)
	}

	frames[currentFrame]->Image->Position(position);
	frames[currentFrame]->Image->Scale(scale);
	frames[currentFrame]->Image->Rotation(rotation);
	frames[currentFrame]->Image->Update(V, P);
}

void Clip::Render()
{
	Frame* frame = frames[currentFrame];
	frame->Image->Render();
}

void Clip::DrawBound(bool val)
{
	for (Frame* frame : frames)
		frame->Image->DrawBound(val);
}

Sprite * Clip::GetSprite()
{
	return frames[currentFrame]->Image;
}
