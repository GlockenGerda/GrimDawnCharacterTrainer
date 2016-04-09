#include "pch.h"
#include "UID.h"
#include "GDCFile.h"
#include <stdint.h>
namespace GDFR {
	void UID::read(GDCFile ^gdc)
	{
		for (unsigned i = 0; i < 16; i++)
		{
			id[i] = gdc->read_byte();
		}
	}

	void UID::write(GDCFile ^gdc)
	{
		for (unsigned i = 0; i < 16; i++)
		{
			gdc->write_byte(id[i]);
		}
	}
}