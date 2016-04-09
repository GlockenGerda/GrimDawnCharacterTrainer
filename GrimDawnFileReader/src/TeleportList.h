#pragma once
#include "Vector.h"
#include "UID.h"

class GDCFile;

class TeleportList
{
public:
	Vector<UID> uids[3];

	void read(GDCFile *);
	void write(GDCFile *);
};