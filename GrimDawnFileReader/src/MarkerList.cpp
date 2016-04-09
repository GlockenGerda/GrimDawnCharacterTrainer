#include "pch.h"
#include "MarkerList.h"
#include "GDCFile.h"
#include "block.h"
namespace GDFR {
	void MarkerList::read(GDCFile ^gdc)
	{
		block^ b;

		if (gdc->read_block_start(b) != 7)
			throw e;

		if (gdc->read_int() != 1) // version
			throw e;

		for (unsigned i = 0; i < 3; i++)
		{
			uids[i]->read(gdc);
		}

		gdc->read_block_end(b);
	}

	void MarkerList::write(GDCFile ^gdc)
	{
		block^ b;

		gdc->write_block_start(b, 7);
		gdc->write_int(1); // version

		for (unsigned i = 0; i < 3; i++)
		{
			uids[i]->write(gdc);
		}

		gdc->write_block_end(b);
	}
}