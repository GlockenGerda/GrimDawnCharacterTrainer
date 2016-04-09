#include "pch.h"
#include "GDCFile.h"
#include "HotSlot.h"
namespace GDFR {
	void HotSlot::read(GDCFile ^gdc)
	{
		type = gdc->read_int();

		if (type == 0)
		{
			skill.read(gdc);
			isItemSkill = gdc->read_byte();
			item.read(gdc);
			equipLocation = gdc->read_int();
		}
		else if (type == 4)
		{
			item.read(gdc);
			bitmapUp.read(gdc);
			bitmapDown.read(gdc);
			label.read(gdc);
		}
	}

	void HotSlot::write(GDCFile ^gdc)
	{
		gdc->write_int(type);

		if (type == 0)
		{
			skill.write(gdc);
			gdc->write_byte(isItemSkill);
			item.write(gdc);
			gdc->write_int(equipLocation);
		}
		else if (type == 4)
		{
			item.write(gdc);
			bitmapUp.write(gdc);
			bitmapDown.write(gdc);
			label.write(gdc);
		}
	}
}