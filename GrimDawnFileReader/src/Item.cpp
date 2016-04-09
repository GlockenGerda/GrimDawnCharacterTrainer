#include "pch.h"
#include "Item.h"
#include "GDCFile.h"

void Item::read(GDCFile *gdc)
{
	baseName.read(gdc);
	prefixName.read(gdc);
	suffixName.read(gdc);
	modifierName.read(gdc);
	transmuteName.read(gdc);
	seed = gdc->read_int();
	relicName.read(gdc);
	relicBonus.read(gdc);
	relicSeed = gdc->read_int();
	augmentName.read(gdc);
	unknown = gdc->read_int();
	augmentSeed = gdc->read_int();
	var1 = gdc->read_int();
	stackCount = gdc->read_int();
}

void Item::write(GDCFile *gdc)
{
	baseName.write(gdc);
	prefixName.write(gdc);
	suffixName.write(gdc);
	modifierName.write(gdc);
	transmuteName.write(gdc);
	gdc->write_int(seed);
	relicName.write(gdc);
	relicBonus.write(gdc);
	gdc->write_int(relicSeed);
	augmentName.write(gdc);
	gdc->write_int(unknown);
	gdc->write_int(augmentSeed);
	gdc->write_int(var1);
	gdc->write_int(stackCount);
}