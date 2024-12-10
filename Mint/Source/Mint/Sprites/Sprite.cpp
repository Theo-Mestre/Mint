#include "mintpch.h"

#include "Sprite.h"
#include "Mint/Time.h"
#include "Mint/Utilities/Timer.h"
#include "Mint/AssetManagment/Assets.h"

namespace Mint
{
	Sprite::Sprite()
	{
		m_texture = nullptr;
		m_currentFrameIndex = 0;
		m_currentAnimationIndex = 0;
		SetCurrentFrame(m_currentFrameIndex);
		m_timer.SetMaxTime(1.0f);

		Pause();
		SetLoop(false);
	}

	Sprite::Sprite(const Animation& _animation)
	{
		Init(_animation);
	}

	Sprite::~Sprite()
	{
		m_animations.clear();
		m_texture = nullptr;
	}

	void Sprite::Init(const Animation& _animation)
	{
		m_animations.push_back(_animation);
		m_texture = m_animations.back().GetSpriteSheet();
		m_currentAnimationIndex = 0;
		m_currentFrameIndex = 0;
		SetCurrentFrame(m_currentFrameIndex);
		m_timer.SetMaxTime(m_animations.back().GetFrameTime());
		m_direction = AnimDirection::Forward;
		Play();
		SetLoop(true);
	}

	bool Sprite::Init()
	{
		if (m_animations.size() > 0)
		{
			m_texture = m_animations.at(0).GetSpriteSheet();
			m_currentFrameIndex = 0;
			SetCurrentFrame(m_currentFrameIndex);
			m_timer.SetMaxTime(m_animations.at(0).GetFrameTime());
			m_direction = AnimDirection::Forward;
			Play();
			SetLoop(true);
			return true;
		}
		return false;
	}

	void Sprite::Update()
	{
		Animation& currentAnimation = m_animations.at(m_currentAnimationIndex);

		// if not paused and we have a valid animation
		if (m_isPaused && !currentAnimation.IsCreated()) { return; }

		// add delta time
		m_timer.Update(Time::DeltaTime());

		// if current time is bigger then the frame time advance one frame
		if (m_timer.HasEnded())
		{
			m_timer.Restart();

			// get next frame index
			if (m_currentFrameIndex + 1 < currentAnimation.GetFrameNumber())
			{
				m_currentFrameIndex++;
			}
			else
			{
				if (m_doesLoop == false)
				{
					m_isPaused = true;
				}
				else
				{
					m_currentFrameIndex = 0;
				}
			}
			// set the current frame, not reseting the time
			SetCurrentFrame(m_currentFrameIndex, false);
		}
	}

	void Sprite::Play()
	{
		m_isPaused = false;
		m_timer.Start();
	}

	void Sprite::Play(const Animation& animation)
	{
		Play();
	}

	void Sprite::Pause()
	{
		m_isPaused = true;
		m_timer.Stop();
	}

	void Sprite::Stop()
	{
		Pause();
		m_timer.SetTime(0.0f);
	}

	void Sprite::SetLoop(bool _loop)
	{
		m_doesLoop = _loop;
	}

	size_t Sprite::AddAnimation(const Animation& animation)
	{
		m_animations.push_back(animation);
		return m_animations.size() - 1;
	}

	void Sprite::SetCurrentAnimation(size_t index)
	{
		m_currentAnimationIndex = index;
		m_currentFrameIndex = 0;
		m_timer.SetMaxTime(m_animations.at(m_currentAnimationIndex).GetFrameTime());
		m_timer.Restart();
	}

	Animation& Sprite::GetCurrentAnimation(void)
	{
		return m_animations.at(m_currentAnimationIndex);
	}

	bool Sprite::IsPlaying(void) const
	{
		return m_isPaused == false;
	}

	bool Sprite::IsLooping(void) const
	{
		return m_doesLoop;
	}

	void Sprite::SetCurrentFrame(size_t _frame, bool _resetTime)
	{
		// Quit if the current animation is not created
		if (m_animations.empty() || !m_animations.at(m_currentAnimationIndex).IsCreated()) { return; }

		// Update vertices and texture coords
		sf::FloatRect rect = static_cast<sf::FloatRect>(m_animations.at(m_currentAnimationIndex).GetFrame(_frame));

		m_vertices[0].position = sf::Vector2f(0.f, 0.f);
		m_vertices[1].position = sf::Vector2f(0.f, rect.height);
		m_vertices[2].position = sf::Vector2f(rect.width,rect.height);
		m_vertices[3].position = sf::Vector2f(rect.width, 0.f);

		float x = rect.left;
		float y = rect.top;
		float width = x + rect.width;
		float height = y + rect.height;

		m_vertices[0].texCoords = sf::Vector2f(x, y);
		m_vertices[1].texCoords = sf::Vector2f(x, height);
		m_vertices[2].texCoords = sf::Vector2f(width, height);
		m_vertices[3].texCoords = sf::Vector2f(width, y);

		if (_resetTime) { m_timer.Restart(); }
	}

	size_t Sprite::GetCurrentFrame(void) const
	{
		return m_currentFrameIndex;
	}

	void Sprite::SetFrameTime(float _time)
	{
		m_timer.SetMaxTime(_time);
		GetCurrentAnimation().SetFrameTime(_time);
	}

	float Sprite::GetFrameTime(void) const
	{
		return m_timer.GetMaxTime();
	}

	void Sprite::ResetAnimationProgression(void)
	{
		m_currentFrameIndex = 0;
	}

	void Sprite::SetColor(const sf::Color& color)
	{
		for (int i = 0; i < 4; ++i)
		{
			m_vertices[i].color = color;
		}
	}

	sf::FloatRect Sprite::GetLocalBounds(void) const
	{
		sf::IntRect rect = m_animations.at(m_currentAnimationIndex).GetFrame(m_currentFrameIndex);
		return sf::FloatRect(0.f, 0.f, static_cast<float>(rect.width), static_cast<float>(rect.height));
	}

	sf::FloatRect Sprite::GetGlobalBounds(void) const
	{
		return getTransform().transformRect(GetLocalBounds());
	}

	void Sprite::SetDirection(AnimDirection _direction)
	{
		if (m_direction != _direction)
		{
			m_direction = _direction;
			setScale(-getScale().x, getScale().y);
		}
	}

	AnimDirection Sprite::GetDirection(void) const
	{
		return m_direction;
	}

	void Sprite::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		if (m_texture != nullptr && m_animations.at(m_currentAnimationIndex).IsCreated())
		{
			states.transform *= getTransform();
			states.texture = &m_texture->Get();
			target.draw(m_vertices, 4, sf::Quads, states);
		}
	}
}