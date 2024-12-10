#ifndef CORE_MANAGER_H
#define CORE_MANAGER_H

#include <unordered_map>

#include "Mint/Logger.h"

class Manager
{
public:
	template <typename T>
	static void AddManager(T* _manager)
	{
		ASSERT(_manager == nullptr, "Manager is nullptr");

		Instance().m_managers[typeid(T).hash_code()] = _manager;
	}

	template <typename T>
	static T* GetManager()
	{
		auto& self = Instance();
		auto it = self.m_managers.find(typeid(T).hash_code());
		if (it != self.m_managers.end())
		{
			return static_cast<T*>(it->second);
		}
		return nullptr;
	}

private:
	Manager()
		: m_managers()
	{	}

	~Manager()
	{
		m_managers.clear();
	}

	static Manager& Instance()
	{
		static Manager instance;
		return instance;
	}

private:
	std::unordered_map<size_t, void*> m_managers;
};

#endif