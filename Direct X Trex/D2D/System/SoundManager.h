#pragma once

class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	void AddSound(string name, string soundFile, bool loop = false);
	void Play(string name, float volume = 1.0f);
	void Stop(string name);
	void Pause(string name);
	void Resume(string name);
	
	bool Playing(string key);
	bool Paused(string Key);

	void Update();

	void Volume(string name, float volume);
	float Volume() { return volume; }

private:
	System* system; //FMOD::System 이게 정석
	Sound** sound;
	Channel** channel;

	UINT buffer;

	map<string, Sound**> sounds;
	map<string, Sound**>::iterator iter;

	float volume;

};

