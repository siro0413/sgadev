#include "stdafx.h"
#include "ColorPlayer.h"
#include "Object/Player.h"
#include "Object/Jumper.h"
#include "Object/Bullet.h"


ColorPlayer::ColorPlayer()
{

	jumper = new Jumper("бс");
	jumper->Position({ 50,20 });

}

ColorPlayer::~ColorPlayer()
{
	SAFE_DELETE(jumper);
	for (Bullet* bullet : bullets)
		SAFE_DELETE(bullet);
	for (Bullet* bullet : bullets2)
		SAFE_DELETE(bullet);
}

void ColorPlayer::Update()
{
	jumper->Update();

	if (jumper->RShoot())
	{
		COORD start = jumper->Position();
		Bullet* bullet = new Bullet("-", start, 2);
		bullets.push_back(bullet);
		jumper->RShoot(false);
	}
	else if (jumper->LShoot())
	{
		COORD start = jumper->Position();
		Bullet* bullet2 = new Bullet("-", start, 2);
		bullets2.push_back(bullet2);
		jumper->LShoot(false);
	}
	

	for (Bullet* bullet : bullets)
		bullet->Update(1);

	for (Bullet* bullet : bullets2)
		bullet->Update(2);

	for (size_t i = 0; i < bullets.size(); i++)
		if (bullets[i]->Position().X >= Width || bullets[i]->Position().X <= 0)
			bullets.erase(bullets.begin() + i);

	for (size_t i = 0; i < bullets2.size(); i++)
		if (bullets2[i]->Position().X >= Width || bullets2[i]->Position().X <= 0)
			bullets2.erase(bullets2.begin() + i);
}

void ColorPlayer::Render()
{
	jumper->Render(COLOR::PURPLE);
	for (Bullet* bullet : bullets)
		bullet->Render();
	for (Bullet* bullet : bullets2)
		bullet->Render();
}
