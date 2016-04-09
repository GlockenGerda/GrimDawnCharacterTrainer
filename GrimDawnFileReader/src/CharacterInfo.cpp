#include "CharacterInfo.h"
#include "block.h"
#include "GDCFile.h"

void CharacterInfo::read(GDCFile *gdc)
{
	block b;

	if (gdc->read_block_start(&b) != 1)
		throw e;

	if (gdc->read_int() != 3) // version
		throw e;

	isInMainQuest = gdc->read_byte();
	hasBeenInGame = gdc->read_byte();
	difficulty = gdc->read_byte();
	greatestDifficulty = gdc->read_byte();
	money = gdc->read_int();
	compassState = gdc->read_byte();
	lootMode = gdc->read_int();
	skillWindowShowHelp = gdc->read_byte();
	alternateConfig = gdc->read_byte();
	alternateConfigEnabled = gdc->read_byte();
	texture.read(gdc);

	gdc->read_block_end(&b);
}

void CharacterInfo::write(GDCFile *gdc)
{
	block b;

	gdc->write_block_start(&b, 1);
	gdc->write_int(3); //version

	gdc->write_byte(isInMainQuest);
	gdc->write_byte(hasBeenInGame);
	gdc->write_byte(difficulty);
	gdc->write_byte(greatestDifficulty);
	gdc->write_int(money);
	gdc->write_byte(compassState);
	gdc->write_int(lootMode);
	gdc->write_byte(skillWindowShowHelp);
	gdc->write_byte(alternateConfig);
	gdc->write_byte(alternateConfigEnabled);
	texture.write(gdc);

	gdc->write_block_end(&b);
}