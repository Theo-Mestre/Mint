#include "corepch.h"
#include "Time.h"

void Time::Init()
{
	Time::s_clock = sf::Clock();
	Time::s_time = sf::Time();
	Time::s_deltaTime = 0.f;
	Time::s_appTime = 0.f;

	Time::DeltaTime.SetValue(&s_deltaTime);
	Time::AppTime.SetValue(&s_appTime);
}

void Time::Restart()
{
	Time::s_time = Time::s_clock.restart();
	Time::s_deltaTime = Time::s_time.asSeconds();
	Time::s_appTime += Time::s_deltaTime;
}

const std::string& Time::GlobalTime()
{
	time_t now = time(0);
	tm tstruct;
	char string[16];

#pragma warning(suppress : 4996)
	tstruct = *localtime(&now);
	strftime(string, sizeof(string), "%X", &tstruct);

	return string;
}

sf::Time Time::GetTime()
{
	return Time::s_time;
}
