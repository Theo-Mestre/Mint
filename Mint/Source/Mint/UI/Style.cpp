#include "mintpch.h"
#include "Style.h"

#include "Mint/Utilities/FilesManagement/RAIIFile.h"
#include "Mint/Utilities/FilesManagement/FileHelper.h"

namespace Mint
{
	namespace UI
	{
		void Style::ResetResolvedBound()
		{
			ResolvedBound = Bound;
		}

		void Style::Serialize(const char* _fileName)
		{
			RAIIFile file(_fileName, std::ios::out | std::ios::binary);

			file().write(reinterpret_cast<const char*>(&PositionType), sizeof(PositionType));
			file().write(reinterpret_cast<const char*>(&Bound), sizeof(Bound));
			file().write(reinterpret_cast<const char*>(&BackgroundColor), sizeof(BackgroundColor));
		}

		void Style::Deserialize(const char* _fileName)
		{
			RAIIFile file(_fileName, std::ios::in | std::ios::binary);

			file().read(reinterpret_cast<char*>(&PositionType), sizeof(PositionType));
			file().read(reinterpret_cast<char*>(&Bound), sizeof(Bound));
			file().read(reinterpret_cast<char*>(&BackgroundColor), sizeof(BackgroundColor));

			ResetResolvedBound();
		}
	}
}