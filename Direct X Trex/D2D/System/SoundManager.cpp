#include "stdafx.h"
#include "SoundManager.h"
using namespace FMOD;

SoundManager::SoundManager()
	:system(NULL), sound(NULL), channel(NULL), buffer(15), volume(1.0f)
{
	System_Create(&system);
	system->init(buffer, FMOD_INIT_NORMAL, 0);
	sound = new Sound*[buffer];
	channel = new Channel*[buffer];

	memset(sound, 0, sizeof(Sound*) * buffer);
	memset(channel, 0, sizeof(Sound*) * buffer);
	//memset = ZeroMemory ¿Í µ¿ÀÏ(ZeroMemory(sound, sizeof(Sound*) buffer
}

SoundManager::~SoundManager()
{
	if (channel != nullptr || sound != nullptr)
	{
		for (UINT i = 0; i < buffer; i++)
		{
			if (channel != nullptr)
			{
				if (channel[i])
					channel[i]->stop();
			}//if (channel != nullptr)
			if (sound != nullptr)
			{
				if (sound[i])
					sound[i]->release();
			}//if (sound != nullptr)
		}//for (UINT i = 0; i < buffer; i++)
	}//if (channel != nullptr || sound != nullptr)
	SAFE_DELETE(sound);
	SAFE_DELETE(channel);

	if (system != nullptr)
	{
		system->release();
		system->close();
	}

	sounds.clear();
}

void SoundManager::AddSound(string name, string soundFile, bool loop)
{
	if (loop == true)
	{
		system->createStream
		(
			soundFile.c_str(),
			FMOD_LOOP_NORMAL,
			NULL,
			&sound[sounds.size()]
		);
	}
	else
	{
		system->createStream
		(
			soundFile.c_str(),
			FMOD_LOOP_OFF,
			NULL,
			&sound[sounds.size()]
		);
	}
	sounds.insert(make_pair(name, &sound[sounds.size()]));
}

void SoundManager::Play(string name, float volume)
{
	int count = 0;
	iter = sounds.begin();

	for (iter; iter != sounds.end(); ++iter, count);
	{
		if (name == iter->first)
		{
			system->playSound(FMOD_CHANNEL_FREE, *iter->second, false, &channel[count]);
			channel[count]->setVolume(volume);
		}
	}
}

void SoundManager::Stop(string name)
{
}

void SoundManager::Pause(string name)
{
}

void SoundManager::Resume(string name)
{
}

bool SoundManager::Playing(string key)
{
	return false;
}

bool SoundManager::Paused(string Key)
{
	return false;
}

void SoundManager::Update()
{
}

void SoundManager::Volume(string name, float volume)
{
}
