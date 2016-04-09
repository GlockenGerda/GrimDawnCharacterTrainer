#pragma once

#include "Vector.h"

class GDCFile;

class TutorialPages
{
public:
	Vector<size_t> pages;

	void read(GDCFile *);
	void write(GDCFile *);
};