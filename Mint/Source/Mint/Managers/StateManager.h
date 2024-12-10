#ifndef STATE_MANAGER_H
#define STATE_MANAGER_H

#include <stack>

#include "Mint/State.h"
#include "Mint/Utilities/Ref.h"

namespace Mint
{
	class State;

	class StateManager
	{
	public:
		StateManager(void);
		~StateManager(void);

		void Add(Ref<State> _toAdd, bool _replace = true);

		void PopCurrent(void);

		Ref<State> ProcessChange(void);

		Ref<State> GetCurrent(void);

	private:
		std::stack <Ref<State>> m_stateStack;
		Ref<State> m_newState;

		bool m_add;
		bool m_replace;
		bool m_remove;
	};
}
#endif