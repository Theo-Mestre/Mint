#ifndef CORE_UI_STYLE_H
#define CORE_UI_STYLE_H

#include "Core/UI/UIGeometry.h"
#include "Core/Utilities/Serializable.h"

namespace Core
{
	namespace UI
	{
		using Color = sf::Color;

		enum class PositionType
		{
			Relative,
			Absolute
		};

		struct Style
			: public Serializable
		{
		public:
			PositionType PositionType = PositionType::Relative;

			// Original bound
			Rect Bound;

			// Resolved bound (after layout computation)
			Rect ResolvedBound;

			// Background color
			Color BackgroundColor = Color::Transparent;

			void ResetResolvedBound();

			void Serialize(const char* _fileName) override;

			void Deserialize(const char* _fileName) override;
		};
	}
}
#endif