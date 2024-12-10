#ifndef CORE_OBJECT_POOL_H
#define CORE_OBJECT_POOL_H

#include <unordered_map>
#include <typeinfo>
#include <vector>

namespace Mint
{
	class ObjectPool
	{
	public:
		ObjectPool() = default;
		~ObjectPool()
		{
			for (auto& object : m_objects)
			{
				for (auto& obj : object.second)
				{
					delete obj;
					obj = nullptr;
				}
				object.second.clear();
			}
			m_objects.clear();
		}

		template <typename T>
		T* AddObject(T&& _object)
		{
			auto& type = typeid(T);
			if (m_objects.find(type) == m_objects.end())
			{
				m_objects[type] = std::vector<void*>();
			}

			m_objects[type].emplace_back(_object));
		}

		template <typename T>
		void RemoveObject(T* _object)
		{
			auto& type = typeid(T);
			if (m_objects.find(type) == m_objects.end())
			{
				return;
			}

			auto& objects = m_objects[type];
			auto it = std::find(objects.begin(), objects.end(), _object);
			if (it != objects.end())
			{
				objects.erase(it);
			}
		}

		template <typename T>
		T* GetObject(size_t _id)
		{
			auto& type = typeid(T);
			if (m_objects.find(type) == m_objects.end())
			{
				return nullptr;
			}

			return static_cast<T*>(m_objects[type].front());
		}

		template <typename T>
		std::vector<T*> GetObjects()
		{
			auto& type = typeid(T);
			if (m_objects.find(type) == m_objects.end())
			{
				return std::vector<T*>();
			}

			return static_cast<std::vector<T*>>(m_objects[type]);
		}

	private:
		std::unordered_map<std::type_info, std::vector<void*>> m_objects;
	};
}

#endif