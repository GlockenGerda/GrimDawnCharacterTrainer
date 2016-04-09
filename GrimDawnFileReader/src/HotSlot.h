#pragma once
#include "WString.h"
#include "String.h"
namespace GDFR {
	class GDCFile;

	public class HotSlot
	{
	public:
		String skill;
		String item;
		String bitmapUp;
		String bitmapDown;
		WString label;
		uint32_t type;
		uint32_t equipLocation;
		uint8_t isItemSkill;

		void read(GDCFile *);
		void write(GDCFile *);
	};
}