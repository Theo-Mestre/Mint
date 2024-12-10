#ifndef CORE_STATE_H
#define CORE_STATE_H

#include "Core/Utilities/Ref.h"

namespace Core
{
	using Event = sf::Event;

	class Renderer;

	class State
	{
	public:
		State(void) = default;
		virtual ~State(void) = default;

		virtual void Load(void) = 0;
		virtual void EarlyUpdate(void) {};
		virtual void OnEventReceived(const Event& _event) {};
		virtual void Update(void) = 0;
		virtual void LateUpdate(void) {};
		virtual void Render(Ref<Renderer> _renderer) = 0;
		virtual void Unload(void) = 0;
		virtual void Start(void) {};
		virtual void Stop(void) {};
	};
}
#endif