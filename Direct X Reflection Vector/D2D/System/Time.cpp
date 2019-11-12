#include "stdafx.h"
#include "Time.h"


Time* Time::instance = NULL;
bool Time::isTimeStopped = true;
float Time::timeElapsed = 0.0f;
Time::Time()
	:tickerPerSecond(0), currentTime(0), lastTime(0), lastFPSUpdate(0), fpsUpdateInterval(0)
	, frameCount(0), runningTime(0), framePerSecond(0)
{
	QueryPerformanceFrequency((LARGE_INTEGER*)&tickerPerSecond);
	fpsUpdateInterval = tickerPerSecond >> 1;
}

Time::~Time()
{
}

Time * Time::Get()
{
	assert(instance != NULL);

	return instance;
}

void Time::Create()
{
	assert(instance == nullptr);
	instance = new Time();

}

void Time::Delete()
{
	SAFE_DELETE(instance);
}

void Time::Update()
{
	if (isTimeStopped) return; // isTimestopped�� ���߸�(Ʈ���) �ߴ�

	//1. ���� �ð��� �����ͼ� �ð� ���� �� ���� �ð��� ����Ѵ�.
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime); //����ð��� ����
	timeElapsed = (float)(currentTime - lastTime) / (float)tickerPerSecond; //�̷��� �и�����Ʈ ����
	//�� ���������κ��� ����ð��� (����ð����� �����ð���������) / ƽ ī��Ʈ�� �������̴�.
	runningTime += timeElapsed; //����ð� + ���� �ð�

	//2. FPS Update
	frameCount++; //�����Ӽ� ����
	if (currentTime - lastFPSUpdate >= fpsUpdateInterval)
		//����ð��� ������fps������Ʈ�ð��������� fps������Ʈ ���ݺ��� ũ�ų� ������
	{
		float tempCurrenTime = (float)currentTime / (float)tickerPerSecond;
		//������ ���� �ð� ������ ����ð��� FPS�� ���� ���� �ְ�
		float tempLastTime = (float)lastFPSUpdate / (float)tickerPerSecond;
		//������ ���� �ð� ������ ���� FPS ������Ʈ �ð��� FPS�� ���� ���� ������
		framePerSecond = (float)frameCount / (tempCurrenTime - tempLastTime);
		//FPS�� ������ ���� ������ (���Ƿ� ���� ����ð��� ���Ƿγ��� �����ð������� ����)

		lastFPSUpdate = (__int64)currentTime;
		//������ FPS������Ʈ �ð��� ����ð�
		frameCount = 0;
		//�ٽ� �����Ӽ��� 0���� �缳��
	}

	lastTime = currentTime;
}

void Time::Start()
{
	if (!isTimeStopped)
		assert(false);

	QueryPerformanceCounter((LARGE_INTEGER*)&lastTime);
	isTimeStopped = false;
}

void Time::Stop()
{
	if (isTimeStopped)
		assert(false);

	__int64 stopTime = 0;
	QueryPerformanceCounter((LARGE_INTEGER*)&stopTime);
	runningTime += (float)(stopTime - lastTime) / (float)tickerPerSecond;
	isTimeStopped = true;
}

