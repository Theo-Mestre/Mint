#include "mintpch.h"
#include "RAIIFile.h"
#include "FileHelper.h"

RAIIFile::RAIIFile(const char* _filename, std::ios_base::openmode _mode)
	: m_file(_filename, _mode)
{
	if (m_file.is_open() == false && 
		(_mode & std::ios::out) == std::ios::out)
	{
		Mint::CreateNewFile(_filename);
		m_file.open(_filename, _mode);
	}

	ASSERT(m_file.is_open() == false, "Failed to open file: {}", _filename);
}

RAIIFile::~RAIIFile()
{
	if (m_file.is_open())
	{
		m_file.close();
	}
}
