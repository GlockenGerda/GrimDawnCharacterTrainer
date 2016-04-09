#pragma once

#include "Item.h"
#include <cstdint>
class GDCFile;

class InventoryEquipment : public Item
{
public:
	uint8_t attached;

	void read(GDCFile *);
	void write(GDCFile *);
};