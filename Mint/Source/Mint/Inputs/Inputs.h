#ifndef CORE_INPUTS_H
#define CORE_INPUTS_H

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Mouse.hpp>
#include <SFML/Window/Joystick.hpp>
#include <SFML/Window/Event.hpp>

namespace Mint
{
	using Inputs = sf::Keyboard;
	using Mouse = sf::Mouse;
	using Joystick = sf::Joystick;
}
#endif