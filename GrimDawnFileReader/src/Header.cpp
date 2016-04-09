#include "pch.h"
#include "Header.h"
#include "GDCFile.h"
namespace GDFR {
	void Header::read(GDCFile^ gdc)
	{
		name.read(gdc);
		sex = gdc->read_byte();
		tag.read(gdc);
		level = gdc->read_int();
		hardcore = gdc->read_byte();
	}

	void Header::write(GDCFile^ gdc)
	{
		name.write(gdc);
		gdc->write_byte(sex);
		tag.write(gdc);
		gdc->write_int(level);
		gdc->write_byte(hardcore);
	}
}