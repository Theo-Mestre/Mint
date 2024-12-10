#ifndef CORE_SERIALIZABLE_H
#define CORE_SERIALIZABLE_H

namespace Mint
{
	class Serializable
	{
	public:
		virtual void Serialize(const char* _fileName) = 0;
		virtual void Deserialize(const char* _fileName) = 0;
	};
}
#endif