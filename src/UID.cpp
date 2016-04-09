#include "UID.h"
#include "GDCFile.h"
#include "pch.h"
#include <stdint.h>

void UID::read(GDCFile *gdc)
{
	for (unsigned i = 0; i < 16; i++)
	{
		id[i] = gdc->read_byte();
	}
}

void UID::write(GDCFile *gdc)
{
	for (unsigned i = 0; i < 16; i++)
	{
		gdc->write_byte(id[i]);
	}
}