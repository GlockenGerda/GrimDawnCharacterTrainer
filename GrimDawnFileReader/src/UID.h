#pragma once
class UID
{
public:
	uint8_t id[16];

	void read(GDCFile *);
	void write(GDCFile *);
};