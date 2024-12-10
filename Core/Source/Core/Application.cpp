#include "corepch.h"

#include "Window/Window.h"
#include "Managers/Manager.h"
#include "Managers/StateManager.h"
#include "Application.h"
#include "Logger.h"
#include "Time.h"

namespace Core
{
	Application::Application()
		: m_window(nullptr)
		, m_renderer(nullptr)
		, m_assetsManager(nullptr)
		, m_stateManager(nullptr)
		, m_currentState(nullptr)
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		Logger::Init();
		LogInfo("Application started");

		Time::Init();

		LogInfo("Application is loading");

		Load();

		LogInfo("Application loaded succefully");

		Time::Restart();

		while (m_window->Get().isOpen())
		{
			Time::Restart();

			EarlyUpdate();
			Update();
			LateUpdate();
			Render();
		}

		LogInfo("Application is unloading");

		Unload();

		LogInfo("Application unloaded succefully");
	}

	void Application::Load()
	{
		m_window = Ref<Window>(new Window());
		m_window->Create("AppData.bin");

		m_renderer = Ref<Renderer>(new Renderer());
		m_renderer->Create(m_window);

		m_stateManager = Ref<StateManager>(new StateManager());
		m_assetsManager = Ref<AssetsManager>(new AssetsManager());

		Manager::AddManager(m_window.get());
		Manager::AddManager(m_stateManager.get());
		Manager::AddManager(m_assetsManager.get());
	}

	void Application::EarlyUpdate()
	{
		m_currentState = m_stateManager->ProcessChange();

		m_currentState->EarlyUpdate();

		Event event = Event();
		while (m_window->Get().pollEvent(event))
		{
			m_currentState->OnEventReceived(event);

			if (event.type == Event::Closed)
				m_window->Get().close();
		}
	}

	void Application::Update()
	{
		m_currentState->Update();
	}

	void Application::LateUpdate()
	{
		m_currentState->LateUpdate();
	}

	void Application::Render()
	{
		m_currentState->Render(m_renderer);

		m_renderer->Render();
	}

	void Application::Unload()
	{
		m_window = nullptr;
		m_renderer = nullptr;
		m_assetsManager = nullptr;
		m_stateManager = nullptr;
		m_currentState = nullptr;
	}
}