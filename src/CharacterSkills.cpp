#include "pch.h"
#include "CharacterSkills.h"
#include "Vector.h"
#include "Skill.h"
#include "block.h"
#include "GDCFile.h"
#include "ItemSkill.h"

#include <cstdint>

void CharacterSkills::read(GDCFile *gdc)
{
	block b;

	if (gdc->read_block_start(&b) != 8)
		throw e;

	if (gdc->read_int() != 5) // version
		throw e;

	skills.read(gdc);
	masteriesAllowed = gdc->read_int();
	skillReclamationPointsUsed = gdc->read_int();
	devotionReclamationPointsUsed = gdc->read_int();
	itemSkills.read(gdc);

	gdc->read_block_end(&b);
}

void CharacterSkills::write(GDCFile *gdc)
{
	block b;

	gdc->write_block_start(&b, 8);
	gdc->write_int(5); // version

	skills.write(gdc);
	gdc->write_int(masteriesAllowed);
	gdc->write_int(skillReclamationPointsUsed);
	gdc->write_int(devotionReclamationPointsUsed);
	itemSkills.write(gdc);

	gdc->write_block_end(&b);
}