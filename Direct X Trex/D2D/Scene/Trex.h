#pragma once
#include "Scene.h"
class Trex : public Scene
{
public:
	Trex(SceneValues* values);
	~Trex();

	class Player* GetPlayer() { return player; }
	
	void Update() override;
	void Render() override;
	
	void Play();

	bool bPlay() { return bplay; }
	auto Score() { return score; }
	auto HScore() { return hscore; }
	auto Speed() { return speed; }


private:
	Sprite* bg[2];
	Sprite* reSet;
	Sprite* reStart;
	Sprite* Iscore;

	class Player* player;

	vector<class Marker*> cloud;
	vector<class Bullet*> bullet;

	bool bplay;
	float speed;
	float score;
	float hscore;
	bool bplays = true;
	UINT fCloud = 0, fCactus = 0;

	float temp; 


};

