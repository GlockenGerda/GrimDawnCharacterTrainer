#pragma once

#include "InventoryItem.h"
#include "Vector.h"
#include <cstdint>
namespace GDFR {
	class GDCFile;

	public class InventorySack
	{
	public:
		Vector<InventoryItem> items;
		uint8_t tempBool;

		void read(GDCFile *);
		void write(GDCFile *);
	};
}