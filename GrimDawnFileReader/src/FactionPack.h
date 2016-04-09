#pragma once
#include <cstdint>
#include "FactionData.h"
#include "Vector.h"
namespace GDFR {
	ref class GDCFile;

	public ref class FactionPack
	{
	public:
		Vector<FactionData>^ factions;
		uint32_t faction;

		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}