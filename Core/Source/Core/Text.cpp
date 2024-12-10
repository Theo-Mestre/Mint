#include "corepch.h"

#include "Text.h"
#include "Core/AssetManagment/Assets.h"

namespace Core
{
	void Text::SetFont(const Ref<Font>& font)
	{
		m_font = font;
		setFont(font->Get());
	}

	Ref<Font> Text::GetFont() const
	{
		return m_font;
	}
}