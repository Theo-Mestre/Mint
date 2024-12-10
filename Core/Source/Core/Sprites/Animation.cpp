#include "corepch.h"
#include "Animation.h"
#include "Core/AssetManagment/Assets.h"

namespace Core
{
	Animation::Animation()
		: m_texture(nullptr)
		, m_frames()
		, m_frameTime(0.0f)
	{ }

	Animation::Animation(const Animation::Data& _data)
	{
		SetSpriteSheet(_data.texture);
		SetFrameTime(_data.frameTime);

		for (short i = 0; i < _data.frameNumber; ++i)
		{
			AddFrame(sf::IntRect(i * _data.frameWidth, _data.frameY, _data.frameWidth, _data.frameHeight));
		}
	}

	Animation::Animation(Ref<Texture2D> _texture)
	{
		SetSpriteSheet(_texture);
		AddFrame(sf::IntRect(0, 0, _texture->Get().getSize().x, _texture->Get().getSize().y));
		SetFrameTime(1.0f);
	}

	Animation::~Animation()
	{
		m_texture = nullptr;
		m_frames.clear();
	}

	void Animation::SetSpriteSheet(Ref<Texture2D> texture)
	{
		m_texture = texture;
	}

	Ref<Texture2D> Animation::GetSpriteSheet(void) const
	{
		return m_texture;
	}

	void Animation::AddFrame(sf::IntRect _rect)
	{
		m_frames.push_back(_rect);
	}

	size_t Animation::GetFrameNumber(void) const
	{
		return m_frames.size();
	}

	sf::IntRect Animation::GetFrame(size_t _frameNumber) const
	{
		return m_frames.at(_frameNumber);
	}

	FramesList& Animation::GetFramesList(void)
	{
		return m_frames;
	}

	void Animation::SetFrameTime(float _frameTime)
	{
		m_frameTime = _frameTime;
	}

	float Animation::GetFrameTime(void) const
	{
		return m_frameTime;
	}

	bool Animation::IsCreated(void) const
	{
		return m_texture != nullptr && m_frames.empty() == false;
	}
}