#include "Inventory.h"
#include "GDCFile.h"
#include "block.h"
#include "InventorySack.h"
#include "InventoryEquipment.h"
#include "pch.h"
#include "Vector.h"
#include <cstdint>

void Inventory::read(GDCFile *gdc)
{
	block b;

	if (gdc->read_block_start(&b) != 3)
		throw e;

	if (gdc->read_int() != 4) // version
		throw e;

	if ((flag = gdc->read_byte()))
	{
		uint32_t n = gdc->read_int();
		focused = gdc->read_int();
		selected = gdc->read_int();

		sacks.resize(n);

		for (uint32_t i = 0; i < n; i++)
		{
			sacks[i].read(gdc);
		}

		useAlternate = gdc->read_byte();

		for (unsigned i = 0; i < 12; i++)
		{
			equipment[i].read(gdc);
		}

		alternate1 = gdc->read_byte();

		for (unsigned i = 0; i < 2; i++)
		{
			weapon1[i].read(gdc);
		}

		alternate2 = gdc->read_byte();

		for (unsigned i = 0; i < 2; i++)
		{
			weapon2[i].read(gdc);
		}
	}

	gdc->read_block_end(&b);
}

void Inventory::write(GDCFile *gdc)
{
	block b;

	gdc->write_block_start(&b, 3);
	gdc->write_int(4); // version

	gdc->write_byte(flag);

	if (flag)
	{
		size_t n = sacks.size();
		gdc->write_int(n);
		gdc->write_int(focused);
		gdc->write_int(selected);

		for (size_t i = 0; i < n; i++)
		{
			sacks[i].write(gdc);
		}

		gdc->write_byte(useAlternate);

		for (unsigned i = 0; i < 12; i++)
		{
			equipment[i].write(gdc);
		}

		gdc->write_byte(alternate1);

		for (unsigned i = 0; i < 2; i++)
		{
			weapon1[i].write(gdc);
		}

		gdc->write_byte(alternate2);

		for (unsigned i = 0; i < 2; i++)
		{
			weapon2[i].write(gdc);
		}
	}

	gdc->write_block_end(&b);
}