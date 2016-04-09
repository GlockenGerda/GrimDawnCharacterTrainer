#include "pch.h"
#include "StashItem.h"
#include "GDCFile.h"
namespace GDFR {
	void StashItem::read(GDCFile ^gdc)
	{
		Item::read(gdc);
		x = gdc->read_float();
		y = gdc->read_float();
	}

	void StashItem::write(GDCFile ^gdc)
	{
		Item::write(gdc);
		gdc->write_float(x);
		gdc->write_float(y);
	}
}