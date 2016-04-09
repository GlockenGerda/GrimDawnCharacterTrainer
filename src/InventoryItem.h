#pragma once

class InventoryItem : public Item
{
public:
	uint32_t x;
	uint32_t y;

	void read(GDCFile *);
	void write(GDCFile *);
};
