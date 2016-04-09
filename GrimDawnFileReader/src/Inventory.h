#pragma once

#include "InventorySack.h"
#include "Vector.h"
#include "InventoryEquipment.h"
#include <cstdint>

class GDCFile;

class Inventory
{
public:
	Vector<InventorySack> sacks;
	InventoryEquipment equipment[12];
	InventoryEquipment weapon1[2];
	InventoryEquipment weapon2[2];
	uint32_t focused;
	uint32_t selected;
	uint8_t flag;
	uint8_t useAlternate;
	uint8_t alternate1;
	uint8_t alternate2;

	void read(GDCFile *);
	void write(GDCFile *);
};