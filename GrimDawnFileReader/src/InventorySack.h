#pragma once

#include "InventoryItem.h"

class InventorySack
{
public:
	Vector<InventoryItem> items;
	uint8_t tempBool;

	void read(GDCFile *);
	void write(GDCFile *);
};