#pragma once

#include "Item.h"
#include <cstdint>
namespace GDFR {
	ref class GDCFile;

	public ref class InventoryEquipment : public Item
	{
	public:
		uint8_t attached;

		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}