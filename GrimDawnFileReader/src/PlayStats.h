#pragma once
#include "String.h"
#include <cstdint>

namespace GDFR {
	ref class GDCFile;

	public ref class PlayStats
	{
	public:
		array<String^ >^ greatestMonsterKilledName = gcnew array<String^ >(3);
		array<String^ >^ lastMonsterHit = gcnew array<String^ >(3);
		array<String^ >^ lastMonsterHitBy = gcnew array<String^ >(3);
		array<float> ^ greatestMonsterKilledLevel = gcnew array<float>(3);
		array<float> ^ greatestMonsterKilledLifeAndMana = gcnew array<float>(3);
		array<uint32_t>^ bossKills = gcnew array <uint32_t>(3);
		uint32_t playTime;
		uint32_t deaths;
		uint32_t kills;
		uint32_t experienceFromKills;
		uint32_t healthPotionsUsed;
		uint32_t manaPotionsUsed;
		uint32_t maxLevel;
		uint32_t hitsReceived;
		uint32_t hitsInflicted;
		uint32_t criticalHitsInflicted;
		uint32_t criticalHitsReceived;
		uint32_t championKills;
		uint32_t heroKills;
		uint32_t itemsCrafted;
		uint32_t relicsCrafted;
		uint32_t transcendentRelicsCrafted;
		uint32_t mythicalRelicsCrafted;
		uint32_t shrinesRestored;
		uint32_t oneShotChestsOpened;
		uint32_t loreNotesCollected;
		float greatestDamageInflicted;
		float lastHit;
		float lastHitBy;
		float greatestDamageReceived;
		uint32_t unknown1;
		uint32_t unknown2;

		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}