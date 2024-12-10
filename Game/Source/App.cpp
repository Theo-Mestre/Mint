#include "gamepch.h"
#include "Game.h"

int main()
{
	auto game = std::make_unique<MyGame>();
	game->Run();
}