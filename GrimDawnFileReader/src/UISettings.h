#pragma once

#include "HotSlot.h"
#include "String.h"
#include <cstdint>
namespace GDFR {
	ref class GDCFile;

	public ref class UISettings
	{
	public:
		array<HotSlot^ >^ slots = gcnew array<HotSlot^ >(36);
		array<String^ >^ unknown4 = gcnew array<String^ >(5);
		array<String^ >^ unknown5 = gcnew array<String^ >(5);
		uint32_t unknown2;
		float cameraDistance;
		array<uint8_t^ >^ unknown6 = gcnew array<uint8_t^ >(5);
		uint8_t unknown1;
		uint8_t unknown3;

		void read(GDCFile^);
		void write(GDCFile^);
	};
}