#pragma once

#include "Vector.h"
#include "String.h"
namespace GDFR {
	class GDCFile;

	public class LoreNotes
	{
	public:
		Vector<String> names;

		void read(GDCFile *);
		void write(GDCFile *);
	};
}