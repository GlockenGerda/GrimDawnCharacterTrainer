#pragma once

#include <cstdint>
namespace GDFR {
	ref class GDCFile;

	public ref class UID
	{
	public:
		array<uint8_t>^ id = gcnew array<uint8_t>(16);

		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}