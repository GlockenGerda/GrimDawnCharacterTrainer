#pragma once
#include "Item.h"
class GDCFile;

class StashItem : public Item
{
public:
	float x;
	float y;

	void read(GDCFile *);
	void write(GDCFile *);
};
