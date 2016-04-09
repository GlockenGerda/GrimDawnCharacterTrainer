#pragma once
#include "Item.h"
#include <cstdint>
namespace GDFR {
	class GDCFile;

	public class InventoryItem : public Item
	{
	public:
		uint32_t x;
		uint32_t y;

		void read(GDCFile *);
		void write(GDCFile *);
	};
}
