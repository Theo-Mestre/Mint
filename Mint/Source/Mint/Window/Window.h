#ifndef CORE_WINDOW_H
#define CORE_WINDOW_H

#include <SFML/Graphics/RenderWindow.hpp>

class Window
{
public:
	Window();
	Window(const char* _configFileName);
	~Window();

	void Create(const char* _configFileName);


	operator sf::RenderWindow& () { return m_window; }
	inline sf::RenderWindow& operator()() { return m_window; }
	sf::RenderWindow& Get() { return m_window; }
private:
	sf::RenderWindow m_window;
};
#endif