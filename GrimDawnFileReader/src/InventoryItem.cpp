#include "pch.h"
#include "InventoryItem.h"
#include "GDCFile.h"
namespace GDFR {
	void InventoryItem::read(GDCFile *gdc)
	{
		Item::read(gdc);
		x = gdc->read_int();
		y = gdc->read_int();
	}

	void InventoryItem::write(GDCFile *gdc)
	{
		Item::write(gdc);
		gdc->write_int(x);
		gdc->write_int(y);
	}
}