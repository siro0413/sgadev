#include "stdafx.h"
#include "Trex.h"
#include "Object/Player.h"
#include "Object/BackGround.h"
#include "Object/Bullet.h"
#include "Object/Marker.h"
Trex::Trex(SceneValues * values)
	:Scene(values), bplay(false), speed(0), score(0), temp(0), hscore(0)
{
	srand((unsigned)time(NULL));

	wstring shaderFile = Shaders + L"Effect.fx";

	bg[0] = new Sprite(Textures + L"ground.png", shaderFile);
	bg[0]->Position(Width * -0.5f, -250);

	bg[1] = new Sprite(Textures + L"ground.png", shaderFile);
	bg[1]->Position(bg[0]->Position().x + bg[0]->TextureSize().x, -250);

	player = new Player(D3DXVECTOR2(-500, -200), D3DXVECTOR2(1.0f, 1.0f));
	D3DXVECTOR2 position;

	position.x = Math::Random((int)(Width * -0.5f), (int)(Width * 0.5f - 100));
	position.y = Math::Random(-150, int(Height * 0.5f) - 100);
	cloud.push_back(new Marker(shaderFile, position));

	position.x = Math::Random((int)(Width * 0.5f), Width);
	position.y = -200;
	bullet.push_back(new Bullet(shaderFile, position, 0));

	reSet = new Sprite(Textures + L"gameover.png", shaderFile);
	position.x = 0 - (reSet->TextureSize().x / 2-200);
	position.y = 10;
	reSet->Position(position);

	reStart = new Sprite(Textures + L"press.png", shaderFile);
	position.x = 0 - (reStart->TextureSize().x / 2-210);
	position.y = -90;
	reStart->Position(position);

	Iscore = new Sprite(Textures + L"score.png", shaderFile, 180, 0, 218, 21);
	position.x = -150;
	position.y = 270;
	Iscore->Position(position);

	player->GetAnimation()->Position(D3DXVECTOR2(-500, -200));
}

Trex::~Trex()
{
	SAFE_DELETE(Iscore);
	SAFE_DELETE(reStart);
	SAFE_DELETE(reSet);
	for (Marker* cloud : cloud)
	{
		SAFE_DELETE(cloud);
	}
	for (Bullet* bullets : bullet)
	{
		SAFE_DELETE(bullets);
	}
	SAFE_DELETE(player);
	SAFE_DELETE(bg[0]);
	SAFE_DELETE(bg[1]);


}

void Trex::Play()
{
	wstring shaderFile = Shaders + L"Effect.fx";
	score = 0;
	speed = 100;
	if (!bplays)
	{
		for (Marker* clouds : cloud)
		{
			SAFE_DELETE(clouds);
		}
		cloud.clear();

		for (Bullet* bullets : bullet)
		{
			SAFE_DELETE(bullets);
		}
		bullet.clear();
		D3DXVECTOR2 position;

		position.x = Math::Random((int)(Width * -0.5f), (int)(Width * 0.5f - 100));
		position.y = Math::Random(-150, int(Height * 0.5f) - 100);
		cloud.push_back(new Marker(shaderFile, position));

		position.x = Math::Random((int)(Width * 0.5f), Width);
		position.y = -200;
		bullet.push_back(new Bullet(shaderFile, position, 0));


		player->GetAnimation()->Position(D3DXVECTOR2(-500, -200));

	}
	player->GetAnimation()->Play(1);

	bplay = true;


}

void Trex::Update()
{

	D3DXMATRIX V = values->MainCamera->View();
	D3DXMATRIX P = values->Projection;
	if (bplay)
	{

		if (speed < 1300)
			speed += 0.1f;
		else
			speed = 1300;
		score += 0.001f * (speed*0.001f);
		if (temp >= 400)
		{
			D3DXVECTOR2 position;
			int type = rand() % 5;

			position.x = player->Position().x + 1500;
			position.y = Math::Random(-150, int(Height * 0.5f) - 100);
			cloud.push_back(new Marker(Shaders + L"Effect.fx", position));


			position.x = Math::Random((int)(Width * 0.5f), Width);
			if (type == 5)
				position.y = Math::Random(-180, -50);
			else
				position.y = -200;

			bullet.push_back(new Bullet(Shaders + L"Effect.fx", position, type));
			temp = rand() % 400;

		}
		else
			temp += 0.1f;

		if (bg[0]->Position().x + bg[0]->TextureSize().x <= Width * -0.5f)
			bg[0]->Position(bg[1]->Position().x + bg[1]->TextureSize().x, -250);
		if (bg[1]->Position().x + bg[1]->TextureSize().x <= Width * -0.5f)
			bg[1]->Position(bg[0]->Position().x + bg[0]->TextureSize().x, -250);

		bg[0]->Position(bg[0]->Position().x - (speed * Time::Delta()), bg[0]->Position().y);
		bg[1]->Position(bg[1]->Position().x - (speed * Time::Delta()), bg[1]->Position().y);
		for (Marker* clouds : cloud)
		{
			clouds->Position(clouds->Position().x - (speed * 0.2f * Time::Delta()), clouds->Position().y);
		}

		for (Bullet* bullets : bullet)
		{
			bullets->Position(bullets->Position().x - (speed * Time::Delta()), bullets->Position().y);

			//Sprite* playerRect = player->GetSprite();
			//Sprite* cactusRect = bullets->GetClip()->GetSprite();
			if (bullets->GetClip()->GetSprite()->Aabb(player->GetAnimation()->GetSprite()))
			{
				player->GetAnimation()->Play(2);
				bullets->GetClip()->Stop();
				if (hscore < score)
					hscore = score;

				if (bplays)
					bplays = false;
				bplay = false;
			}


		}
	}

	for (Marker* clouds : cloud)
	{
		clouds->Update(V, P);
		if (player->Position().x >= clouds->Position().x + 1000)
			cloud.erase(cloud.begin());
	}

	for (Bullet* bullets : bullet)
	{
		bullets->Update(V, P);
		if (player->Position().x >= bullets->Position().x + 1000)
			bullet.erase(bullet.begin());
	}
	player->Update(V, P);
	reSet->Update(V, P);
	reStart->Update(V, P);
	bg[0]->Update(V, P);
	bg[1]->Update(V, P);
	Iscore->Update(V, P);
}

void Trex::Render()
{
	bg[0]->Render();
	bg[1]->Render();
	for (Marker* clouds : cloud)
		clouds->Render();

	for (Bullet* bullets : bullet)
		bullets->Render();

	player->Render();

	if (player->GetAnimation()->Current() == 2)
		reSet->Render();

	if (!bplay)
		reStart->Render();

}

