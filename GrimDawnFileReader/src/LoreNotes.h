#pragma once

#include "Vector.h"
#include "String.h"
class GDCFile;

class LoreNotes
{
public:
	Vector<String> names;

	void read(GDCFile *);
	void write(GDCFile *);
};