#pragma once

class Time
{
public:

	static Time* Get();

	static void Create();
	static void Delete();

	static bool Stopped() { return isTimeStopped; }
	static float Delta() { return isTimeStopped ? 0.0f : timeElapsed; }
	//참이면 0.0f반환 아니면 경과시간 반환

	void Update();

	void Start();
	void Stop();

	const float FPS() { return framePerSecond; }
	const float Running() { return runningTime; }

private:
	Time();
	~Time();

	static Time* instance;		//싱글톤 객체

	static bool isTimeStopped;	//타이머 중지
	static float timeElapsed;	//이전 프레임으로부터 경과시간
	__int64 tickerPerSecond;	//초당 틱 카운트

	__int64 currentTime;		//현재 시간
	__int64 lastTime;			//이전 시간
	__int64 lastFPSUpdate;		//마지막 FPS 업데이트 시간
	__int64 fpsUpdateInterval;	//FPS 업데이트 간격

	UINT frameCount;			//프레임 수
	float runningTime;			//진행 시간
	float framePerSecond;		//FPS
};

