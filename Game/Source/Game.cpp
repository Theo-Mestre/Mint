#include "gamepch.h"
#include "Game.h"
#include "GameStates/MainMenuState.h"

MyGame::MyGame()
	: Core::Application()
{
}

MyGame::~MyGame()
{
}

void MyGame::Load()
{
	Core::Application::Load();

	m_stateManager->Add(CreateRef<MainMenuState>());
}
