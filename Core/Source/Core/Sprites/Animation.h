#ifndef ANIMATION_H
#define ANIMATION_H
//#pragma warning(disable:4275)
//#pragma warning(disable:4251)

#include <vector>
#include <SFML/Graphics/Rect.hpp>

#include "Core/Utilities/Ref.h"

namespace Core
{
	class Texture2D;

	using FramesList = std::vector<sf::IntRect>;

	enum class AnimDirection
	{
		Forward,
		Backward
	};

	/**
	 * \brief Container that regroup the textures rect and the spritesheet of an animations.
	 */
	class Animation
	{
	public:
		struct Data
		{
			Ref<Texture2D> texture = nullptr;
			short frameNumber = 0;
			short frameY = 0;
			short frameWidth = 0;
			short frameHeight = 0;
			float frameTime = 0.0f;
		};

	public:
		Animation();
		Animation(const Animation::Data& _data);
		Animation(Ref<Texture2D> _texture);
		~Animation();

		/**\brief Assign a spritesheet to the animation*/
		void SetSpriteSheet(Ref<Texture2D> _texture);
		/**\brief Return the animation' spritesheet*/
		Ref<Texture2D> GetSpriteSheet(void) const;

		/**\brief Add a new frame to the frame list*/
		void AddFrame(sf::IntRect _rect);

		/**\brief Return the number of frames*/
		size_t GetFrameNumber(void) const;

		/**\brief Return the frame texture rect at the given index*/
		sf::IntRect GetFrame(size_t _frameNumber) const;
		/**\brief Return the frame list*/
		FramesList& GetFramesList(void);

		/**\brief Set the time between each frame*/
		void SetFrameTime(float _frameTime);
		/**\brief Return the time between each frame*/
		float GetFrameTime(void) const;

		/**\brief Return if the animation gots a texture and at least a frame*/
		bool IsCreated(void) const;
	private:
		FramesList m_frames;
		Ref<Texture2D> m_texture;
		float m_frameTime;
	};
}
#endif