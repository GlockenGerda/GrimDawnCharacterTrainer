#pragma once

#include <cstdint>

class GDCFile;

class FactionData
{
public:
	float value;
	float positiveBoost;
	float negativeBoost;
	uint8_t modified;
	uint8_t unlocked;

	void read(GDCFile *);
	void write(GDCFile *);
};