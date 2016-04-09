#pragma once

class InventoryEquipment : public Item
{
public:
	uint8_t attached;

	void read(GDCFile *);
	void write(GDCFile *);
};