#include "pch.h"
#include "CharacterBio.h"
#include "GDCFile.h"
#include "block.h"
#include <cstdint>

void CharacterBio::read(GDCFile *gdc)
{
	block b;

	if (gdc->read_block_start(&b) != 2)
		throw e;

	if (gdc->read_int() != 8) // version
		throw e;

	level = gdc->read_int();
	experience = gdc->read_int();
	modifierPoints = gdc->read_int();
	skillPoints = gdc->read_int();
	devotionPoints = gdc->read_int();
	totalDevotion = gdc->read_int();
	physique = gdc->read_float();
	cunning = gdc->read_float();
	spirit = gdc->read_float();
	health = gdc->read_float();
	energy = gdc->read_float();

	gdc->read_block_end(&b);
}

void CharacterBio::write(GDCFile *gdc)
{
	block b;

	gdc->write_block_start(&b, 2);
	gdc->write_int(8); // version

	gdc->write_int(level);
	gdc->write_int(experience);
	gdc->write_int(modifierPoints);
	gdc->write_int(skillPoints);
	gdc->write_int(devotionPoints);
	gdc->write_int(totalDevotion);
	gdc->write_float(physique);
	gdc->write_float(cunning);
	gdc->write_float(spirit);
	gdc->write_float(health);
	gdc->write_float(energy);

	gdc->write_block_end(&b);
}