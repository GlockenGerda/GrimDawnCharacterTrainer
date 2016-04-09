#pragma once

class TeleportList
{
public:
	Vector<UID> uids[3];

	void read(GDCFile *);
	void write(GDCFile *);
};