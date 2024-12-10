#ifndef RENDERER_H
#define RENDERER_H

#include <vector>

#include "Mint/Utilities/Ref.h"

namespace sf
{
	class Drawable;
}
class Window;

namespace Mint
{
	using Renderable = sf::Drawable;

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void Create(Ref<Window> _window);

		void Submit(Ref<Renderable> _object);
		void Submit(const Renderable* _object);

		void Render();

	public: // Delete copy and move constructors and operators
		Renderer(const Renderer&) = delete;
		Renderer(Renderer&&) = delete;

		Renderer& operator=(const Renderer&) = delete;
		Renderer& operator=(Renderer&&) = delete;

	private:
		std::vector<const Renderable*> m_renderQueue;
		Ref<Window> m_window;
	};
}
#endif