#include "mintpch.h"

#include "Text.h"
#include "Mint/AssetManagment/Assets.h"

namespace Mint
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