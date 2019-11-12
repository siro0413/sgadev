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
	if (isTimeStopped) return; // isTimestopped가 멈추면(트루면) 중단

	//1. 현재 시간을 가져와서 시간 간격 및 진행 시간을 계산한다.
	QueryPerformanceCounter((LARGE_INTEGER*)&currentTime); //현재시간에 저장
	timeElapsed = (float)(currentTime - lastTime) / (float)tickerPerSecond; //이러면 밀리세컨트 단위
	//전 프레임으로부터 경과시간은 (현재시간에서 이전시간을빼고난뒤) / 틱 카운트를 나눈값이다.
	runningTime += timeElapsed; //진행시간 + 현재 시간

	//2. FPS Update
	frameCount++; //프레임수 증가
	if (currentTime - lastFPSUpdate >= fpsUpdateInterval)
		//현재시간이 마지막fps업데이트시간을뺏을때 fps업데이트 간격보다 크거나 같을때
	{
		float tempCurrenTime = (float)currentTime / (float)tickerPerSecond;
		//임의의 현재 시간 변수에 현재시간를 FPS로 나눈 값을 넣고
		float tempLastTime = (float)lastFPSUpdate / (float)tickerPerSecond;
		//임의의 이전 시간 변수에 이전 FPS 업데이트 시간를 FPS로 나눈 값을 넣은후
		framePerSecond = (float)frameCount / (tempCurrenTime - tempLastTime);
		//FPS는 프레임 숫자 나누기 (임의로 넣은 현재시간에 임의로넣은 이전시간변수를 뺀값)

		lastFPSUpdate = (__int64)currentTime;
		//마지막 FPS업데이트 시간은 현재시간
		frameCount = 0;
		//다시 프래임수를 0으로 재설정
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

