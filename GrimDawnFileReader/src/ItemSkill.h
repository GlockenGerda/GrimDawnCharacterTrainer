#pragma once

#include "String.h"
namespace GDFR {
	ref class GDCFile;

	public ref class ItemSkill
	{
	public:

		String name;
		String autoCastSkill;
		String autoCastController;

		void read(GDCFile ^);
		void write(GDCFile ^);
	};
}