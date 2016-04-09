#pragma once
#include <cstdint>
#include "Vector.h"
#include "Skill.h"
#include "ItemSkill.h"

class GDCFile;

class CharacterSkills
{
public:
	Vector<Skill> skills;
	Vector<ItemSkill> itemSkills;
	uint32_t masteriesAllowed;
	uint32_t skillReclamationPointsUsed;
	uint32_t devotionReclamationPointsUsed;

	void read(GDCFile *);
	void write(GDCFile *);
};
