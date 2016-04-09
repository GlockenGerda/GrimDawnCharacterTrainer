#pragma once

#include "InventoryItem.h"
#include "Vector.h"
#include <cstdint>

class GDCFile;

class InventorySack
{
public:
	Vector<InventoryItem> items;
	uint8_t tempBool;

	void read(GDCFile *);
	void write(GDCFile *);
};