#pragma once
#include "Vector.h"
#include "UID.h"

class GDCFile;

class RespawnList
{
public:
	Vector<UID> uids[3];
	UID spawn[3];

	void read(GDCFile *);
	void write(GDCFile *);
};
