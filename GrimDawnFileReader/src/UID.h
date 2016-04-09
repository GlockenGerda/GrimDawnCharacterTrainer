#pragma once

#include <cstdint>
namespace GDFR {
	class GDCFile;

	public class UID
	{
	public:
		uint8_t id[16];

		void read(GDCFile *);
		void write(GDCFile *);
	};
}