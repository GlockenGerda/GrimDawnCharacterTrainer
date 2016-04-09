#include "pch.h"
#include "FactionPack.h"
#include "GDCFile.h"
#include "block.h"
namespace GDFR {
	void FactionPack::read(GDCFile ^gdc)
	{
		block^ b;

		if (gdc->read_block_start(b) != 13)
			throw e;

		if (gdc->read_int() != 5) // version
			throw e;

		faction = gdc->read_int();
		factions.read(gdc);

		gdc->read_block_end(b);
	}

	void FactionPack::write(GDCFile ^gdc)
	{
		block^ b;

		gdc->write_block_start(b, 13);
		gdc->write_int(5); // version

		gdc->write_int(faction);
		factions.write(gdc);

		gdc->write_block_end(b);
	}
}