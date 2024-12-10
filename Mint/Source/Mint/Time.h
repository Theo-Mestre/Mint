#ifndef CORE_TIME_H
#define CORE_TIME_H

#include <string>
#include <SFML/System/Clock.hpp>

#include "Utilities/Property.h"

class Time final
{
public:
	/**\brief Initialize the time class and properties*/
	static void Init();

	/**\brief Restart the game's clock and udpate time data.*/
	static void Restart();

	/**\brief Return the delta time as sf::Time.*/
	static sf::Time GetTime();
	/**\brief Return the global time as a string.*/
	static const std::string& GlobalTime();

	// Properties
	inline static PropertyReadOnly<float> DeltaTime;
	inline static PropertyReadOnly<float> AppTime;

private:
	Time();
	~Time() = default;
private:
	inline static sf::Clock s_clock;
	inline static sf::Time s_time;
	inline static float s_deltaTime;
	inline static float s_appTime;
};
#endif 