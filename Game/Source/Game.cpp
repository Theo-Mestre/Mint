#include "gamepch.h"
#include "Game.h"
#include "GameStates/MainMenuState.h"

MyGame::MyGame()
	: Mint::Application()
{
}

MyGame::~MyGame()
{
}

void MyGame::Load()
{
	Mint::Application::Load();

	m_stateManager->Add(CreateRef<MainMenuState>());
}
