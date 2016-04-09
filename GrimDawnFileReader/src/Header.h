#pragma once
#include "WString.h"
#include "String.h"
#include "GDCFile.h"

namespace GDFR {
	ref class GDCFile;
	public ref class Header
	{
	public:
		WString name;
		String tag;
		uint32_t level;
		uint8_t sex;
		uint8_t hardcore;

		void read(GDCFile^);
		void write(GDCFile^);
	};
}
