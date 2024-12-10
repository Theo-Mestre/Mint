#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <SFML/Graphics/VertexArray.hpp>

#include <vector>
#include <string>

#include "Mint/UI/Style.h"

namespace Mint
{
	namespace UI
	{
		class UIElement
		{
		public:
			UIElement();
			virtual ~UIElement();

			void Add(UIElement* _child)
			{
				_child->SetParent(this);
				m_children.push_back(_child);
				Modified(true);
			}
			std::vector<UIElement*> GetChildren() const { return m_children; }

			void SetParent(UIElement* _parent) { m_parent = _parent; }

			// Layout info
			void SetStyle(const Style& _newStyle) 
			{
				m_style = _newStyle;
				Modified(true);
			}
			Style& GetStyle() { return m_style; }

			void ComputeLayout();

			void Modified(bool _state)
			{
				m_dirty = _state;
				if (m_parent != nullptr) m_parent->Modified(_state);
				
			}

			sf::VertexArray& GetVertices();

		private:
			friend class UIRenderer;
			void Render(sf::RenderTexture& context);

		protected:
			void ResolveLayout();

		protected:
			Style m_style;
			bool m_dirty;

			UIElement* m_parent = nullptr;
			std::vector<UIElement*> m_children;

			sf::VertexArray m_vertices;
		};
	}
}
#endif