#pragma once

class Time
{
public:

	static Time* Get();

	static void Create();
	static void Delete();

	static bool Stopped() { return isTimeStopped; }
	static float Delta() { return isTimeStopped ? 0.0f : timeElapsed; }
	//���̸� 0.0f��ȯ �ƴϸ� ����ð� ��ȯ

	void Update();

	void Start();
	void Stop();

	const float FPS() { return framePerSecond; }
	const float Running() { return runningTime; }

private:
	Time();
	~Time();

	static Time* instance;		//�̱��� ��ü

	static bool isTimeStopped;	//Ÿ�̸� ����
	static float timeElapsed;	//���� ���������κ��� ����ð�
	__int64 tickerPerSecond;	//�ʴ� ƽ ī��Ʈ

	__int64 currentTime;		//���� �ð�
	__int64 lastTime;			//���� �ð�
	__int64 lastFPSUpdate;		//������ FPS ������Ʈ �ð�
	__int64 fpsUpdateInterval;	//FPS ������Ʈ ����

	UINT frameCount;			//������ ��
	float runningTime;			//���� �ð�
	float framePerSecond;		//FPS
};

