#include "pch.h"
#include "LoreNotes.h"
#include "GDCFile.h"
#include "block.h"

void LoreNotes::read(GDCFile *gdc)
{
	block b;

	if (gdc->read_block_start(&b) != 12)
		throw e;

	if (gdc->read_int() != 1) // version
		throw e;

	names.read(gdc);

	gdc->read_block_end(&b);
}

void LoreNotes::write(GDCFile *gdc)
{
	block b;

	gdc->write_block_start(&b, 12);
	gdc->write_int(1); // version

	names.write(gdc);

	gdc->write_block_end(&b);
}