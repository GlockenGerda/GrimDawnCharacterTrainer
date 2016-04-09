#include "pch.h"
#include "ItemSkill.h"
#include "GDCFile.h"

void ItemSkill::read(GDCFile *gdc)
{
	name.read(gdc);
	autoCastSkill.read(gdc);
	autoCastController.read(gdc);
}

void ItemSkill::write(GDCFile *gdc)
{
	name.write(gdc);
	autoCastSkill.write(gdc);
	autoCastController.write(gdc);
}