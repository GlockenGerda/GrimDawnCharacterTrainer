#include "WString.h"
#include "GDCFile.h"
#include <stdint.h>
#include <string>

namespace GDFR {
	void WString::read(GDCFile^ gdc)
	{
		uint32_t len = gdc->read_int();

		string->clear();
		string->reserve(len);

		for (uint32_t i = 0; i < len; i++)
		{
			wchar_t c = gdc->read_byte();
			c |= gdc->read_byte() << 8;
			string->push_back(c);
		}
	}

	void WString::write(GDCFile^ gdc)
	{
		uint32_t len = string->size();
		const wchar_t *str = string->data();

		gdc->write_int(len);

		for (uint32_t i = 0; i < len; i++)
		{
			gdc->write_byte(str[i]);
			gdc->write_byte(str[i] >> 8);
		}
	}
}