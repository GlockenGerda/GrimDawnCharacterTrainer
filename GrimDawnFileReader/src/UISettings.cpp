#include "UISettings.h"
#include "block.h"
#include "GDCFile.h"
namespace GDFR {
	void UISettings::read(GDCFile *gdc)
	{
		block b;

		if (gdc->read_block_start(&b) != 14)
			throw e;

		if (gdc->read_int() != 4) // version
			throw e;

		unknown1 = gdc->read_byte();
		unknown2 = gdc->read_int();
		unknown3 = gdc->read_byte();

		for (unsigned i = 0; i < 5; i++)
		{
			unknown4[i].read(gdc);
			unknown5[i].read(gdc);
			unknown6[i] = gdc->read_byte();
		}

		for (unsigned i = 0; i < 36; i++)
		{
			slots[i].read(gdc);
		}

		cameraDistance = gdc->read_float();

		gdc->read_block_end(&b);
	}

	void UISettings::write(GDCFile *gdc)
	{
		block b;

		gdc->write_block_start(&b, 14);
		gdc->write_int(4); // version

		gdc->write_byte(unknown1);
		gdc->write_int(unknown2);
		gdc->write_byte(unknown3);

		for (unsigned i = 0; i < 5; i++)
		{
			unknown4[i].write(gdc);
			unknown5[i].write(gdc);
			gdc->write_byte(unknown6[i]);
		}

		for (unsigned i = 0; i < 36; i++)
		{
			slots[i].write(gdc);
		}

		gdc->write_float(cameraDistance);

		gdc->write_block_end(&b);
	}
}