#include "corepch.h"
#include "Assets.h"
#include "Core/Utilities/FilesManagement/FileHelper.h"

namespace Core
{
#pragma region Texture2D
	Texture2D::Texture2D()
	{
		m_loaded = false;
	}

	Texture2D::~Texture2D()
	{
		if (m_loaded)
		{
			Unload();
		}
	}

	void Texture2D::Load(const char* _assetName)
	{
		if (FileExists(_assetName) == false)
		{
			ASSERT("Failed to load texture: {} - File not found", _assetName);
		}

		if (m_texture.loadFromFile(_assetName) == false)
		{
			LogError("Failed to load texture: {}", _assetName);
			return;
		}

		m_loaded = true;
	}

	void Texture2D::Unload()
	{
		if (m_loaded == false) return;
		m_loaded = false;
	}
#pragma endregion

#pragma region Shader
	Shader::Shader()
	{
	}
	Shader::~Shader()
	{
	}
	void Shader::Load(const char* _assetName)
	{
	}
	void Shader::Unload()
	{
	}
#pragma endregion

#pragma region Font
	Font::Font()
	{
		m_loaded = false;
	}
	Font::~Font()
	{
		if (m_loaded)
		{
			Unload();
		}
	}
	void Font::Load(const char* _assetName)
	{
		if (FileExists(_assetName) == false)
		{
			ASSERT("Failed to load font: {} - File not found", _assetName);
		}

		if (m_font.loadFromFile(_assetName) == false)
		{
			LogError("Failed to load font: {}", _assetName);
			return;
		}

		m_loaded = true;
	}
	void Font::Unload()
	{
		if (m_loaded == false) return;
		m_loaded = false;
	}
#pragma endregion
}