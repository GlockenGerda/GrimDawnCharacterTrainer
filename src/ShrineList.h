#pragma once

class ShrineList
{
public:
	Vector<UID> uids[6];

	void read(GDCFile *);
	void write(GDCFile *);
};
