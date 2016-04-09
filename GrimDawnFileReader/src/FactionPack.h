#pragma once
class FactionPack
{
public:
	Vector<FactionData> factions;
	uint32_t faction;

	void read(GDCFile *);
	void write(GDCFile *);
};