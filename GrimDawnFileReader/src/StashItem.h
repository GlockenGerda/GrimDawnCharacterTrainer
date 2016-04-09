#pragma once
#include "Item.h"
namespace GDFR {
	ref class GDCFile;

	public ref class StashItem : public Item
	{
	public:
		float x;
		float y;

		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}
