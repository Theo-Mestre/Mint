#include "corepch.h"
#include "StaticSprite.h"

namespace Core
{
	StaticSprite::StaticSprite()
		: StaticSprite(nullptr)
	{
	}

	StaticSprite::StaticSprite(const Ref<Texture2D>& _texture)
		: m_texture(_texture)
	{
		UpdatePositions();
	}

	StaticSprite::~StaticSprite()
	{
	}

	void StaticSprite::SetTexture(const Ref<Texture2D>& _texture)
	{
		m_texture = _texture;
		UpdatePositions();
	}

	Ref<Texture2D> StaticSprite::GetTexture(void) const
	{
		return m_texture;
	}

	void StaticSprite::SetColor(const sf::Color& _color)
	{
		for (int i = 0; i < 4; i++)
		{
			m_vertices[i].color = _color;
		}
	}
	sf::Color StaticSprite::GetColor(void) const
	{
		return m_vertices[0].color;
	}
	sf::FloatRect StaticSprite::GetLocalBounds(void) const
	{
		sf::Vector2f texSize = static_cast<sf::Vector2f>(m_texture->Get().getSize());
		return sf::FloatRect(0.f, 0.f, texSize.x, texSize.y);
	}
	sf::FloatRect StaticSprite::GetGlobalBounds(void) const
	{
		return getTransform().transformRect(GetLocalBounds());
	}
	void StaticSprite::UpdatePositions(void)
	{
		if (m_texture == nullptr) return;

		sf::Vector2f texSize = static_cast<sf::Vector2f>(m_texture->Get().getSize());

		m_vertices[0].position = sf::Vector2f(0.f, 0.f);
		m_vertices[1].position = sf::Vector2f(0.f, texSize.y);
		m_vertices[2].position = sf::Vector2f(texSize.x, texSize.y);
		m_vertices[3].position = sf::Vector2f(texSize.x, 0.f);

		m_vertices[0].texCoords = m_vertices[0].position;
		m_vertices[1].texCoords = m_vertices[1].position;
		m_vertices[2].texCoords = m_vertices[2].position;
		m_vertices[3].texCoords = m_vertices[3].position;
	}
	void StaticSprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (m_texture == nullptr) return;

		states.transform *= getTransform();
		states.texture = &m_texture->Get();
		target.draw(m_vertices, 4, sf::Quads, states);
	}
}