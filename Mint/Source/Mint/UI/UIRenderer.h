#ifndef UI_RENDERER_H
#define UI_RENDERER_H

#include <SFML/Graphics/RenderTexture.hpp>

#include <vector>

#include "Mint/UI/Elements/UIElement.h"

namespace Mint
{
	namespace UI
	{
		class UIElement;

		class UIRenderer
		{
		public:

			UIRenderer(Size _size)
				: m_renderTexture()
			{
				m_renderTexture.create((uint32_t)_size.width, (uint32_t)_size.height);
			}

			~UIRenderer() = default;

			void Render()
			{
				if (m_elements.empty()) return;

				m_renderTexture.clear(Color::Transparent);

				for (auto& element : m_elements)
				{
					element->ComputeLayout();
					element->Render(m_renderTexture);
				}

				m_renderTexture.display();

				m_elements.clear();
			}

			void Submit(UIElement* _element)
			{
				m_elements.push_back(_element);
			}

			sf::RenderTexture& GetRenderTexture() { return m_renderTexture; }

		private:
			std::vector<UIElement*> m_elements;

			sf::RenderTexture m_renderTexture;
		};
	}
}
#endif