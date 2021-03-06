#pragma once

#include "String.h"

#include <cstdint>
namespace GDFR {
	ref class GDCFile;

	public ref class Skill
	{
	public:
		String name;
		String autoCastSkill;
		String autoCastController;
		uint32_t level;
		uint32_t devotionLevel;
		uint32_t experience;
		uint32_t active;
		uint8_t enabled;
		uint8_t unknown1;
		uint8_t unknown2;

		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}