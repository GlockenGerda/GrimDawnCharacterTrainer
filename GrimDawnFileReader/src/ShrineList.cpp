#include "pch.h"
#include "ShrineList.h"
#include "block.h"
#include "GDCFile.h"

void ShrineList::read(GDCFile *gdc)
{
	block b;

	if (gdc->read_block_start(&b) != 17)
		throw e;

	if (gdc->read_int() != 2) // version
		throw e;

	for (unsigned i = 0; i < 6; i++)
	{
		uids[i].read(gdc);
	}

	gdc->read_block_end(&b);
}

void ShrineList::write(GDCFile *gdc)
{
	block b;

	gdc->write_block_start(&b, 17);
	gdc->write_int(2); // version

	for (unsigned i = 0; i < 6; i++)
	{
		uids[i].write(gdc);
	}

	gdc->write_block_end(&b);
}