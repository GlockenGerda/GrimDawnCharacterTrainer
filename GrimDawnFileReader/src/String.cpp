#include "pch.h"
#include "String.h"
#include "GDCFile.h"
#include <cstdint>

void String::read(GDCFile *gdc)
{
	uint32_t len = gdc->read_int();

	clear();
	reserve(len);

	for (uint32_t i = 0; i < len; i++)
	{
		push_back(gdc->read_byte());
	}
}

void String::write(GDCFile *gdc)
{
	size_t  len = size();
	const char *str = data();

	gdc->write_int(len);

	for (size_t i = 0; i < len; i++)
	{
		gdc->write_byte(str[i]);
	}
}