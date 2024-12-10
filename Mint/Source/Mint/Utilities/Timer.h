#ifndef TIMER_H
#define TIMER_H

/**\brief An utility class to create a timer and to manage it.*/
class Timer
{
public:
	Timer();
	Timer(float _maxTime);
	~Timer();

	/**\brief Update the time and check if the limit has been reached.*/
	void Update(float dt);

	/**\brief Return the time elapsed since the last 'start'.*/
	float GetTime(void) const;
	/**\brief Return the max time value that the time can reach.*/
	float GetMaxTime(void) const;
	/**\brief Return the remaining time before the timer end.*/
	float GetRemainingTime(void) const;

	/**\brief Set the timer to a specific time.*/
	void SetTime(float _time);
	/**\brief Set a new time limit to the timer.*/
	void SetMaxTime(float _maxTime);

	/**\brief Restart the timer.*/
	void Restart(void);
	/**\brief Start the timer update.*/
	void Start(void);
	/**\brief Stop the timer update.*/
	void Stop(void);
	/**\brief Set the timer state to 'ended'.*/
	void End(void);

	/**\brief Return if the timer is running*/
	bool IsRunning(void) const;
	/**\brief Return if the timer has ended.*/
	bool HasEnded(void) const;
	
private:
	float m_time;
	float m_maxTime;
	
	bool m_isRunning;
	bool m_hasEnded;
};
#endif