#ifndef CORE_APPLICATION_H
#define CORE_APPLICATION_H

#include "Managers/StateManager.h"
#include "AssetManagment/AssetsManager.h"
#include "Core/Managers/Renderer.h"
#include "Inputs/Inputs.h"

namespace Core
{
	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();

	protected:
		virtual void Load();
		virtual void EarlyUpdate();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render();
		virtual void Unload();

	protected:
		Ref<Window> m_window;
		Ref<Renderer> m_renderer;
		Ref<AssetsManager> m_assetsManager;
		Ref<StateManager> m_stateManager;
		Ref<State> m_currentState;
	};
}
#endif