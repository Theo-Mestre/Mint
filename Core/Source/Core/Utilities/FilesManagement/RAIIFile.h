#ifndef RAII_FILE_H
#define RAII_FILE_H

#include <fstream>

class RAIIFile
{
public:
	RAIIFile(const char* _filename, std::ios_base::openmode _mode);
	virtual ~RAIIFile();

	inline std::fstream& operator()() { return m_file; }
protected:
	std::fstream m_file;
};

#endif