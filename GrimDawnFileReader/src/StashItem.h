#pragma once
#include "Item.h"
namespace GDFR {
	class GDCFile;

	public class StashItem : public Item
	{
	public:
		float x;
		float y;

		void read(GDCFile *);
		void write(GDCFile *);
	};
}
