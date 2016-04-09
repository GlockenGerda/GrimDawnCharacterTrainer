#pragma once

#include "String.h"
namespace GDFR {
	class GDCFile;

	public class ItemSkill
	{
	public:

		String name;
		String autoCastSkill;
		String autoCastController;

		void read(GDCFile *);
		void write(GDCFile *);
	};
}