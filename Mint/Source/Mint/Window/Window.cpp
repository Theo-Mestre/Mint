#include "mintpch.h"
#include "Window.h"
#include "Mint/Utilities/FilesManagement/RAIIFile.h"
#include "Mint/Utilities/Serializable.h"

#define WriteToFile(file, data) file().write(reinterpret_cast<char*>(&data), sizeof(data))
#define ReadFromFile(file, data) file().read(reinterpret_cast<char*>(&data), sizeof(data))

class WindowConfigData
	: public Mint::Serializable
{
public:
	WindowConfigData() = default;

	virtual void Serialize(const char* _fileName) override
	{
		RAIIFile m_file = RAIIFile(_fileName, std::ios::out | std::ios::binary);

		WriteToFile(m_file, TitleLenght);
		m_file().write(Title.c_str(), Title.size());
		WriteToFile(m_file, Width);
		WriteToFile(m_file, Height);
		WriteToFile(m_file, Style);
		WriteToFile(m_file, FramerateLimit);
		WriteToFile(m_file, VSync);
	}

	virtual void Deserialize(const char* _fileName) override
	{
		RAIIFile m_file = RAIIFile(_fileName, std::ios::in | std::ios::binary);

		ReadFromFile(m_file, TitleLenght);
		Title.resize(TitleLenght + 1);
		m_file().read(&Title[0], TitleLenght);
		ReadFromFile(m_file, Width);
		ReadFromFile(m_file, Height);
		ReadFromFile(m_file, Style);
		ReadFromFile(m_file, FramerateLimit);
		ReadFromFile(m_file, VSync);
	}

public:
	size_t TitleLenght = 0;
	std::string Title;
	uint32_t Width = 0;
	uint32_t Height = 0;
	uint32_t Style = 0;
	uint32_t FramerateLimit = 0;
	bool VSync = false;
};

Window::Window()
	: m_window()
{
}

Window::Window(const char* _configFileName)
	: m_window()
{
	Create(_configFileName);
}

Window::~Window()
{
	if (m_window.isOpen())
	{
		m_window.close();
	}
}

void Window::Create(const char* _configFileName)
{
	WindowConfigData data;

	data.Deserialize(_configFileName);

	sf::VideoMode videoMode(data.Width, data.Height);
	m_window.create(videoMode, data.Title, data.Style);
	m_window.setFramerateLimit(data.FramerateLimit);
	m_window.setVerticalSyncEnabled(data.VSync);
}