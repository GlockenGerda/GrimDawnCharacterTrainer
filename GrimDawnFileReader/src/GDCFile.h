#pragma once
#include <cstdint>
#include "UID.h"
#include "CharacterInfo.h"
#include "CharacterBio.h"
#include "Header.h"
#include "Inventory.h"
#include "CharacterStash.h"
#include "RespawnList.h"
#include "TeleportList.h"
#include "MarkerList.h"
#include "ShrineList.h"
#include "CharacterSkills.h"
#include "LoreNotes.h"
#include "FactionPack.h"
#include "UISettings.h"
#include "TutorialPages.h"
#include "PlayStats.h"
using namespace System;
using namespace System::IO;
using namespace System;
namespace GDFR {
	ref struct block;
	union { float f; int i; } u;

	public ref class GDCFile
	{
	private:
		FileStream^ fs;
		BinaryWriter^ bw;
		BinaryReader^ br;
		uint32_t key;
		array<uint32_t>^ table = gcnew array<uint32_t>(256);

	public:
		Header^ hdr;
		UID^ id;
		CharacterInfo^ info;
		CharacterBio^ bio;
		Inventory^ inv;
		CharacterStash^ stash;
		RespawnList^ respawns;
		TeleportList^ teleports;
		MarkerList^ markers;
		ShrineList^ shrines;
		CharacterSkills^ skills;
		LoreNotes^ notes;
		FactionPack^ factions;
		UISettings^ ui;
		TutorialPages^ tutorials;
		PlayStats^ stats;

		void read(const char *);
		void write(String^);

	private:
		void read_key();
		uint32_t next_int();
		void update_key(void * ptr, uint32_t len);
	public:
		uint32_t read_int();
		uint16_t read_short();
		uint8_t read_byte();
		float read_float();
		uint32_t read_block_start(block ^b);
		void read_block_end(block ^b);
		void write_int(uint32_t val);
		void write_short(uint16_t val);
		void write_byte(uint8_t val);
		void write_float(float val);
		void write_block_start(block ^b, uint32_t n);
		void write_block_end(block ^b);
	};
}