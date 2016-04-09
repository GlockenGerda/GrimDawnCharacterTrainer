#pragma once
#include "Item.h"
#include <cstdint>
class GDCFile;

class InventoryItem : public Item
{
public:
	uint32_t x;
	uint32_t y;

	void read(GDCFile *);
	void write(GDCFile *);
};
