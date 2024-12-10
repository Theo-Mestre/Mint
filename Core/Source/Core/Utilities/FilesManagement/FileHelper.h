#ifndef CORE_FILE_HELPER_H
#define CORE_FILE_HELPER_H

#include <sys/stat.h>

namespace Core
{
	bool FileExists(const char* _path);

	void CreateNewFile(const char* _path);
}

#endif