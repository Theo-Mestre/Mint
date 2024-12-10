#include "mintpch.h"
#include "FileHelper.h"

namespace Mint
{
	bool FileExists(const char* _path)
	{
		struct stat buffer;
		return (stat(_path, &buffer) == 0);
	}

	void CreateNewFile(const char* _path)
	{
		std::ofstream file(_path);
		if (file.is_open() == false)
		{
			ASSERT(false, "Failed to create file: {}", _path);
		}
		file.close();
	}
}