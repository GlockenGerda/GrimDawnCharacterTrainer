#include "InventoryEquipment.h"
#include "GDCFile.h"
#include "Item.h"
#include "pch.h"
namespace GDFR {
	void InventoryEquipment::read(GDCFile *gdc)
	{
		Item::read(gdc);
		attached = gdc->read_byte();
	}

	void InventoryEquipment::write(GDCFile *gdc)
	{
		Item::write(gdc);
		gdc->write_byte(attached);
	}
}