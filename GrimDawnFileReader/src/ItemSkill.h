#pragma once

#include "String.h"
class GDCFile;

class ItemSkill
{
public:

	String name;
	String autoCastSkill;
	String autoCastController;

	void read(GDCFile *);
	void write(GDCFile *);
};