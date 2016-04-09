#pragma once

class Item
{
public:
	String baseName;
	String prefixName;
	String suffixName;
	String modifierName;
	String transmuteName;
	String relicName;
	String relicBonus;
	String augmentName;
	uint32_t stackCount;
	uint32_t seed;
	uint32_t relicSeed;
	uint32_t unknown;
	uint32_t augmentSeed;
	uint32_t var1;

	void read(GDCFile *);
	void write(GDCFile *);
};