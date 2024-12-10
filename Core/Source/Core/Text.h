#ifndef CORE_TEXT_H
#define CORE_TEXT_H

#include <SFML/Graphics/Text.hpp>

#include "Core/Utilities/Ref.h"

namespace Core
{
	class Font;

	class Text
		: public sf::Text
	{
	public:
		void SetFont(const Ref<Font>& font);
		Ref<Font> GetFont() const;
	private:
		Ref<Font> m_font;
	};
}
#endif