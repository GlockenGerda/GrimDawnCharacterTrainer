#pragma once
#include <cstdint>
#include "String.h"

namespace GDFR {
	ref class GDCFile;

	public ref class CharacterInfo
	{
	public:
		CharacterInfo();
	private:
		String texture;
		uint32_t money;
		uint32_t lootMode;
		uint8_t isInMainQuest;
		uint8_t hasBeenInGame;
		uint8_t difficulty;
		uint8_t greatestDifficulty;
		uint8_t compassState;
		uint8_t skillWindowShowHelp;
		uint8_t alternateConfig;
		uint8_t alternateConfigEnabled;
	public:
		void read(GDCFile^);
		void write(GDCFile^);
	};
}
