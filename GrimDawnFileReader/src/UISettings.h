#pragma once

#include "HotSlot.h"
#include "String.h"
#include <cstdint>
namespace GDFR {
	class GDCFile;

	public class UISettings
	{
	public:
		HotSlot slots[36];
		String unknown4[5];
		String unknown5[5];
		uint32_t unknown2;
		float cameraDistance;
		uint8_t unknown6[5];
		uint8_t unknown1;
		uint8_t unknown3;

		void read(GDCFile *);
		void write(GDCFile *);
	};
}