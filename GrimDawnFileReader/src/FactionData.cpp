#include "FactionData.h"
#include "GDCFile.h"

void FactionData::read(GDCFile *gdc)
{
	modified = gdc->read_byte();
	unlocked = gdc->read_byte();
	value = gdc->read_float();
	positiveBoost = gdc->read_float();
	negativeBoost = gdc->read_float();
}

void FactionData::write(GDCFile *gdc)
{
	gdc->write_byte(modified);
	gdc->write_byte(unlocked);
	gdc->write_float(value);
	gdc->write_float(positiveBoost);
	gdc->write_float(negativeBoost);
}