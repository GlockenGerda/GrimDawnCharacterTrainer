#include "GDString.h"
#include "GDCFile.h"
#include <cstdint>
using namespace System;
namespace GDFR {
	void GDString::read(GDCFile ^gdc)
	{
		uint32_t len = gdc->read_int();

		s = gcnew String("");

		for (uint32_t i = 0; i < len; i++)
		{
			uint8_t byte = gdc->read_byte();
			s->Insert(s->Length, byte);
		}
	}

	void GDString::write(GDCFile ^gdc)
	{
		size_t  len = s->Length;
		const char *str = s->data();

		gdc->write_int(len);

		for (size_t i = 0; i < len; i++)
		{
			gdc->write_byte(str[i]);
		}
	}
}