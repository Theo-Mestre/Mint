#include "corepch.h"
#include "Renderer.h"

#include "Core/Window/Window.h"

namespace Core
{
	Renderer::Renderer()
		: m_window(nullptr)
	{
	}

	Renderer::~Renderer()
	{
		m_window = nullptr;
		m_renderQueue.clear();
	}

	void Renderer::Create(Ref<Window> _window)
	{
		m_window = _window;
	}

	void Renderer::Submit(Ref<Renderable> _object)
	{
		m_renderQueue.push_back(_object.get());
	}

	void Renderer::Submit(const Renderable* _object)
	{
		m_renderQueue.push_back(_object);
	}

	void Renderer::Render()
	{
		if (m_window == nullptr)
		{
			LogError("Renderer::Render: Window is nullptr");
			return;
		}

		auto& window = m_window->Get();

		window.clear();
		for (auto renderable : m_renderQueue)
		{
			window.draw(*renderable);
		}
		window.display();

		m_renderQueue.clear();
	}
}