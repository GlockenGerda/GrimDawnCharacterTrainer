#pragma once

class Header
{
public:
	WString name;
	String tag;
	uint32_t level;
	uint8_t sex;
	uint8_t hardcore;

	void read(GDCFile *);
	void write(GDCFile *);
};