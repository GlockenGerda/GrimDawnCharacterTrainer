#pragma once

class GDCFile
{
private:
	FILE *fp;
	uint32_t key;
	uint32_t table[256];

public:
	Header hdr;
	UID id;
	CharacterInfo info;
	CharacterBio bio;
	Inventory inv;
	CharacterStash stash;
	RespawnList respawns;
	TeleportList teleports;
	MarkerList markers;
	ShrineList shrines;
	CharacterSkills skills;
	LoreNotes notes;
	FactionPack factions;
	UISettings ui;
	TutorialPages tutorials;
	PlayStats stats;

	void read(const char *);
	void write(const char *);

private:
	void read_key();
	uint32_t next_int();
	void update_key(void * ptr, uint32_t len);
public:
	uint32_t read_int();
	uint16_t read_short();
	uint8_t read_byte();
	float read_float();
	uint32_t read_block_start(block * b);
	void read_block_end(block *b);
	void write_int(uint32_t val);
	void write_short(uint16_t val);
	void write_byte(uint8_t val);
	void write_float(float val);
	void write_block_start(block *b, uint32_t n);
	void write_block_end(block *b);
};