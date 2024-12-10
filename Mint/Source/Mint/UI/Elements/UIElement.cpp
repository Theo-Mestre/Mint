#include "mintpch.h"
#include "UIElement.h"

namespace Mint
{
	namespace UI
	{
		UIElement::UIElement()
			: m_vertices{ sf::Quads }
			, m_dirty(true)
		{
			m_vertices.resize(4);
		}

		UIElement::~UIElement()
		{
			for (auto& child : m_children)
			{
				delete child;
				child = nullptr;
			}
		}

		void UIElement::ComputeLayout()
		{
			if (m_dirty == false) return;

			ResolveLayout();

			for (auto& child : m_children)
			{
				child->ComputeLayout();
			}
		}

		void UIElement::Render(sf::RenderTexture& context)
		{
			context.draw(m_vertices);
			for (auto& child : m_children)
			{
				child->Render(context);
			}
		}

		sf::VertexArray& UIElement::GetVertices()
		{
			return m_vertices;
		}

		void UIElement::ResolveLayout()
		{
			Rect& RB = m_style.ResolvedBound;
			if (m_parent == nullptr)
			{
				m_vertices[0].position = { RB.position.x, RB.position.y };
				m_vertices[1].position = { RB.position.x + RB.size.width, RB.position.y };
				m_vertices[2].position = { RB.position.x + RB.size.width, RB.position.y + RB.size.height };
				m_vertices[3].position = { RB.position.x, RB.position.y + RB.size.height };

				m_vertices[0].color = m_style.BackgroundColor;
				m_vertices[1].color = m_style.BackgroundColor;
				m_vertices[2].color = m_style.BackgroundColor;
				m_vertices[3].color = m_style.BackgroundColor;
				return;
			}



			Rect& PRB = m_parent->GetStyle().ResolvedBound;
			if (m_style.PositionType == PositionType::Absolute)
			{
				m_style.ResolvedBound.position = m_style.Bound.position;
			}
			else
			{
				m_style.ResolvedBound.position = m_style.Bound.position + m_parent->GetStyle().ResolvedBound.position;
				/*
				auto childNumber = m_parent->m_children.size();
				auto childIndex = std::distance(m_parent->m_children.begin(), std::find(m_parent->m_children.begin(), m_parent->m_children.end(), this));

				// Resolve x and y
				if (childIndex == 0)
				{
					RB.position.x = 0.0f;
					RB.position.y = 0.0f;
				}
				else
				{
					RB.position.x = m_parent->m_children[childIndex - 1]->m_style.ResolvedBound.position.x + m_parent->m_children[childIndex - 1]->m_style.ResolvedBound.size.width;
					RB.position.y = m_parent->m_children[childIndex - 1]->m_style.ResolvedBound.position.y;
				}

				// Resolve width and height
				if (childIndex == childNumber - 1)
				{
					RB.size.width = PRB.size.width - RB.position.x;
					RB.size.height = PRB.size.height - RB.position.y;
				}
				else
				{
					RB.size.width = m_style.Bound.size.width;
					RB.size.height = m_style.Bound.size.height;
				}


				if (RB.position.x + RB.size.width > PRB.size.width) { RB.size.width = RB.position.x - PRB.size.width; }
				if (RB.position.y + RB.size.height > PRB.size.height) { RB.size.height = RB.position.y - PRB.size.height; }
				*/
			}
			m_vertices[0].position = { RB.position.x, RB.position.y };
			m_vertices[1].position = { RB.position.x + RB.size.width, RB.position.y };
			m_vertices[2].position = { RB.position.x + RB.size.width, RB.position.y + RB.size.height };
			m_vertices[3].position = { RB.position.x, RB.position.y + RB.size.height };

			m_vertices[0].color = m_style.BackgroundColor;
			m_vertices[1].color = m_style.BackgroundColor;
			m_vertices[2].color = m_style.BackgroundColor;
			m_vertices[3].color = m_style.BackgroundColor;
		}
	}
}