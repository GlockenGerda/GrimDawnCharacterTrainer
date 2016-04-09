#include "TutorialPages.h"
#include "GDCFile.h"
#include "block.h"

namespace GDFR {
	void TutorialPages::read(GDCFile *gdc)
	{
		block b;

		if (gdc->read_block_start(&b) != 15)
			throw e;

		if (gdc->read_int() != 1) // version
			throw e;

		uint32_t n = gdc->read_int();
		pages.vector->resize(n);

		for (uint32_t i = 0; i < n; i++)
		{
			pages.vector->at(i) = gdc->read_int();
		}

		gdc->read_block_end(&b);
	}

	void TutorialPages::write(GDCFile *gdc)
	{
		block b;

		gdc->write_block_start(&b, 15);
		gdc->write_int(1); // version

		size_t  n = pages.vector->size();
		gdc->write_int(n);

		for (size_t i = 0; i < n; i++)
		{
			gdc->write_int(pages.vector->at(i));
		}

		gdc->write_block_end(&b);
	}
}