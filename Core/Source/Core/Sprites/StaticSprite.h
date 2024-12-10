#ifndef CORE_STATIC_SPRITE_H
#define CORE_STATIC_SPRITE_H

#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "Core/AssetManagment/Assets.h"
#include "Core/Utilities/Ref.h"

namespace Core
{
	class StaticSprite
		: public sf::Drawable
		, public sf::Transformable
	{
	public:
		StaticSprite();
		StaticSprite(const Ref<Texture2D>& _texture);
		~StaticSprite();

		void SetTexture(const Ref<Texture2D>& _texture);
		Ref<Texture2D> GetTexture(void) const;

		void SetColor(const sf::Color& _color);
		sf::Color GetColor(void) const;

		sf::FloatRect GetLocalBounds(void) const;
		sf::FloatRect GetGlobalBounds(void) const;

	private:
		void UpdatePositions(void);

		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	private:
		Ref<Texture2D> m_texture;
		sf::Vertex m_vertices[4];
	};
}
#endif