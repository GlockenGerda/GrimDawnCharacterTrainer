#pragma once

#include "Vector.h"
#include "UID.h"

class GDCFile;

class ShrineList
{
public:
	Vector<UID> uids[6];

	void read(GDCFile *);
	void write(GDCFile *);
};
