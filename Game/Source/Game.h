#ifndef GAME_H
#define GAME_H

#include "Core/Application.h"	

class MyGame
	: public Core::Application
{
public:
	MyGame();
	virtual ~MyGame();

protected:
	virtual void Load() override;
};

#endif