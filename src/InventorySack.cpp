#include "pch.h"
#include "InventorySack.h"
#include "Vector.h"
#include "Item.h"
#include "GDCFile.h"
#include "block.h"

#include <cstdint>

void InventorySack::read(GDCFile *gdc)
{
	block b;

	if (gdc->read_block_start(&b))
		throw e;

	tempBool = gdc->read_byte();
	items.read(gdc);

	gdc->read_block_end(&b);
}

void InventorySack::write(GDCFile *gdc)
{
	block b;

	gdc->write_block_start(&b, 0);

	gdc->write_byte(tempBool);
	items.write(gdc);

	gdc->write_block_end(&b);
}