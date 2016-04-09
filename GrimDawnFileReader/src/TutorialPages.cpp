#include "TutorialPages.h"
#include "GDCFile.h"
#include "block.h"

namespace GDFR {
	void TutorialPages::read(GDCFile ^gdc)
	{
		block^ b;

		if (gdc->read_block_start(b) != 15)
			throw e;

		if (gdc->read_int() != 1) // version
			throw e;

		uint32_t n = gdc->read_int();
		pages->vector = gcnew array<size_t>(n);

		for (uint32_t i = 0; i < n; i++)
		{
			pages->vector[i] = gdc->read_int();
		}

		gdc->read_block_end(b);
	}

	void TutorialPages::write(GDCFile ^gdc)
	{
		block^ b;

		gdc->write_block_start(b, 15);
		gdc->write_int(1); // version

		size_t  n = pages->vector->Length;
		gdc->write_int(n);

		for (size_t i = 0; i < n; i++)
		{
			gdc->write_int(pages->vector[i]);
		}

		gdc->write_block_end(b);
	}
}