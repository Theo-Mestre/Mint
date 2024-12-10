#ifndef GAME_H
#define GAME_H

#include "Mint/Application.h"	

class MyGame
	: public Mint::Application
{
public:
	MyGame();
	virtual ~MyGame();

protected:
	virtual void Load() override;
};

#endif