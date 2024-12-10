#include "mintpch.h"

#include "StateManager.h"
#include "Mint/Logger.h"

namespace Mint
{
	StateManager::StateManager(void)
		: m_stateStack()
		, m_newState(nullptr)
		, m_add(false)
		, m_replace(false)
		, m_remove(false)
	{}

	StateManager::~StateManager(void)
	{
		while (!m_stateStack.empty())
		{
			m_stateStack.top()->Unload();
			m_stateStack.pop();
		}
	}

	void StateManager::Add(Ref<State> _toAdd, bool _replace)
	{
		m_add = true;
		m_newState = std::move(_toAdd);
		m_replace = _replace;
	}

	void StateManager::PopCurrent(void)
	{
		m_remove = true;
	}

	Ref<State> StateManager::ProcessChange(void)
	{
		if (m_remove == true && !m_stateStack.empty())
		{
			m_stateStack.top()->Unload();
			m_stateStack.pop();

			if (!m_stateStack.empty())
			{
				m_stateStack.top()->Load();
			}
			m_remove = false;
		}

		if (m_add == true)
		{
			if (m_replace == true && !m_stateStack.empty())
			{
				m_stateStack.top()->Unload();
				m_stateStack.pop();
			}

			if (!m_stateStack.empty())
			{
				m_stateStack.top()->Stop();
			}
			m_stateStack.push(std::move(m_newState));

			m_stateStack.top()->Load();
			m_stateStack.top()->Start();

			m_add = false;
			m_replace = false;
		}
		return GetCurrent();
	}

	Ref<State> StateManager::GetCurrent(void)
	{
		Ref<State> currentState = m_stateStack.top();
		ASSERT(currentState == nullptr, "No state in the stack");
		return currentState;
	}
}