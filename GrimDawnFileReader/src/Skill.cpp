#include "pch.h"
#include "Skill.h"
#include "GDCFile.h"

namespace GDFR {
	void Skill::read(GDCFile ^gdc)
	{
		name.read(gdc);
		level = gdc->read_int();
		enabled = gdc->read_byte();
		devotionLevel = gdc->read_int();
		experience = gdc->read_int();
		active = gdc->read_int();
		unknown1 = gdc->read_byte();
		unknown2 = gdc->read_byte();
		autoCastSkill.read(gdc);
		autoCastController.read(gdc);
	}

	void Skill::write(GDCFile ^gdc)
	{
		name.write(gdc);
		gdc->write_int(level);
		gdc->write_byte(enabled);
		gdc->write_int(devotionLevel);
		gdc->write_int(experience);
		gdc->write_int(active);
		gdc->write_byte(unknown1);
		gdc->write_byte(unknown2);
		autoCastSkill.write(gdc);
		autoCastController.write(gdc);
	}
}