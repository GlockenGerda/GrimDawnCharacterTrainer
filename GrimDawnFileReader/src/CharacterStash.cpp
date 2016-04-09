#include "pch.h"
#include "CharacterStash.h"
#include "GDCFile.h"
#include "block.h"

void CharacterStash::read(GDCFile *gdc)
{
	block b;

	if (gdc->read_block_start(&b) != 4)
		throw e;

	if (gdc->read_int() != 5) // version
		throw e;

	width = gdc->read_int();
	height = gdc->read_int();
	items.read(gdc);

	gdc->read_block_end(&b);
}

void CharacterStash::write(GDCFile *gdc)
{
	block b;

	gdc->write_block_start(&b, 4);
	gdc->write_int(5); // version

	gdc->write_int(width);
	gdc->write_int(height);
	items.write(gdc);

	gdc->write_block_end(&b);
}