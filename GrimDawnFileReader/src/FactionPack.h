#pragma once
#include <cstdint>
#include "FactionData.h"
#include "Vector.h"
namespace GDFR {
	class GDCFile;

	public class FactionPack
	{
	public:
		Vector<FactionData> factions;
		uint32_t faction;

		void read(GDCFile *);
		void write(GDCFile *);
	};
}