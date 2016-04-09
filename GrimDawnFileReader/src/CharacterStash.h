#pragma once

class CharacterStash
{
public:
	Vector<StashItem> items;
	uint32_t width;
	uint32_t height;

	void read(GDCFile *);
	void write(GDCFile *);
};