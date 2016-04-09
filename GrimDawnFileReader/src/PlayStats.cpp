#include "pch.h"
#include "PlayStats.h"
#include "GDCFile.h"
#include "String.h"

#include "block.h"
#include <cstdint>

void PlayStats::read(GDCFile *gdc)
{
	block b;

	if (gdc->read_block_start(&b) != 16)
		throw e;

	if (gdc->read_int() != 7) // version
		throw e;

	playTime = gdc->read_int();
	deaths = gdc->read_int();
	kills = gdc->read_int();
	experienceFromKills = gdc->read_int();
	healthPotionsUsed = gdc->read_int();
	manaPotionsUsed = gdc->read_int();
	maxLevel = gdc->read_int();
	hitsReceived = gdc->read_int();
	hitsInflicted = gdc->read_int();
	criticalHitsInflicted = gdc->read_int();
	criticalHitsReceived = gdc->read_int();
	greatestDamageInflicted = gdc->read_float();

	for (unsigned i = 0; i < 3; i++)
	{
		greatestMonsterKilledName[i].read(gdc);
		greatestMonsterKilledLevel[i] = gdc->read_int();
		greatestMonsterKilledLifeAndMana[i] = gdc->read_int();
		lastMonsterHit[i].read(gdc);
		lastMonsterHitBy[i].read(gdc);
	}

	championKills = gdc->read_int();
	lastHit = gdc->read_float();
	lastHitBy = gdc->read_float();
	greatestDamageReceived = gdc->read_float();
	heroKills = gdc->read_int();
	itemsCrafted = gdc->read_int();
	relicsCrafted = gdc->read_int();
	transcendentRelicsCrafted = gdc->read_int();
	mythicalRelicsCrafted = gdc->read_int();
	shrinesRestored = gdc->read_int();
	oneShotChestsOpened = gdc->read_int();
	loreNotesCollected = gdc->read_int();

	for (unsigned i = 0; i < 3; i++)
	{
		bossKills[i] = gdc->read_int();
	}

	unknown1 = gdc->read_int();
	unknown2 = gdc->read_int();

	gdc->read_block_end(&b);
}

void PlayStats::write(GDCFile *gdc)
{
	block b;

	gdc->write_block_start(&b, 16);
	gdc->write_int(7); // version

	gdc->write_int(playTime);
	gdc->write_int(deaths);
	gdc->write_int(kills);
	gdc->write_int(experienceFromKills);
	gdc->write_int(healthPotionsUsed);
	gdc->write_int(manaPotionsUsed);
	gdc->write_int(maxLevel);
	gdc->write_int(hitsReceived);
	gdc->write_int(hitsInflicted);
	gdc->write_int(criticalHitsInflicted);
	gdc->write_int(criticalHitsReceived);
	gdc->write_float(greatestDamageInflicted);

	for (unsigned i = 0; i < 3; i++)
	{
		greatestMonsterKilledName[i].write(gdc);
		gdc->write_int(greatestMonsterKilledLevel[i]);
		gdc->write_int(greatestMonsterKilledLifeAndMana[i]);
		lastMonsterHit[i].write(gdc);
		lastMonsterHitBy[i].write(gdc);
	}

	gdc->write_int(championKills);
	gdc->write_float(lastHit);
	gdc->write_float(lastHitBy);
	gdc->write_float(greatestDamageReceived);
	gdc->write_int(heroKills);
	gdc->write_int(itemsCrafted);
	gdc->write_int(relicsCrafted);
	gdc->write_int(transcendentRelicsCrafted);
	gdc->write_int(mythicalRelicsCrafted);
	gdc->write_int(shrinesRestored);
	gdc->write_int(oneShotChestsOpened);
	gdc->write_int(loreNotesCollected);

	for (unsigned i = 0; i < 3; i++)
	{
		gdc->write_int(bossKills[i]);
	}

	gdc->write_int(unknown1);
	gdc->write_int(unknown2);

	gdc->write_block_end(&b);
}