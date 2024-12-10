#ifndef CORE_ASSETS_H
#define CORE_ASSETS_H

#include<SFML/Graphics/Texture.hpp>
#include<SFML/Graphics/Shader.hpp>
#include<SFML/Graphics/Font.hpp>

#pragma region Asset
namespace Mint
{
	class Asset
	{
	public:
		enum class Type
		{
			Texture2D,
			Shader,
			Font,

			Count
		};

	public:
		Asset() = default;
		virtual ~Asset() = default;

		virtual void Load(const char* _assetName) = 0;
		virtual void Unload() = 0;
		inline bool IsLoaded() const { return m_loaded; }

		virtual Type GetType() const = 0;
		inline const std::string& GetName() const { return m_name; }

	protected:
		bool m_loaded = false;
		std::string m_name;
	};
#pragma endregion

#pragma region Texture2D
	class Texture2D
		: public Asset
	{
	public:
		Texture2D();
		~Texture2D();

		void Load(const char* _assetName) override;
		void Unload() override;

		virtual Type GetType() const override { return Asset::Type::Texture2D; }

		operator sf::Texture& () { return m_texture; }
		sf::Texture& Get() { return m_texture; }

	private:
		sf::Texture m_texture;
	};
#pragma endregion

#pragma region Shader
	class Shader
		: public Asset
	{
	public:
		Shader();
		~Shader();

		void Load(const char* _assetName) override;
		void Unload() override;

		virtual Type GetType() const override { return Asset::Type::Shader; }

		operator sf::Shader& () { return m_shader; }
		sf::Shader& Get() { return m_shader; }

	private:
		sf::Shader m_shader;
	};


#pragma endregion

#pragma region Font
	class Font
		: public Asset
	{
	public:
		Font();
		~Font();

		void Load(const char* _assetName) override;
		void Unload() override;

		virtual Type GetType() const override { return Asset::Type::Font; }

		operator sf::Font& () { return m_font; }
		sf::Font& Get() { return m_font; }

	private:
		sf::Font m_font;
	};

#pragma endregion

}
#endif