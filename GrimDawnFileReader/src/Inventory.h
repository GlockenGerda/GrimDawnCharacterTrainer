#pragma once

#include "InventorySack.h"
#include "Vector.h"
#include "InventoryEquipment.h"
#include <cstdint>
namespace GDFR {
	ref class GDCFile;

	public ref class Inventory
	{
	public:
		Vector<InventorySack^> sacks;
		array<InventoryEquipment^ >^ equipment = gcnew array<InventoryEquipment^ >(12);
		array<InventoryEquipment^ >^ weapon1 = gcnew array<InventoryEquipment^ >(2);
		array<InventoryEquipment^ >^ weapon2 = gcnew array<InventoryEquipment^ >(2);
		uint32_t focused;
		uint32_t selected;
		uint8_t flag;
		uint8_t useAlternate;
		uint8_t alternate1;
		uint8_t alternate2;

		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}