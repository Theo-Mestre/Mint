#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <SFML/Graphics/Vertex.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "Animation.h"
#include "Core/Utilities/Timer.h"

namespace Core
{
	using AnimationList = std::vector<Animation>;

	class Sprite
		: public sf::Drawable
		, public sf::Transformable
	{
	public:

		Sprite();
		Sprite(const Animation& _animation);
		~Sprite();

		/**
		 * \brief Initialize the sprite from an animation.
		 * \param _animation : the animation to emplace.
		 */
		void Init(const Animation& _animation);

		/**
		 * \brief Initialize the sprite from stored Animation.
		 *  if no animation is stored, the sprite is not initialized.
		 * \return true if the sprite is initialized, false otherwise.
		 */
		bool Init();

		/**\brief Update the current animation and manage timer.*/
		void Update();

		/**\brief Change the current animation.*/
		void SetCurrentAnimation(size_t index);
		/**\brief Return the animation currently playing.*/
		Animation& GetCurrentAnimation(void);

		/**\brief Set the current animation's frame.*/
		void SetCurrentFrame(size_t _frame, bool _resetTime = false);
		/**\brief Return the ID of the current animation's frame.*/
		size_t GetCurrentFrame(void) const;

		/**\brief Start the animation.*/
		void Play();
		/**\brief Add an animation to the list and play it.*/
		void Play(const Animation& animation);
		/**\brief Pause the animation.*/
		void Pause();
		/**\brief Stop the animation.*/
		void Stop();
		/**\brief Make the animation loop*/
		void SetLoop(bool _loop);

		/**\brief Add an animation to the list ans return its index.*/
		size_t AddAnimation(const Animation& _animation);

		/**\brief Return if the animation is currently playing.*/
		bool IsPlaying(void) const;
		/**\brief Return if the animation loops.*/
		bool IsLooping(void) const;

		/**\brief Set the time between two frames*/
		void SetFrameTime(float _time);
		/**\brief Return the time value between two frames*/
		float GetFrameTime(void) const;

		/**\brief Set the  current frame index to 0.*/
		void ResetAnimationProgression(void);

		/**\brief Change the color of the sprite*/
		void SetColor(const sf::Color& color);
		/**\brief Return the local boundings of the sprite*/
		sf::FloatRect GetLocalBounds(void) const;
		/**\brief Return the global boundings of the sprite*/
		sf::FloatRect GetGlobalBounds(void) const;

		/**\brief Set the direction of the animation*/
		void SetDirection(AnimDirection _direction);
		/**\brief Return the direction of the animation*/
		AnimDirection GetDirection(void) const;

	private:
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	private:
		AnimationList m_animations;
		Timer m_timer;

		size_t m_currentAnimationIndex;
		size_t m_currentFrameIndex;

		Ref<Texture2D> m_texture;
		sf::Vertex m_vertices[4];

		bool m_isPaused;
		bool m_doesLoop;

		AnimDirection m_direction;
	};
}
#endif