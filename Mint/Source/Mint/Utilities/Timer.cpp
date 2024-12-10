#include "mintpch.h"
#include "Timer.h"

Timer::Timer() : Timer(0.f) {}

Timer::Timer(float _maxTime)
{
	m_time = 0;
	m_maxTime = _maxTime;
	m_isRunning = false;
	m_hasEnded = false;

	Start();
}

Timer::~Timer()
{
}

void Timer::Update(float dt)
{
	if (m_isRunning == false) { return; }

	m_time += dt;

	if (m_time >= m_maxTime)
	{
		Stop();
		End();
	}
}

float Timer::GetTime(void) const
{
	return m_time;
}

float Timer::GetMaxTime(void) const
{
	return m_maxTime;
}

float Timer::GetRemainingTime(void) const
{
	return m_maxTime - m_time;
}

void Timer::SetTime(float _time)
{
	m_time = _time;
}

void Timer::SetMaxTime(float _maxTime)
{
	m_maxTime = _maxTime;
}

void Timer::Restart(void)
{
	m_time -= m_maxTime;
	m_time = m_time <= 0.0f ? 0.0f : m_time;
	m_hasEnded = false;
	Start();
}

void Timer::Start(void)
{
	m_isRunning = true;
}

void Timer::Stop(void)
{
	m_isRunning = false;
}

void Timer::End(void)
{
	m_hasEnded = true;
}

bool Timer::IsRunning(void) const
{
	return m_isRunning;
}

bool Timer::HasEnded(void) const
{
	return m_hasEnded;
}