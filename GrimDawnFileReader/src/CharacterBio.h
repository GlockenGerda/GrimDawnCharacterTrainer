#pragma once
#include <cstdint>
namespace GDFR {
	ref class GDCFile;

	public ref class CharacterBio
	{
	public:
		uint32_t level;
		uint32_t experience;
		uint32_t modifierPoints;
		uint32_t skillPoints;
		uint32_t devotionPoints;
		uint32_t totalDevotion;
		float physique;
		float cunning;
		float spirit;
		float health;
		float energy;

		void read(GDCFile^);
		void write(GDCFile^);
	};
}